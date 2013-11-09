<?php

/**
 * @file
 * Responsive Navigation Administration UI
 * Implements the configuration screen.
 */

module_load_include('inc', 'responsive_navigation', 'responsive_navigation_common');

/**
 * Settings form as implemented by hook_menu.
 */
function responsive_navigation_admin_settings($form, &$form_state) {
  $form['responsive_navigation_number'] = array(
    '#type' => 'select',
    '#description' => t('<b>NOTE: responsive-nav.js only supports one navigation menu. This setting will be increased when responsive-nav.js supports more than one.</b><br />Enter the total number of independent Responsive Navigation menu blocks you want. Enter a number between 0 and 1. If you set this to 0, you will have no blocks created but you can still use the !rnjs theme functions and Javascript/CSS directly in your theme.', array('!rnjs' => l(RNJS_MAIN_JS, RNJS_SITE_URL))),
    '#default_value' => variable_get('responsive_navigation_number', '1'),
    '#options' => drupal_map_assoc(range(0, 1)),
    '#size' => 1,
  );

  // Custom validation to make sure the user is entering numbers.
  $form['#validate'][] = 'responsive_navigation_settings_validate';

  return system_settings_form($form);
}

/**
 * Custom validation for the settings form.
 */
function responsive_navigation_settings_validate($form, &$form_state) {
  $number = $form_state['values']['responsive_navigation_number'];
  // Check to make sure it is a number and that is a maximum of 2 digits.
  if (!is_numeric($number) || strlen($number) > 2) {
    form_set_error('responsive_navigation_number', t('You must enter a number from 0 to 99.'));
  }
}
