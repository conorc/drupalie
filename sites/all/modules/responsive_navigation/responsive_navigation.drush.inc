<?php

/**
 * @file
 * Drush integration for responsive-nav.js.
 */

module_load_include('inc', 'responsive_navigation', 'responsive_navigation_common');

/**
 * Implements hook_drush_command().
 */
function responsive_navigation_drush_command() {
  $items = array();

  // install plugin
  $items['rnjs-plugin'] = array(
    'callback' => 'drush_rnjs_plugin',
    'description' => dt("Downloads the responsive-nav.js plugin."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the responsive-nav.js plugin. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('rnjsplugin'),
  );

  // remove plugin
  $items['rm-rnjs-plugin'] = array(
    'callback' => 'drush_rmrnjs_plugin',
    'description' => dt("Deletes the responsive-nav.js plugin."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to delete the responsive-nav.js plugin. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('rmrnjsplugin'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function responsive_navigation_drush_help($section) {
  switch ($section) {
    case 'drush:rnjs-plugin':
      return dt("Downloads the responsive-nav.js plugin, default location is sites/all/libraries.");
  }
}

/**
 * Command to download the responsive-nav.js plugin. Use drush --verbose for extra log detail.
 */
function drush_rnjs_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  $olddir = getcwd();
  chdir($path);

  if ($filepath = drush_download_file(RNJS_DOWNLOAD_URI)) {
    $filename = basename($filepath);
    $dirname = 'responsive-nav.js-' . basename($filepath, '.zip'); // Github auto file naming

    if (is_dir($dirname) || is_dir('responsive_navigation')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('responsive_navigation', TRUE);
      drush_log(dt('An existing responsive-nav.js plugin was deleted from @path', array('@path' => $path)), 'notice');
    }

    drush_tarball_extract($filename);

    if ($dirname != 'responsive_navigation') {
      drush_move_dir($dirname, 'responsive_navigation', TRUE);
      $dirname = 'responsive_navigation';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('responsive-nav.js plugin has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the responsive-nav.js plugin to @path', array('@path' => $path)), 'error');
  }

  chdir($olddir);
}


/**
 * Command to delete the responsive-nav.js plugin. Use drush --verbose for extra log detail.
 */
function drush_rmrnjs_plugin() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  if (!is_dir($path)) {
    drush_log(dt('Directory @path was not found.', array('@path' => $path)), 'error');
  }

  $olddir = getcwd();
  chdir($path);

  if (is_dir('responsive_navigation')) {
    drush_log(dt('The responsive_navigation directory was found at @path. Attempting to delete it.', array('@path' => $path)), 'notice');
    
    if (drush_delete_dir('responsive_navigation', TRUE)) {
      drush_log(dt('The responsive_navigation directory has been deleted in @path', array('@path' => $path)), 'success');
    }
    else {
      drush_log(dt('Drush was unable to delete the responsive_navigation directory in @path', array('@path' => $path)), 'error');
    }
  }
  else {
    drush_log(dt('Drush was unable to find the responsive_navigation directory in @path', array('@path' => $path)), 'error');
  }

  chdir($olddir);
}
