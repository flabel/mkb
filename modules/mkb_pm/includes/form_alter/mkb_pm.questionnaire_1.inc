<?php
module_load_include('inc', 'mkb_pm', 'includes/mkb_pm.helper');

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
function mkb_pm_questionnaire_1($form, $form_state, $form_id){
  if(user_is_anonymous()) return $form;
  $account = $GLOBALS['user'];
  $account = user_load($account->uid);
  $account_wrapper = entity_metadata_wrapper('user', $account);
  $profile = profile2_load_by_user($account, 'main');
  if($profile) $profile_wrapper = entity_metadata_wrapper('profile2', $profile);
  else $profile_wrapper = FALSE;
  
  if(isset($_SESSION["mkb_gid"])){
    $gid = $_SESSION["mkb_gid"];
    
    $group_content = mkb_application_get_group_content($gid, 'application_project_info');
    $project_info = $group_content[0];
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);

    
    if(!isset($form['details'])) return $form;
    if($form['details']['page_num']['#value'] == 1){
       // Project acronym
      $acronym = $project_info_wrapper->field_app_acronym->value();
      $form['submitted']['acronym']['#default_value'] = $acronym;
      $form['submitted']['acronym']['#disabled'] = TRUE;
      
      // Project id
      $form['submitted']['project_id']['#default_value'] = $gid;
      $form['submitted']['project_id']['#disabled'] = TRUE;
      
      if(isset($form['submitted']['please_enter_your_name'])){
        // Name
        $form['submitted']['please_enter_your_name']['#default_value'] = $account->realname;
        
        // Country
        $country = $account_wrapper->field_country->name->value();
        $form['submitted']['please_enter_your_country_region']['#default_value'] = isset($country) ? $country : '';
        
        // ************
        // Organisation name and type
        if ($profile_wrapper) $org = $profile_wrapper->field_my_organisation->value();
        if(isset($org)){
          $form['submitted']['Please_enter_the_name_of_your_organisation']['#default_value'] = $org->title;
          $org_wrapper = entity_metadata_wrapper('node', $org);
          $org_type = $org_wrapper->field_organisation_type->value();
          if(isset($org_type[0])) $form['submitted']['please_select_the_type_of_organisation_you_represent']['#default_value'] = $org_type[0]->name;
        }
        
        // Roles
        $og_roles = og_get_user_roles('node', $gid, $account->uid);
        $form['submitted']['are_you_the_coordinator_of_the_project_consortium']['#default_value'] = in_array('project coordinator', $og_roles) ? 0 : 1;
      }
    }
    if($form['details']['page_num']['#value'] == 1 && isset($form['submitted']['call_id'])){
      // Call
      $call_id = mkb_application_get_call_main_nid($gid);
      if(isset($call_id)){
        $form['submitted']['call_id']['#default_value'] = $call_id;
        $form['submitted']['call_id']['#disabled'] = TRUE;
        $call = node_load($call_id);        
        $form['submitted']['call_name']['#default_value'] = $call->title;
        $form['submitted']['call_name']['#disabled'] = TRUE;
      }
    }
    if($form['details']['page_num']['#value'] == 1 && isset($form['submitted']['finance_wrapper'])){
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
          $n = count($budget[10])-1;
          
          // finance_wrapper
          $requested = $budget[10][$n];
          $form['submitted']['finance_wrapper']['ict_agri']['#default_value'] = $requested;
          $total = $budget[10][$n-1];
          $form['submitted']['finance_wrapper']['own_funds']['#default_value'] = $total-$requested;
          
          // budget_used_wrapper
          $salary = $budget[3][$n-1];
          $form['submitted']['budget_used_wrapper']['salary']['#default_value'] = $salary;
          
          $equipment = $budget[6][$n-1];
          $form['submitted']['budget_used_wrapper']['equipment']['#default_value'] = $equipment;
          
          $t_m = $budget[4][$n-1];
          $form['submitted']['budget_used_wrapper']['travelling_meetings']['#default_value'] = $t_m;
          
          $other = $budget[5][$n-1] + $budget[7][$n-1] + $budget[8][$n-1] + $budget[9][$n-1];
          $form['submitted']['budget_used_wrapper']['other_expenditures']['#default_value'] = $other;
        }        
      }      
    }
    
  }

  return $form;
}
