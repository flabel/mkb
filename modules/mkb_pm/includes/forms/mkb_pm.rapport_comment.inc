<?php
module_load_include('inc', 'mkb_pm', 'includes/mkb_pm.helper');
module_load_include('inc', 'mkb_pm', 'includes/pages/mkb_pm.rapport_page');

function mkb_pm_rapport_comment_form($form, $form_state, $gid, $apcid){
  $rapport = mkb_pm_application_rapport($gid, $apcid);
  $form['rapport'] = array(
    '#markup' => $rapport,
    '#weight' => 0,
    );
  
  // Application project publish data
  // NOTE: this will not work if there is more than one application project publish per group
  $group_content = mkb_application_get_group_content($gid, 'application_project_publish');
  if(isset($group_content[0])){
    $app_pp = node_load($group_content[0]);

    $form['wrapper'] = array(
      '#type' => 'fieldset', 
      '#title' => 'Comments (' . $app_pp -> comment_count . ') Add comment', 
      '#weight' => 1, 
      '#collapsible' => TRUE, 
      '#collapsed' => TRUE,
    );
    // Comments
    $form['wrapper']['comments'] = array(
      '#markup' => render(comment_node_page_additions($app_pp)),
      '#weight' => 2,
    );
  }
  return $form;
}

function mkb_pm_rapport_comment_form_submit($form, &$form_state){
}
