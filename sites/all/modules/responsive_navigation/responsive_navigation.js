/**
 * @file
 * Applies responsive-nav.js settings.
 */
(function ($) {

  Drupal.responsive_navigation = Drupal.responsive_navigation || {};
  Drupal.behaviors.responsive_navigation = {
    attach: function (context, settings) {
      settings.responsive_navigation = settings.responsive_navigation || {};
      Drupal.responsive_navigation.blocks = Drupal.responsive_navigation.blocks || {};
      if (!$("#nav").size() || settings.responsive_navigation.total == 0) return; // end if no #nav is found or no blocks enabled.
      $.each(settings.responsive_navigation.blocks, function(key, value) {
        /* Method for handling multiple navs in the future */
        // key = key.split('_').join('-'); // convert _ to -
        // Drupal.responsive_navigation.blocks[key] = responsiveNav("#" + key, { // Selector: The ID of the wrapper
        Drupal.responsive_navigation.blocks['navigation'] = responsiveNav("#nav", { // Selector: The ID of the wrapper
          animate: value['responsive_navigation_animate'], // Boolean: Use CSS3 transitions, true or false
          transition: value['responsive_navigation_transition'], // Integer: Speed of the transition, in milliseconds
          label: value['responsive_navigation_label'], // String: Label for the navigation toggle
          insert: value['responsive_navigation_insert'], // String: Insert the toggle before or after the navigation
          openPos: value['responsive_navigation_openpos'], // String: Position of the opened nav, relative or static
          jsClass: value['responsive_navigation_jsclass'], // String: 'JS enabled' class which is added to <html> el
        });
      });
    },
  };

}(jQuery));
