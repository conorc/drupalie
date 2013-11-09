<?php
/**
 * @file
 * context_place_secondary_menu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function context_place_secondary_menu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
