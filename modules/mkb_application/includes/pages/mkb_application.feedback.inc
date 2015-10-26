<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Generates content for group_evaluation_page template.
 *
 * @param $gid
 *   Evaluation configuration node id.
 * @return template
 *   The template group_evaluation_page_template is called with $content.
 */

function mkb_feedback_application_function($gid){
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
//dpm($eval_confs);
  $eval_confs = array();
  $eval_confs['35265'] = node_load(35265);
//dpm($eval_confs);
  // Build content
  $options = array('acronym' => TRUE, 'eval_type' => TRUE, 'eval_author' => FALSE, 'topic' => FALSE);
  $content = mkb_eval_get_evaluation_view(array($gid => $group_node), $eval_confs, $options);

  $variables['group'] = $group;
  $variables['content'] = $content;
  return theme('feedback_application_template', $variables);
}

