<?php

module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Set expert_selected to 1 and redirect back to view
 *
 * @param $nid
 *   eval_expert_application node id
 * @param $eval_conf_nid
 *   eval_conf node id
  */
function mkb_eval_select_expert_application($nid, $eval_conf_nid){
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);

  $expert_nids = $node_wrapper->field_expert_selected->value();
  if(!$expert_nids) $expert_nids = array();

  $key = -1;
  for($i=0; $i<count($expert_nids); $i++){
    if($expert_nids[$i] == $eval_conf_nid) $key = $i;
  }

  if($key === -1) $expert_nids[] = $eval_conf_nid;
  else unset($expert_nids[$key]);

  $node_wrapper->field_expert_selected->set($expert_nids);
  $node_wrapper->save();
  drupal_goto('expert-applications');
}