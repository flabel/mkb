<?php
/**
 * @file
 * mkb_pm.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mkb_pm_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mkb_pm_views_api($module = NULL, $api = NULL) {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_pm'),
    'template path' => drupal_get_path('module', 'mkb_pm') . '/theme',
  );
}

/**
 * Implements hook_node_info().
 */
function mkb_pm_node_info() {
  $items = array(
    'application_project_publish' => array(
      'name' => t('Application project publish'),
      'base' => 'node_content',
      'description' => t('Used to generate Mid-term and full rapport of proposals'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'application_publish_conf' => array(
      'name' => t('Application publish configuration'),
      'base' => 'node_content',
      'description' => t('Configure publishing options for different rapports'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
