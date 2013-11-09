<?php
/**
 * @file
 * ical_feed_importer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ical_feed_importer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ical_feed_importer_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Use this content type for any event that might be of interest to Drupal Ireland members (but is not already on the Drupal Ireland Groups feed)'),
      'has_title' => '1',
      'title_label' => t('Name of Event'),
      'help' => '',
    ),
  );
  return $items;
}
