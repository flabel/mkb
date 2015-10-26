<?php
/**
 * @file
 * mkb_application.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mkb_application_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mkb_application_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_application'),
    'template path' => drupal_get_path('module', 'mkb_application') . '/views',
  );
}

/**
 * Implements hook_node_info().
 */
function mkb_application_node_info() {
  $items = array(
    'application_partner_budget' => array(
      'name' => t('Application-partner-budget'),
      'base' => 'node_content',
      'description' => t('Project budget content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'application_partner_info' => array(
      'name' => t('Application-partner-info'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Partner'),
      'help' => t('In "Partner" please enter the name of the participating unit.'),
    ),
    'application_project_info' => array(
      'name' => t('Application-project-info'),
      'base' => 'node_content',
      'description' => t('Project information form'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Title of the project (max. 200 characters incl. spaces and punctuation)'),
    ),
  );
  return $items;
}
