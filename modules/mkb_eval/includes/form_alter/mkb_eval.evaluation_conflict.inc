<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * hook_form_alter : $form_id == 'evaluation_conflict_node_form'
 */
function mkb_eval_evaluation_conflict_alter(&$form, $form_state, $form_id){
  // Set group by default
  $gid = 0;
  if(arg(1) == 'add' && is_numeric(arg(3))) $gid = arg(3);
  if(arg(2) == 'edit' && is_numeric(arg(3))) $gid = arg(3);
  if($gid != 0){
    $form['og_group_ref']['und']['#default_value'][0] = $gid;
    $form['og_group_ref']['#access'] = FALSE;

    $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
    $title = 'None';
    if($project_info_nids){
      $project_info_node = node_load($project_info_nids[0]);
      $acronym = $project_info_node->field_app_acronym['und'][0]['value'] . ' - conflict';
    }
    $form['title']['#default_value'] = $acronym;
    $form['title']['#access'] = FALSE;

    // Print table of application participants
    $header = array('Role', 'Name', 'Country', 'Acronym', 'Organisation');
    $rows = array();
    $group_data = mkb_application_get_group_user_and_roles($gid);
    foreach ($group_data['rows'] as $row){
      if($row->entity_type == 'user'){
        $user_my_org = mkb_application_get_my_org($row->uid);
        $rows[$row->uid] = array(
            0 => $row->role,
            1 => $row->realname,
            2 => isset($row->country) ? $row->country : '',
            );

        if(!array_key_exists(3, $rows)){
          $rows[$row->uid][3] = '';
          $rows[$row->uid][4] = '';
        }
      }
      elseif($row->entity_type == 'node'){
        if($row->type == 'application_partner_info'){
          $partner_info = node_load($row->nid);
          if($partner_info){
            $rows[$row->author_uid][3] = isset($partner_info->field_par_acronym['und'][0]['value']) ?
              $partner_info->field_par_acronym['und'][0]['value'] : '';
            $rows[$row->author_uid][4] = isset($partner_info->title) ? $partner_info->title : '';
          }
        }
      }
    }

    $form['table'] = array(
        '#markup' => theme('table', array('header' => $header, 'rows' => $rows)),
        '#weight' => 0,
        );

   // Print the project-info summary
   $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
   if(isset($project_info_nids[0])){
     $project_info = node_load($project_info_nids[0]);

     $form['summary'] = array(
         '#type' => 'fieldset',
         '#title' => 'Summary',
         '#weight' => 1,
         '#collapsible' => TRUE,
         '#collapsed' => FALSE,
         );

     $form['summary']['text'] = array(
         '#markup' => isset($project_info->field_app_summary['und'][0]['value']) ?
             nl2br($project_info->field_app_summary['und'][0]['value']) : 'None',
         );
   }
  }
}
