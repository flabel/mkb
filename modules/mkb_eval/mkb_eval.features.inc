<?php
/**
 * @file
 * mkb_eval.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mkb_eval_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mkb_eval_views_api($module = NULL, $api = NULL) {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_eval'),
    'template path' => drupal_get_path('module', 'mkb_eval') . '/theme',
  );
}

/**
 * Implements hook_node_info().
 */
function mkb_eval_node_info() {
  $items = array(
    'eval_expert_application' => array(
      'name' => t('New evaluation expert application'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'evaluation' => array(
      'name' => t('Evaluation'),
      'base' => 'node_content',
      'description' => t('Evaluation types configured by evaluation_conf'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'evaluation_conf' => array(
      'name' => t('Evaluation configuration'),
      'base' => 'node_content',
      'description' => t('Configuration node for Evaluations'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'evaluation_conflict' => array(
      'name' => t('Declaration of no conflict'),
      'base' => 'node_content',
      'description' => t('One to One acknowledgement of any conflict between the "Expert evaluator" and the group applicants'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'evaluation_filter' => array(
      'name' => t('Evaluation filter'),
      'base' => 'node_content',
      'description' => t('Define filters for Evaluation views'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'evaluation_view' => array(
      'name' => t('Evaluation view'),
      'base' => 'node_content',
      'description' => t('Define which fiels should be visible in evaluation views'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'expert_evaluators' => array(
      'name' => t('Expert evaluators'),
      'base' => 'node_content',
      'description' => t('Evaluators for stage 2'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
