<?php

module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Generates content for application_home template.
 *
 * @param $gid
 *   Group node id
 * @return form
 *   Application home template.
 */
function mkb_webform_questionnaire($gid, $nid){
  $account = $GLOBALS['user'];
  $variables = array();
  $group = node_load($gid);
  
  $header = array('Name', 'Role', 'Questionnaire');
  $rows = array();
  
  // Get all roles
  $all_og_roles = array_flip(mkb_groups_get_group_roles());
  $coordinator_rid = $all_og_roles['project coordinator'];  

  // Get group users
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
    ->fieldCondition('og_user_node', 'target_id', $gid, '=');
  $results = $query->execute();
   
  foreach ($results['user'] as $uid => $u) {
    $user = user_load($uid);

    // Add name
    $rows[$uid][] = $user->realname;
    
    // Add role
    $og_roles = og_get_user_roles('node', $gid, $user->uid);
    if(array_key_exists($coordinator_rid, $og_roles)) $rows[$uid][] = 'Coordinator';
    else $rows[$uid][] = 'Partner';

    // Get component id of project_id field
    $query = db_select("webform_component", "ws");
    $query->addField("ws", "cid", "cid");
    $query->condition("ws.nid", $nid)
          ->condition("ws.form_key", "project_id");
    $cid = $query->execute()->fetchField();
    
    // Check if user has created a questionnaire for this group
    $query = db_select("webform_submissions", "ws");
    $query->leftJoin("webform_submitted_data", "wsd", "wsd.sid = ws.sid");
    $query->addField("wsd", "sid", "sid");
    $query->condition("ws.uid", $uid)
          ->condition("ws.nid", $nid)
          ->condition("wsd.cid", $cid)
          ->condition("wsd.data", $gid);
    $sid = $query->execute()->fetchField();
    
    // Add link Create / View/Edit
    if($sid !== FALSE){
      if($uid == $account->uid){
        $link = l('View', 'node/' . $nid . '/submission/' . $sid) . '/' . l('Edit', 'node/' . $nid . '/submission/' . $sid . '/edit',
                    array('query' => drupal_get_destination()));
      }
      else $link = 'Submitted';
    }
    else{
      if($uid == $account->uid) $link = l('Create', 'node/' . $nid);
      else $link = 'Pending'; 
       
    }
    $rows[$uid][] = $link;
  }
  
  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('questionnaire', $variables);
}
