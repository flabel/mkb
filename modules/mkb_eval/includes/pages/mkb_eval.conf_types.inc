<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_experts_page_template template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Filter node nid.
 * @return template
 *   The template evaluation_conf_types_template is called with $variables.
 */
function mkb_eval_conf_types($cid, $fid){
  $variables = array();

  // Get call stage
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $stage = $call_wrapper->field_current_stage->value();

  // Get term ID for 'Expert' in evaluation type vocabulary
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
  ->entityCondition('bundle', array('evaluation_type'))
  ->propertyCondition('name', 'Expert')
  ->propertyOrderBy('weight');
  $result = $query->execute();
  $tids = array_keys($result['taxonomy_term']);
  $tid = isset($tids[0]) ? $tids[0] : 0;

  // Get all evluation configuration node that has is refering call and has correct stage
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation_conf')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_call_id', 'target_id', $cid, '=')
    ->fieldCondition('field_call_stage', 'value', $stage, '=')
    ->fieldCondition('field_eval_conf_type', 'target_id', $tid, '=');

  $result = $query->execute();
  $nodes = array();
  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);
  }

  $header = array();
  $rows = array();
  foreach ($nodes as $node){
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $rows[] = array(l($node_wrapper->label(), 'eval/application_experts/' . $cid . '/' .
        $node_wrapper->getIdentifier() . '/' . $fid));
  }

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('evaluation_conf_types_template', $variables);
}