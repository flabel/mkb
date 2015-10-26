<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Alter form for group
 *
 * @param $form
 *   Form
 * @param $form_state
 *   Form state
 * @param $form_id
 *   Form id
 * @return $form
 *   Altered form.
 */
function mkb_application_group($form, $form_state, $form_id){
  //if group is new OR application nid is empty
  if(!isset($form["nid"]['#value']) ||
      !isset($form["field_group_application"]["und"]["#default_value"][0])){
    $data = mkb_application_call_open();
    $options = array();
    $options["_none"] = "- None -";
    foreach($data as $row){
      $options[$row->entity_id] = $row->title;
    }
    $form["field_group_application"]["und"]["#options"] = $options;
  }
  //if group is not new
  else{
    $default_id = $form["field_group_application"]["und"]["#default_value"][0];
    $options = $form["field_group_application"]["und"]["#options"];
    $new_options = array();
    while (list($key,$val) = each($options)) {
      if($key == $default_id){
        $new_options[$key] = $val;
      }
    }
    $form["field_group_application"]["und"]["#options"] = $new_options;
  }
  return $form;
}