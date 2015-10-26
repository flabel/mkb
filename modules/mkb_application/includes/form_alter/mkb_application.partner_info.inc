<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Alter form for application_partner_info
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
function mkb_application_partner_info($form, $form_state, $form_id){
  if (isset($_SESSION["mkb_gid"])) {
    $gid = $_SESSION["mkb_gid"];
    $nid = mkb_application_get_call_main_nid($gid);

    //Set gid in group audience and remove group audience from form
    $form['og_group_ref']['und'][0]['default']['#default_value'][0] = $gid;
    $form['og_group_ref']['#access'] = FALSE;

    //Get options from application-partner-info
    $acronym = mkb_application_get_value($nid, "call_par_acronym");
    $role = mkb_application_get_value($nid, "call_role");
    $publications = mkb_application_get_value($nid, "call_publications");
    $business_plan = mkb_application_get_value($nid, "call_business_plan");
    $sme_declaration = mkb_application_get_value($nid, "call_par_sme");
    $par_add_field_1 = mkb_application_get_value($nid, "call_par_add_field_1");
    $par_add_field_2 = mkb_application_get_value($nid, "call_par_add_field_2");
    $par_add_field_3 = mkb_application_get_value($nid, "call_par_add_field_3");
    $par_add_field_4 = mkb_application_get_value($nid, "call_par_add_field_4");
    $par_add_field_5 = mkb_application_get_value($nid, "call_par_add_field_5");

    // Hide fields from application-partner-info in form
  if($acronym == 0) $form["field_par_acronym"]["#access"] = 0;
  if($role == 0) $form["field_par_role"]["#access"] = 0;
  if($publications == 0) $form["field_par_publications"]["#access"] = 0;
  if($business_plan == 0) $form["field_par_business_plan"]["#access"] = 0;
  if($sme_declaration == 0) $form["field_par_sme"]["#access"] = 0;
    if($par_add_field_1 == 0) $form["field_par_additional_field_1"]["#access"] = 0;
    if($par_add_field_2 == 0) $form["field_par_additional_field_2"]["#access"] = 0;
    if($par_add_field_3 == 0) $form["field_par_additional_field_3"]["#access"] = 0;
    if($par_add_field_4 == 0) $form["field_par_additional_field_4"]["#access"] = 0;
    if($par_add_field_5 == 0) $form["field_par_additional_field_5"]["#access"] = 0;
  }
  return $form;
}