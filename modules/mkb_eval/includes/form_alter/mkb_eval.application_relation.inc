<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * hook_form_alter : $form_id == 'application_relation_node_form'
 */
function mkb_eval_application_relation_alter(&$form, &$form_state, $form_id){
  if(is_numeric(arg(3))) $cid = arg(3);
  if(is_numeric(arg(4))) $fid = arg(4);
  if(is_numeric(arg(5))) $gid_1 = arg(5);
  if(is_numeric(arg(6))) $gid_2 = arg(6);

  if(isset($cid) && isset($fid) && isset($gid_1) && isset($gid_2)){
    // Load filtered groups
    $groups = mkb_eval_get_filtered_groups($cid, $fid);

    // Add acronym to options
    $options = array();
    foreach ($groups as $gid => $group){
      $options[$gid] = mkb_eval_get_acronym($group->applications['application_project_info']);
    }

    $form['og_group_ref'][LANGUAGE_NONE]['#options'] = $options;
    
    // Set Call id and hide form element
    $form['field_call_id'][LANGUAGE_NONE]['#default_value'][0] = $cid;
    $form['field_call_id'][LANGUAGE_NONE]['#access'] = FALSE;
    
    // Hide Proposal 1 and 2 form elements
    $form['field_rel_proposal_1'][LANGUAGE_NONE]['#access'] = FALSE;
    $form['field_rel_proposal_2'][LANGUAGE_NONE]['#access'] = FALSE;
    
    // If new: Set default values for title and project 1 and 2
    if(arg(1) == 'add'){
      $form['og_group_ref'][LANGUAGE_NONE]['#default_value'] = array($gid_1, $gid_2);
      $form['title']['#default_value'] = $options[$gid_1] . ' - ' . $options[$gid_2];
    }
  }
  else drupal_set_message('Please create/edit relations through the relations administration page', 'warning');
}
      
