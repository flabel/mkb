<?php
/**
 * @file
 * mkb_call_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mkb_call_admin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mkb_call_admin_views_api($module = NULL, $api = NULL) {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_call_admin'),
    'template path' => drupal_get_path('module', 'mkb_call_admin') . '/theme',
  );
}

/**
 * Implements hook_node_info().
 */
function mkb_call_admin_node_info() {
  $items = array(
    'call_funder_page' => array(
      'name' => t('Call-funder-page'),
      'base' => 'node_content',
      'description' => t('Description of the funding agencies in the call.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'call_main_page' => array(
      'name' => t('Call-main-page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'call_topic' => array(
      'name' => t('Call topic'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Topic'),
      'help' => '',
    ),
    'funding_scheme' => array(
      'name' => t('Funding scheme'),
      'base' => 'node_content',
      'description' => t('Defines which parts of the basic call budget funding scheme are present in the partner budget edit form '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project_page' => array(
      'name' => t('Project_page'),
      'base' => 'node_content',
      'description' => t('Pages only visible in Intra-net'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
