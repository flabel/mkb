<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * hook_form_alter : $form_id == 'expert_evaluators_node_form'
 */
function mkb_eval_expert_evaluators_alter(&$form, $form_state, $form_id){
  $gid = 0;
  $eval_conf_nid = 0;
  if(is_numeric(arg(3))) $gid = arg(3);
  if(is_numeric(arg(4))) $eval_conf_nid = arg(4);

  $title = 'Assign evaluation experts';
  if($gid != 0 && $eval_conf_nid != 0){

    // Group
    $form['og_group_ref'][LANGUAGE_NONE]['#default_value'][0] = $gid;
    $form['og_group_ref']['#access'] = FALSE;

    // Eval conf
    $form['field_eval_conf'][LANGUAGE_NONE]['#default_value'][0] = $eval_conf_nid;
    $form['field_eval_conf']['#access'] = FALSE;

    $acronym = 'Expert evaluators';
    $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
    if($project_info_nids){
      $project_info_node = node_load($project_info_nids[0]);
      $acronym = $project_info_node->field_app_acronym['und'][0]['value'];
    }

    $form['title']['#default_value'] = $acronym;
    $form['title']['#access'] = FALSE;

    // Custom title
    $eval_conf = node_load($eval_conf_nid);
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);

    $title = '<p><b>Evaluation configuration type:</b> ' . $eval_conf_wrapper->label() . '</p>';
    $title .= '<p><b>Application:</b> ' . $acronym . '</p>';

    $form['custom_title'] = array(
        '#markup' => $title,
        '#weight' => -50,
        );

    // Add number of application each expert evaluator is already assigned to
    $options = isset($form['field_expert_application_id'][LANGUAGE_NONE]['#options']) ? array_keys($form['field_expert_application_id'][LANGUAGE_NONE]['#options']) : NULL;

    $expert_applications = node_load_multiple($options); 
    if(isset($expert_applications)){
      foreach ($expert_applications as $expert_application){
        $expert_application_wrapper = entity_metadata_wrapper('node', $expert_application);

        // Filter expert applications by eval_conf and selected
        $expert_application_eval_conf_nids = $expert_application_wrapper->field_eval_conf_id->raw();
        $selected_list = $expert_application_wrapper->field_expert_selected->value();

        if(!$selected_list) $selected_list = array();
        if(in_array($eval_conf_nid, $expert_application_eval_conf_nids) && in_array($eval_conf_nid, $selected_list)){

          // Get number of applications this application_expert is already assigned to
          $count = mkb_eval_get_application_expert_count($expert_application->nid, $eval_conf_nid);

          // Username
          $account = $expert_application_wrapper->field_expert_usr->value();

          // Option string
          $option_str = $account->realname . ' (' . $count . ')';

          // Add application expert to form
          $form['field_expert_application_id'][LANGUAGE_NONE]['#options'][$expert_application->nid] = $option_str;
        }
        else{
          unset($form['field_expert_application_id'][LANGUAGE_NONE]['#options'][$expert_application->nid]);
        }
      }
    }
  }

  if(empty($form['field_expert_application_id'][LANGUAGE_NONE]['#options'])){
    $form['field_expert_application_id'][LANGUAGE_NONE]['#description'] = 'No evaluators with this expertise
        has been selected';
  }

  // Text to explain the numbers of applications each evaluator has been assigned to
  $form['field_expert_application_id'][LANGUAGE_NONE]['#title'] = 'Evaluators:';
}
