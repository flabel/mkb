<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.custom_theme');

/**
 * Application selection form submit.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 * @return $???
 *   ???.
 */
function mkb_eval_application_selection_topic_form_submit($form, $form_state){
  $call = node_load($form_state['build_info']['args'][0]);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $call_wrapper->field_current_stage->value();
  $field_name = 'field_app_selected_' . $current_stage;

  foreach ($form_state['values']['checkboxes'] as $id => $checkbox){
    $node = node_load($id);
    if(isset($checkbox) && $id == $checkbox){
      $node->{$field_name}['und'][0]['value'] = 1;
      node_save($node);
    }
    else{
      $node->{$field_name}['und'][0]['value'] = 0;
      node_save($node);
    }
  }
}

function mkb_eval_application_selection_topic_form_validate($form, $form_state){
}

/**
 * Generates form for A pplication topic selection.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $eid
 *   Evaluation configuration node id.
 * @param $fid
 *   Evaluation filter node id.
 * @param $tid
 *   Call topic nid.
 * @return form.
 *   Application selection form.
 */
function mkb_eval_application_selection_topic_form($form, &$form_state, $cid, $eid, $fid, $tid){
  return mkb_eval_selection_get_form($form, $form_state, $cid, $eid, $fid, $tid);
}

