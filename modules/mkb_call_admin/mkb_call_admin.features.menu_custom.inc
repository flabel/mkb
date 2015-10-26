<?php
/**
 * @file
 * mkb_call_admin.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function mkb_call_admin_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-call-admin.
  $menus['menu-call-admin'] = array(
    'menu_name' => 'menu-call-admin',
    'title' => 'Call admin',
    'description' => 'Call administration menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Call admin');
  t('Call administration menu');


  return $menus;
}
