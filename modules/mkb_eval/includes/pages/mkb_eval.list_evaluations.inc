<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_summary_page template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $eid
 *   Evaluation configuration node id.
 * @param $fid
 *   Evaluation filter nid.
 * @param $by_topic
 *   TRUE or FALSE.
 * @return template
 *   The template list_evaluations_template is called with $content.
 */
function mkb_eval_list_evaluations($cid, $eid, $fid, $by_topic){
  // Load eval conf
  $eval_confs = entity_load('node', array($eid));

  // Get groups selected for call stage
  $groups = mkb_eval_get_filtered_groups($cid, $fid, $eid);

  // Get evaluations by options
  $topic = ($by_topic==1) ? TRUE : FALSE;
  $options = array('acronym' => TRUE, 'eval_type' => FALSE, 'eval_author' => TRUE, 'topic' => $topic);
  $rows = mkb_eval_get_evaluation_view($groups, $eval_confs, $options);

  $variables['topic'] = $topic;
  $variables['rows'] = $rows;
  return theme('list_evaluations_template', $variables);
}


