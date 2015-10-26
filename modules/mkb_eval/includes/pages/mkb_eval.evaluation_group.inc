<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for group_evaluation_page template.
 *
 * @param $gid
 *   Evaluation configuration node id.
 * @return template
 *   The template group_evaluation_page_template is called with $content.
 */
function evaluation_group_page_function($gid){
  $variables = array();
  // Info from group
  $group['gid'] = $gid;

  $group_node = node_load($gid);
  $app_id = mkb_eval_get_aid($gid, 'application_project_info');
  if($app_id){
    $group['acronym'] = mkb_eval_get_acronym($app_id);
    $group['title'] = mkb_eval_get_title($app_id);
  }
  else{
    $group['acronym'] = '';
    $group['title'] = '';
  }

  // Load evaluation configuration nodes to be shown
  $eval_confs = node_load_multiple(array(), array('type' => 'evaluation_conf'));
  // Build content
  $options = array('acronym' => FALSE, 'eval_type' => FALSE, 'eval_author' => TRUE, 'topic' => FALSE);
  $content = mkb_eval_get_evaluation_view(array($gid => $group_node), $eval_confs, $options);

  $variables['group'] = $group;
  $variables['content'] = $content;
  return theme('evaluation_group_page_template', $variables);
}