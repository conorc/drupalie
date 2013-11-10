/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {


// To understand behaviors, see https://drupal.org/node/756722#behaviors
Drupal.behaviors.DrupalIeTheme = {
  attach: function(context, settings) {

    // Make a menu button for the secondary menu and make it clickable to show/hide.
    var $secondary_menu = $('#block-menu-menu-secondary-menu ul.menu');
    var $secondary_menu_button_markup = '<div class="menu-button menu-collapsed">menu</div>';
    $secondary_menu.before($secondary_menu_button_markup);
    var $secondary_menu_button = $('#block-menu-menu-secondary-menu div.menu-button');
    $secondary_menu.hide();
    $secondary_menu_button.click(function() {
      $secondary_menu.toggle();
      $(this).toggleClass('menu-collapsed').toggleClass('menu-expanded');
    });
  }
};


})(jQuery, Drupal, this, this.document);
