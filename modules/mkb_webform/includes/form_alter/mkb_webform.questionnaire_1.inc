<?php
module_load_include('inc', 'mkb_webform', 'includes/mkb_webform.helper');

/**
 * Alter form for questionnaire 1
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
function mkb_webform_questionnaire_1($form, $form_state, $form_id){
  if(user_is_anonymous()) return $form;
  $account = $GLOBALS['user'];
  $account = user_load($account->uid);
  $account_wrapper = entity_metadata_wrapper('user', $account);
  $profile = profile2_load_by_user($account, 'main');
  $profile_wrapper = entity_metadata_wrapper('profile2', $profile);
  
  if(isset($_SESSION["mkb_gid"])){
    $gid = $_SESSION["mkb_gid"];
    
    if(!isset($form['details'])) return $form;
    if($form['details']['page_num']['#value'] == 1){
      // Name
      $form['submitted']['please_enter_your_name']['#default_value'] = $account->realname;
      
      // Country
      $country = $account_wrapper->field_country->name->value();
      $form['submitted']['please_enter_your_country_region']['#default_value'] = isset($country) ? $country : '';
      
      // Organisation name and type
      $org = $profile_wrapper->field_my_organisation->value();
      if(isset($org)){
        $form['submitted']['Please_enter_the_name_of_your_organisation']['#default_value'] = $org->title;
        $org_wrapper = entity_metadata_wrapper('node', $org);
        $org_type = $org_wrapper->field_organisation_type->value();
        if(isset($org_type[0])) $form['submitted']['please_select_the_type_of_organisation_you_represent']['#default_value'] = $org_type[0]->name;
      }
      
      // Project id
      $form['submitted']['project_id']['#default_value'] = $gid;
      $form['submitted']['project_id']['#disabled'] = TRUE;
      
      // Roles
      $og_roles = og_get_user_roles('node', $gid, $account->uid);
      $form['submitted']['are_you_the_coordinator_of_the_project_consortium']['#default_value'] = in_array('project coordinator', $og_roles) ? 0 : 1;
    }
    elseif($form['details']['page_num']['#value'] == 2){
      // Call
      $call_id = mkb_application_get_call_main_nid($gid);
      if(isset($call_id)){
        $form['submitted']['call_id']['#default_value'] = $call_id;
        $call = node_load($call_id);        
        $form['submitted']['call_name']['#default_value'] = $call->title;
      }
    }
    elseif($form['details']['page_num']['#value'] == 3){
      // Budget
      $query = new EntityFieldQuery();

      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'application_partner_budget')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->propertyCondition('uid', $account->uid)
        ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
        ->addMetaData('account', user_load(1));

      $result = $query->execute();

      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $budget = mkb_application_get_budget_table($nids[0]);

        // ICT-AGRI funding Requested & Own funding (Total - Requested)
        if(isset($budget[10])){
          $last_i = count($budget[10])-1;
          $requested = $budget[10][$last_i];
          $form['submitted']['to_finance_your_part_of_the_project_what_amount_in_euros_was_funded_by_ICT_AGRI']['#default_value'] = $requested;
          $total = $budget[10][$last_i-1];
          $form['submitted']['to_finance_your_part_of_the_project_what_amount_in_euros_was_funded_by_your_own_funds']['#default_value'] = $total-$requested;
        }        
      }      
    }
    
  }
  //else{
    //drupal_set_message('Please go through the proposal workspace to create the questionnaire', 'warning');
    //drupal_goto('<front>');
  //}

  return $form;
}

