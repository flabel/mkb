<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_experts_page_template template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Filter node nid.
 * @param $stage
 *   Stage.
 * @return template
 *   The template list_conf_types_template is called with $variables.
 */
function mkb_eval_list_conf_types($cid, $fid, $stage){
  $variables = array();

  // Get call stage
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  //$stage = $call_wrapper->field_current_stage->value();

  // Get all evluation configuration node that has is refering call and has correct stage
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation_conf')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_call_id', 'target_id', $cid, '=')
    ->fieldCondition('field_call_stage', 'value', $stage, '=');

  $result = $query->execute();
  $nodes = array();
  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);
  }

  $call_topic = $call_wrapper->field_theme_funding->value();
  $call_topic_enabled = ($call_topic==1) ? TRUE : FALSE;
  if($call_topic_enabled){
    $header = array('Evaluation type', 'By topic', 'No topic');
    $rows = array();
    foreach ($nodes as $nid => $node){
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $rows[$nid][] = $node_wrapper->label();
      $rows[$nid][] = l('View', 'eval/list/evaluations/' . $cid . '/' . $node_wrapper->getIdentifier() .
          '/' . $fid . '/1');
      $rows[$nid][] = l('View', 'eval/list/evaluations/' . $cid . '/' . $node_wrapper->getIdentifier() .
          '/' . $fid . '/0');
    }
  }
  else{
    $header = array('Evaluation type');
    $rows = array();
    foreach ($nodes as $nid => $node){
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $rows[] = array(l($node_wrapper->label(), 'eval/list/evaluations/' . $cid . '/' . $node_wrapper->getIdentifier() .
          '/' . $fid . '/0'));
    }
  }

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('list_conf_types_template', $variables);
}
