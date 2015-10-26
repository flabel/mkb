<?php
/**
 * @file
 * mkb_groups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mkb_groups_ctools_plugin_api($module = NULL, $api = NULL) {
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
function mkb_groups_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_groups'),
    'template path' => drupal_get_path('module', 'mkb_groups') . '/theme',
  );
}

/**
 * Implements hook_node_info().
 */
function mkb_groups_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'group_docs' => array(
      'name' => t('Group documents'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'post' => array(
      'name' => t('Post'),
      'base' => 'node_content',
      'description' => t('Content that will belong to a single or multiple groups.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Fill in Title and Body and select the group this post is intended for.'),
    ),
  );
  return $items;
}
