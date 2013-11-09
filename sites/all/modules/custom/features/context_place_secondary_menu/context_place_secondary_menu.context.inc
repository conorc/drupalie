<?php
/**
 * @file
 * context_place_secondary_menu.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_place_secondary_menu_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'secondary_menu';
  $context->description = 'Places secondary menu';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~/admin' => '~/admin',
        '~/node/*/edit' => '~/node/*/edit',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-secondary-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary-menu',
          'region' => 'header',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Places secondary menu');
  $export['secondary_menu'] = $context;

  return $export;
}
