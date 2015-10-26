<?php
/**
 * @file
 * mkb_call_admin.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function mkb_call_admin_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu-menu-call-admin'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-call-admin',
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'module' => 'menu',
    'node_types' => array(),
    'pages' => '<?php if (function_exists(\'mkb_display_menu\')) return mkb_display_menu(\'menu-call-admin\'); else return false; ?>',
    'roles' => array(
      'administrator' => 3,
      'call administrator' => 8,
    ),
    'themes' => array(
      'adaptivetheme_subtheme' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme_subtheme',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'pixture_reloaded' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'pixture_reloaded',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  return $export;
}
