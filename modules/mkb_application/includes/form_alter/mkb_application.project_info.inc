<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Alter form for application_project_info
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
function mkb_application_project_info($form, $form_state, $form_id){
  if (isset($_SESSION["mkb_gid"])) {
    $gid = $_SESSION["mkb_gid"];
    $nid = mkb_application_get_call_main_nid($gid);

    //Set gid in group audience and remove group audience from form
    $form['og_group_ref']['und'][0]['default']['#default_value'][0] = $gid;
    $form['og_group_ref']['#access'] = FALSE;

    // Remove submitted, submit_time and app_selected 1 and 2 from form
    $form['field_app_submitted']['#access'] = FALSE;
    $form['field_app_submit_time']['#access'] = FALSE;
    $form['field_app_selected_1']['#access'] = FALSE;
    $form['field_app_submitted_2']['#access'] = FALSE;
    $form['field_app_submit_time_2']['#access'] = FALSE;
    $form['field_app_selected_2']['#access'] = FALSE;

    //Get options from application-project-info
    $acronym = mkb_application_get_value($nid, "call_app_acronym");
    $duration = mkb_application_get_value($nid, "call_duration");
    $topics = mkb_application_get_value($nid, "call_topics");
    $keywords = mkb_application_get_value($nid, "call_keywords");
    $summary = mkb_application_get_value($nid, "call_summary");
    $expected = mkb_application_get_value($nid, "call_expected");
    $supplementory = mkb_application_get_value($nid, "call_supplementory");
    $app_add_field_1 = mkb_application_get_value($nid, "call_app_add_field_1");
    $app_add_field_2 = mkb_application_get_value($nid, "call_app_add_field_2");
    $app_add_field_3 = mkb_application_get_value($nid, "call_app_add_field_3");
    $app_add_field_4 = mkb_application_get_value($nid, "call_app_add_field_4");
    $app_add_field_5 = mkb_application_get_value($nid, "call_app_add_field_5");

  	// Hide fields in form
    if($acronym == 0) $form["field_app_acronym"]["#access"] = 0;
    if($duration == 0) $form["field_app_duration"]["#access"] = 0;
    if($topics == 0) $form["field_app_topics"]["#access"] = 0;
    if($keywords == 0) $form["field_app_keywords"]["#access"] = 0;
    if($summary == 0) $form["field_app_summary"]["#access"] = 0;
    if($expected == 0) $form["field_app_expected"]["#access"] = 0;
    if($supplementory == 0) $form["field_app_supplementory"]["#access"] = 0;
    if($app_add_field_1 == 0) $form["field_app_additional_field_1"]["#access"] = 0;
    if($app_add_field_2 == 0) $form["field_app_additional_field_2"]["#access"] = 0;
    if($app_add_field_3 == 0) $form["field_app_additional_field_3"]["#access"] = 0;
    if($app_add_field_4 == 0) $form["field_app_additional_field_4"]["#access"] = 0;
    if($app_add_field_5 == 0) $form["field_app_additional_field_5"]["#access"] = 0;

    //Topics - Add js
    $form['#attached']['js'] = array(
    	drupal_get_path('module', 'mkb_application') . '/js/topics.js');

    $form['field_app_topics']['und']['#attributes'] = array(
    		'onchange' => "checkTopics(this);");

    //Filter topics by call-main-page nid belonging to this group
    $topics = mkb_application_get_topics($nid);
    $form['field_app_topics']['und']['#options'] = $topics;
  }
  return $form;
}