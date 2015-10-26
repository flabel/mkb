<?php

/**
 * @param $expert_application_nid
 *   Node id.
 * @param $eid
 *   Evaluation configuration node id.
 * @return $count
 *   Number of applications this expert application is assigned to.
 */
function mkb_eval_get_application_expert_count($nid, $eid){
  $query = db_select("field_data_field_expert_application_id", "field_expert_application_id");
  $query->leftJoin('field_data_field_eval_conf', 'field_eval_conf',
      'field_eval_conf.entity_id = field_expert_application_id.entity_id');
  $query ->addField("field_expert_application_id", "entity_id", "entity_id");
  $query
  ->condition("field_expert_application_id.entity_type", 'node')
  ->condition("field_expert_application_id.bundle", 'expert_evaluators')
  ->condition("field_expert_application_id.field_expert_application_id_target_id", $nid)
  ->condition("field_eval_conf.entity_type", 'node')
  ->condition("field_eval_conf.bundle", 'expert_evaluators')
  ->condition("field_eval_conf.field_eval_conf_target_id", $eid);
  return $query->execute()->rowCount();
}

/**
 * Specfic for CORE-ORGANIC:
 * Return applications that is submitted for stage 2 by applicatans
 * Return applications that is selected for stage 2 by evaluators
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Evaluation filter nid.
 * @return $groups
 *   Groups.
 */
function mkb_eval_get_stage_applications($cid, $fid){
  global $user;
  $groups = array();
  // Get current call stage
  $call = node_load($cid);
  $wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $wrapper->field_current_stage->value();

  // Get evaluation filter
  $filter = node_load($fid);
  $filter_wrapper = entity_metadata_wrapper('node', $filter);
  $filter_submit_1 = $filter_wrapper->field_filter_submit_1->value();
  $filter_submit_2 = $filter_wrapper->field_filter_submit_2->value();
  $filter_select_1 = $filter_wrapper->field_filter_select_1->value();
  $filter_select_2 = $filter_wrapper->field_filter_select_2->value();

  // Get groups
  if (in_array('administrator', $user->roles) || in_array('call administrator', $user->roles)){
    $groups = node_load_multiple(array(), array('type' => 'group'));
    foreach ($groups as $gid => $group){
      $unset = FALSE;
      $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
      if($project_info_nids){
        $project_info = node_load($project_info_nids[0]);
        $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
        if($current_stage == 1){
          $app_submitted = $project_info_wrapper->field_app_submitted->value();
          if($app_submitted != $filter_submit_1) $unset = TRUE;
        }
        elseif($current_stage == 2){
          $app_submitted_2 = $project_info_wrapper->field_app_submitted_2->value();
          $app_selected_1 = $project_info_wrapper->field_app_selected_1->value();
          if($app_selected_1 != $filter_submit_1 || $app_submitted_2 != $filter_submit_2) $unset = TRUE;
        }
      }
      else{
        $unset = TRUE;
      }
      if($unset) unset($groups[$gid]);
    }
  }
  return $groups;
}

/**
 * @param $nid
 *   Node id (gid).
 * @return $allowed_values
 *   Allowed values key => value array.
 */
function mkb_eval_get_allowed_values($field){
  $field = field_info_field($field);
  $allowed_values= list_allowed_values($field);
  return $allowed_values;
}


/**
 * @param $gid
 *   Group node id (gid).
 * @return $data
 *   questionnaire entity ids belonging to this group.
 */
function mkb_eval_get_experts_questionnaire_by_uid($gid){
  $query = db_select('og_membership', 'og_membership');
  $query->leftJoin('field_data_field_exp_evaluator', 'field_exp_evaluator',
      'field_exp_evaluator.field_exp_evaluator_target_id = og_membership.etid');
  $query->leftJoin('eck_expert_questionnaire', 'eck_expert_questionnaire',
      'eck_expert_questionnaire.id = field_exp_evaluator.entity_id');
  $query->addField('eck_expert_questionnaire', 'uid', 'uid');
  $query->addField('eck_expert_questionnaire', 'id', 'id');
  $query
  ->condition('og_membership.entity_type', 'expert_evaluators')
  ->condition('og_membership.gid', $gid);
  $result = $query->execute()->fetchAll();
  $data = array();
  if($result !== FALSE){
    foreach ($result as $row){
      $data[$row->id] = $row->uid;
    }
  }
  return $data;
}

/**
 * @param $gid
 *   Group node id (gid).
 * @return $result
 *   expert_evaluators entity ids belonging to this group.
 */
function mkb_eval_get_eval_experts_by_gid($gid){
  $query = db_select("og_membership", "og_membership");
  $query->addField("og_membership", "etid", "nid");
  $query
  ->condition("og_membership.entity_type", "expert_evaluators")
  ->condition("og_membership.gid", $gid);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * Sort function.
 *
 * @param $array
 *   Array to be sorted.
 * @param $key
 *   Key to sort by.
 * @param $order
 *   Sort direction. (optional)
 * @return $output
 *   Rendered output.
 */

function field_sort (&$array, $sort_key, $order='asc') {
    $sorter=array();
    $new_sorted=array();
    reset($array);
    foreach ($array as $ii => $values) {
        $sorter[$ii]=$values[$sort_key];
    }
    if ($order=='asc') asort($sorter);
    if ($order=='desc') arsort($sorter);
    foreach ($sorter as $ii => $values) {
        $new_sorted[$ii]=$array[$ii];
    }
    $array=$new_sorted;
}

/**
 * @param $cid
  *   Call-main-page node id
 * @return $group_ids
 *   Group ids
 */
function mkb_eval_get_group_ids($cid){
  // Get all groups to this call
  $group_content = mkb_eval_get_group($cid, array('group_title' => TRUE, 'group_body' => TRUE));

  // Group content keys to initiate content and groups
  $group_ids = array();
  foreach (array_keys($group_content) as $key){
    $group_ids[$key] = array();
  }
  return $group_ids;
}

/**
 * @param $groups
  *   Groups
 * @return $groups
 *   All groups with application ids
 */
function mkb_eval_get_group_aids($groups){
  $applications = array();
  foreach ($groups as $gid => $group){
    // Fill the groups array with application ids
    $aids = mkb_eval_get_aids($gid);

    $application_init = array(
        'application_project_info' => FALSE,
        'application_partner_info' => array(),
        'application_partner_budget' => array(),
        );
    foreach ($aids as $aid){
      if($aid->type == 'application_project_info') $application_init['application_project_info'] = $aid->aid;
      if($aid->type == 'application_partner_info') $application_init['application_partner_info'][] = $aid->aid;
      if($aid->type == 'application_partner_budget') $application_init['application_partner_budget'][] = $aid->aid;
    }
    $applications[$gid] = $application_init;
    // Remove all groups that doesn´t have a project-info
    if(!$application_init['application_project_info']){
      unset($applications[$gid]);
    }
  }
  return $applications;
}

/**
 * @param $content
 *   Array with all group ids as key
 * @param $group_content
 *   Array group id, title and body
 * @param $view
 *   Current view
 * @param $view_keys
 *   Keys from current view
 * @return content
 *   Group content: gid, title and body
 */
function mkb_eval_build_content($groups, $view, $view_keys){
  $content = array();

  // build a default group with keys from view
  $group_default = array();
  foreach ($view_keys as $key){
    $group_default[$key] = "";
  }

  // Add group_default to each group in content
  // Add gid if true in view
  foreach ($groups as $gid => $group){
    $content[$gid] = $group_default;
    if(isset($view['gid']) && $view['gid']) $content[$gid]['gid'] = $gid;
  }
  return $content;
}

/**
 * @param $cid
  *   Call-main-page nid.
 * @param $view
  *   view with boolean for gid, title and body.
 * @return group
 *   Group content: gid, title (optional), body (optional)
 */
function mkb_eval_get_group($cid, $view){
  $query = db_select("field_data_field_group_application", "ga");
  $query ->leftJoin("node", "n", "n.nid = ga.entity_id");
  $query ->leftJoin("field_data_body", "b", "b.entity_id = n.nid");
  $query ->addField("n", "nid", "gid");
  if($view['group_title']) $query ->addField("n", "title", "group_title");
  if($view['group_body']) $query ->addField("b", "body_value", "group_body");
  $query
  ->condition("ga.field_group_application_target_id", $cid)
  ->condition("ga.entity_type", "node")
  ->condition("n.type", "group")
  ->condition("b.entity_type", "node");
  $query ->orderBy('gid', 'ASC');
  $groups = $query->execute()->fetchAll();

  $return = array();
  foreach ($groups as $key => $group){
    $return[$group->gid] = array('gid' => $group->gid);
    if($view['group_title']) $return[$group->gid]['group_title'] = $group->group_title;
    if($view['group_body']) $return[$group->gid]['group_body'] = $group->group_body;
  }
  return $return;
}

/**
 * @param $gid
  *   Group ID.
 * @return app_ids and type
 *   Application (project-info, partner-info, partner-budget) ids to a group
 */
function mkb_eval_get_aids($gid){
  $query = db_select("og_membership", "og");
  $query ->leftJoin("node", "n", "n.nid = og.etid");
  $query ->addField("og", "etid", "aid");
  $query ->addField("n", "type", "type");
  $query
  ->condition("og.gid", $gid)
  ->condition("og.entity_type", "node");
  $db_or = db_or();
  $db_or->condition("n.type", "application_project_info");
  $db_or->condition("n.type", "application_partner_info");
  $db_or->condition("n.type", "application_partner_budget");
  $query->condition($db_or);
  $app_ids = $query->execute()->fetchAll();
  return $app_ids;
}

/**
 * @param $gid
 *   Group ID.
 * @param $type
 *   Evaluation configuration node type.
 * @return app_ids
 *   Application (node type) id to a group
 */
function mkb_eval_get_aid($gid, $type){
  $query = db_select("og_membership", "og");
  $query ->leftJoin("node", "n", "n.nid = og.etid");
  $query ->addField("og", "etid", "aid");
  $query
  ->condition("og.gid", $gid)
  ->condition("og.entity_type", "node")
  ->condition("n.type", $type);

  $app_id = $query->execute()->fetchField();
  return $app_id;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return acronym
 *   Application-project-info acronym.
 */
function mkb_eval_get_acronym($nid){
  $query = db_select("field_data_field_app_acronym", "field_app_acronym");
  $query ->addField("field_app_acronym", "field_app_acronym_value", "acronym");
  $query
  ->condition("field_app_acronym.entity_id", $nid)
  ->condition("field_app_acronym.entity_type", "node");
  $acronym = $query->execute()->fetchField();
  return $acronym;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return acronym
 *   Application-project-info title.
 */
function mkb_eval_get_title($nid){
  $query = db_select("node", "node");
  $query ->addField("node", "title", "title");
  $query
  ->condition("node.nid", $nid)
  ->condition("node.type", "application_project_info");
  $title = $query->execute()->fetchField();
  return $title;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return acronym
 *   Application-project-info submitted.
 */
function mkb_eval_get_submitted($nid){
  $query = db_select("field_data_field_app_submitted", "field_app_submitted");
  $query ->addField("field_app_submitted", "field_app_submitted_value", "submitted");
  $query
  ->condition("field_app_submitted.entity_id", $nid)
  ->condition("field_app_submitted.entity_type", "node");
  $submitted = $query->execute()->fetchField();
  return $submitted;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return acronym
 *   Application-project-info selected_1.
 */
function mkb_eval_get_selected_1($nid){
  $query = db_select("field_data_field_app_selected_1", "field_app_selected_1");
  $query ->addField("field_app_selected_1", "field_app_selected_1_value", "selected_1");
  $query
  ->condition("field_app_selected_1.entity_id", $nid)
  ->condition("field_app_selected_1.entity_type", "node");
  $selected_1 = $query->execute()->fetchField();
  return $selected_1;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return $coordinator
 *   Application-project-info auhor's (Project coordinator) user id and realname.
 */
function mkb_eval_get_coordinator($nid){
  $query = db_select("node", "node");
  $query ->leftJoin("users", "users", "users.uid = node.uid");
  $query ->leftJoin("realname", "realname", "realname.uid = users.uid");
  $query ->leftJoin("profile", "profile", "profile.uid = users.uid");
  $query ->addField("users", "uid", "uid");
  $query ->addField("realname", "realname", "realname");
  $query
    ->condition("node.nid", $nid)
    ->condition("node.type", "application_project_info");

  $coordinator = $query->execute()->fetchAll();
  return $coordinator;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return acronym
 *   Application-project-info Description of work (DOW).
 *
 */
function mkb_eval_get_dow($nid){
  $query = db_select("field_data_field_app_dow", "field_app_dow");
  $query ->leftJoin("file_managed", "file_managed", "file_managed.fid = field_app_dow.field_app_dow_fid");
  $query ->addField("file_managed", "uri", "uri");
  $query
  ->condition("field_app_dow.entity_id", $nid)
  ->condition("field_app_dow.entity_type", "node");
  $uri = $query->execute()->fetchField();
  if($uri){
    $url = file_create_url($uri);
    $dow = l(t('View'), $url);
  }
  else{
    $dow = "";
  }
  return $dow;
}

/**
 * @param $nid
  *   Application-project-info node id (nid).
 * @return topics
 *   Application-project-info topics (level 1 only).
 *
 */
function mkb_eval_get_topics($nid){
  $query = db_select("field_data_field_app_topics", "field_app_topics");
  $query ->leftJoin("field_data_field_topic_level", "field_topic_level", "field_topic_level.entity_id = field_app_topics.field_app_topics_target_id");
  $query ->leftJoin("node", "node", "node.nid = field_app_topics.field_app_topics_target_id");
  $query ->addField("node", "title", "topic");
  $query
  ->condition("field_topic_level.field_topic_level_value", "1")
  ->condition("field_app_topics.entity_id", $nid)
  ->condition("node.type", "call_topic");
  $result = $query->execute()->fetchAll();
  $topics = '';
  if($result !== FALSE){
    foreach ($result as $row){
      $topics .= $row->topic;
    }
    return $topics;
  }

  return $result;
}

/**
 * @param $nid
 *   Application-project-info node id (nid).
 * @param $tid
 *   Call-topic node id
 * @return has_topic
 *   Boolean
 */
function mkb_eval_has_topic($nid, $tid){
  $query = db_select("field_data_field_app_topics", "field_app_topics");
  $query ->addField("field_app_topics", "field_app_topics_target_id", "tid");
  $query
  ->condition("field_app_topics.entity_id", $nid)
  ->condition("field_app_topics.field_app_topics_target_id", $tid);
  $result = $query->execute()->fetchField();
  return $result;
}


/**
 * @param $gid
  *   Group id.
 * @return $iso2
 *   iso2 of the country each application-partner-info node author
 *   has set a my_country in their account.
 */
function mkb_eval_get_country($gid){
  //User data
  $query = db_select("og_membership", "og_membership");
  $query->leftJoin("users", "users", "users.uid = og_membership.etid");
  $query->leftJoin("field_data_field_country", "field_data_field_country", "field_data_field_country.entity_id = users.uid");
  $query->leftJoin("og_users_roles", "og_users_roles", "og_users_roles.uid = users.uid");
  $query->leftJoin("og_role", "og_role", "og_role.rid = og_users_roles.rid");
  $query->addField("field_data_field_country", "field_country_iso2", "iso2");
  $query->condition("og_membership.entity_type", "user");
  $query->condition("field_data_field_country.entity_type", "user");
  $query->condition("field_data_field_country.bundle", "user");
  $query->condition("og_membership.gid", $gid);
  $query->condition("og_users_roles.gid", $gid);
//  $query->condition("og_role.name", "administrator", "<>");
//  $query->condition("og_role.name", "project editor", "<>");
//  $query->condition("og_role.name", "project partner", "<>");
//  $query->condition("og_role.name", "project coordinator", "<>");
  $query->distinct();
  $result = $query->execute()->fetchAll();

  // Remove duplicates
  $result = array_unique($result, SORT_REGULAR);
  // Reindex array
  $result = array_values($result);

  // Build iso2 string
  $iso2 = "";
  for($i = 0; $i < count($result); $i++){
    if($i == 0) $iso2 = $result[$i]->iso2;
    else $iso2 .= " " . $result[$i]->iso2;
  }
  return $iso2;
}

/**
 * @param $nid
  *   Call-funder-page node id.
 * @return $country
 *   Funding agency country.
 */
function mkb_eval_get_funder_page_country($nid){
  $query = db_select("field_data_field_funding_agency", "field_funding_agency");
  $query->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query->leftJoin("countries_country", "countries_country", "countries_country.iso2 = field_country.field_country_iso2");
  $query->addField("countries_country", "name", "country");
  $query->condition("field_funding_agency.entity_id", $nid);
  $query->condition("field_funding_agency.bundle", 'call_funder_page');
  $query->condition("field_country.bundle", 'organisation');
  $query->distinct();
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $uid
 *   Current user id.
 * @param $gid
 *   Group id.
 * @param $type
 *   Array of Evaluation types.
 * @return $evaluation_id
 *   Evaluation id.
 */
function mkb_eval_get_exp_evaluation_ids($uid, $gid, $type){
  $query = db_select("evaluation", "evaluation");
  $query ->addField("evaluation", "evaluation_id", "evaluation_id");
  $query
    ->condition("evaluation.uid", $uid)
    ->condition("evaluation.gid", $gid)
    ->condition("evaluation.type", $type, 'IN');
  $result = $query->execute()->fetchAll();
  $evaluation_ids = array();
  foreach ($result as $row){
    $evaluation_ids[] = $row->evaluation_id;
  }
  return $evaluation_ids;
}

/**
 * @param $uid
 *   Current user id.
 * @param $eid
 *   Evaluation configuration node id.
 * @param $gid
 *   Group id.
 * @param $type
 *   Evaluation type.
 * @return $evaluation_id
 *   Evaluation id.
 */
function mkb_eval_get_evaluation_id($uid, $eid, $gid, $type){
  $query = db_select("evaluation", "evaluation");
  $query ->addField("evaluation", "evaluation_id", "evaluation_id");
  $query
    ->condition("evaluation.uid", $uid)
    ->condition("evaluation.eid", $eid)
    ->condition("evaluation.gid", $gid)
    ->condition("evaluation.type", $type);
  $evaluation_id = $query->execute()->fetchField();
  return $evaluation_id;
}

/**
 * @param $funder_page_uids
 *   Funder page user ids.
 * @param $eval_conf
 *   Evaluation configuration node.
 * @param $gid
 *   Group id.
 * @return $evaluation_id
 *   Evaluation id.
 */
function mkb_eval_get_funder_page_evaluation_id($funder_page_uids, $eval_conf, $gid){
  $query = db_select("evaluation", "evaluation");
  $query ->leftJoin("node", "node", "node.nid = evaluation.eid");
  $query ->addField("evaluation", "evaluation_id", "evaluation_id");
  $query
    ->condition("evaluation.uid", $funder_page_uids, 'IN')
    ->condition("evaluation.eid", $eval_conf->nid)
    ->condition("evaluation.gid", $gid)
    ->condition("node.type", $eval_conf->type);
  $evaluation_id = $query->execute()->fetchField();
  return $evaluation_id;
}

/**
 * @param $gid
 *   Group id.
 * @param $eval_conf_type (optional)
 *   Evaluation configuration node type.
 * @return $evaluation_ids
 *   All Evaluation ids to a group.
 *
 * @todo Should this function be in evaluation module like evaluation_load?
 */
function mkb_eval_get_evaluation_ids($gid, $eval_conf_type = NULL){
  $query = db_select("evaluation", "evaluation");
  $query ->leftJoin("node", "node", "node.nid = evaluation.eid");
  $query ->leftJoin("node_type", "node_type", "node_type.type = node.type");
  $query ->addField("node_type", "name", "type");
  $query ->addField("evaluation", "evaluation_id", "evaluation_id");
  $query ->condition("evaluation.gid", $gid);
  if(isset($eval_conf_type)) $query ->condition("node.type", $eval_conf_type);
  $evaluation_ids = $query->execute()->fetchAll();
  return $evaluation_ids;
}



/**
 * @param $gid
 *   Group id.
 * @return $score
 *   Evaluation score
 *
 * @todo Should this function be in evaluation module like evaluation_load?
 */
function mkb_eval_get_score($gid){
  $query = db_select("evaluation", "evaluation");
  $query ->leftJoin("node", "node", "node.nid = evaluation.eid");
  $query ->leftJoin("node_type", "node_type", "node_type.type = node.type");
  $query ->addField("node_type", "name", "type");
  $query ->addField("evaluation", "evaluation_id", "evaluation_id");
  $query ->condition("evaluation.gid", $gid);
  if(isset($eval_conf_type)) $query ->condition("node.type", $eval_conf_type);
  $evaluation_ids = $query->execute()->fetchAll();
  return $evaluation_ids;
}

/**
 * @param $cid
 *   call-main-page node id.
 * @param $uid
 *   current user id.
 * @return $nid
 *   Call-funder-page nid of call where current user is call manager.
 */
function mkb_eval_get_manager_funder_pages($cid, $uid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_call_managers", "field_call_managers", "field_call_managers.entity_id = field_call_id.entity_id");
  $query ->addField("field_call_managers", "entity_id", "nid");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_managers.field_call_managers_target_id", $uid);
  $result = $query->execute()->fetchAll();

  if($result !== FALSE){
    $funder_pages = array();
    foreach ($result as $row){
      if($row->nid !== NULL) $funder_pages[] = $row->nid;
    }
    return $funder_pages;
  }
  return $result;
}

/**
 * @param $cid
 *   call-main-page node id.
 * @param $uid
 *   current user id.
 * @return $nid
 *   Call-funder-page nid of call where current user is evaluator.
  */
function mkb_eval_get_evaluator_funder_pages($cid, $uid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_evaluators", "field_evaluators", "field_evaluators.entity_id = field_call_id.entity_id");
  $query ->addField("field_evaluators", "entity_id", "nid");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_evaluators.field_evaluators_target_id", $uid);
  $result = $query->execute()->fetchAll();

  if($result !== FALSE){
    $funder_pages = array();
    foreach ($result as $row){
      if($row->nid !== NULL) $funder_pages[] = $row->nid;
    }
    return $funder_pages;
  }
  return $result;
}

/**
 * @param $gid
 *   Group id.
 * @return $has_evaluation
 *   True if this group in this call has an evaluation.
  */
function mkb_eval_form_eval_link($gid){
  $query = db_select("evaluation", "evaluation");
  $query ->leftJoin("node", "node", "node.nid = evaluation.eid");
  $query ->addField("evaluation", "evaluation_id", "evaluation_id");
  $query
    ->condition("evaluation.gid", $gid)
    ->condition("node.type", "form_eval");
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $gid
 *   Group id.
 * @param $uid
 *   Author user id.
 * @return $nid
 *   Node id.
  */
function mkb_eval_get_eval_conflict($gid, $uid){
  $query = db_select("og_membership", "og_membership");
  $query ->leftJoin("node", "node", "node.nid = og_membership.etid");
  $query ->addField("node", "nid", "nid");
  $query
  ->condition("og_membership.gid", $gid)
  ->condition("og_membership.entity_type", 'node')
  ->condition("node.type", 'evaluation_conflict')
  ->condition("node.uid", $uid);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $funder_pages
 *   Funder-pages.
 * @return $nid
 *   All Application-partner-budget node ids that the funder-pages are using.
  */
function mkb_eval_get_partner_budgets($funder_pages){
  $query = db_select("field_data_field_funder_page", "field_funder_page");
  $query ->addField("field_funder_page", "entity_id", "nid");
  $query
    ->condition("field_funder_page.bundle", 'application_partner_budget')
    ->condition("field_funder_page.entity_type", 'node')
    ->condition("field_funder_page.field_funder_page_target_id", $funder_pages, 'IN');
  $query->distinct();
  $result = $query->execute()->fetchAll();

  if($result !== FALSE){
    $partner_budgets = array();
    foreach ($result as $row){
      if($row->nid !== NULL) $partner_budgets[] = $row->nid;
    }
    return $partner_budgets;
  }
  return $result;
}

/**
 * @param $nid
 *   funder_page node id.
 * @return $nid
 *   Call-funder-page manager uids of call where current user is call manager.
 */
function mkb_eval_get_uids_manager_funder_pages($nid){
  $query = db_select("field_data_field_call_managers", "field_call_managers");
  $query ->addField("field_call_managers", "field_call_managers_target_id", "uid");
  $query
    ->condition("field_call_managers.entity_id", $nid);
  $result = $query->execute()->fetchAll();

  if($result !== FALSE){
    $uids = array();
    foreach ($result as $row){
      if($row->uid !== NULL) $uids[] = $row->uid;
    }
    return $uids;
  }
  return $result;
}

/**
 * @param $nid
 *   funder_page node id.
 * @return $nid
 *   Call-funder-page evaluator uids of call where current user is evaluator.
  */
function mkb_eval_get_uids_evaluator_funder_pages($nid){
  $query = db_select("field_data_field_evaluators", "field_evaluators");
  $query ->addField("field_evaluators", "field_evaluators_target_id", "uid");
  $query
    ->condition("field_evaluators.entity_id", $nid);
  $result = $query->execute()->fetchAll();

  if($result !== FALSE){
    $uids = array();
    foreach ($result as $row){
      if($row->uid !== NULL) $uids[] = $row->uid;
    }
    return $uids;
  }
  return $result;
}

/**
 * @param $cid
 *   Call-main-page node id
 * @return $funder_agencies
 *   Funding agencies for this call.
  */
function mkb_eval_get_all_funding_agencies($cid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_funding_agency", "field_funding_agency", "field_funding_agency.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_short_name", "field_short_name", "field_short_name.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query ->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_short_name.entity_id");
  $query ->addField("field_call_id", "entity_id", "funder_page_nid");
  $query ->addField("field_short_name", "field_short_name_value", "short_name");
  $query ->addField("field_country", "field_country_iso2", "iso2");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_funding_agency.bundle", 'call_funder_page')
    ->condition("field_country.bundle", 'organisation');
  $query ->orderBy('field_country_iso2', 'ASC');
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    $funding_agencies = array();
    foreach ($result as $row){
      $funding_agencies[$row->funder_page_nid] = '<p class="eval_short_name">' . $row->short_name .
        '</p>' . $row->iso2;
    }
    return $funding_agencies;
  }
  return $result;
}

/**
 * @param $cid
 *   Call-main-page node id
 * @return $funder_agencies
 *   Funding agencies for this call.
  */
function mkb_eval_get_all_funding_agency_names($cid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_funding_agency", "field_funding_agency", "field_funding_agency.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_short_name", "field_short_name", "field_short_name.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query ->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_short_name.entity_id");
  $query ->addField("field_call_id", "entity_id", "funder_page_nid");
  $query ->addField("field_short_name", "field_short_name_value", "short_name");
  $query ->addField("field_country", "field_country_iso2", "iso2");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_funding_agency.bundle", 'call_funder_page')
    ->condition("field_country.bundle", 'organisation');
  $query ->orderBy('field_country_iso2', 'ASC');
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    $funding_agencies = array();
    foreach ($result as $row){
      $funding_agencies[$row->funder_page_nid] = $row->short_name;
    }
    return $funding_agencies;
  }
  return $result;
}

/**
 * @param $cid
 *   Call-main-page node id
 * @param $tid
 *   Call-topic nid
 * @return $deltantitle
 *   Call-topic delta and title
  */
function mkb_eval_get_topic_delta_n_title($cid, $tid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_topic_level", "field_topic_level", "field_topic_level.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_topic_weight", "field_topic_weight", "field_topic_weight.entity_id = field_call_id.entity_id");
  $query ->leftJoin("node", "node", "node.nid = field_call_id.entity_id");
  $query ->addField("node", "title", "title");
  $query ->addField("field_call_id", "entity_id", "tid");
  $query
    ->condition("field_call_id.bundle", 'call_topic')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_topic_level.field_topic_level_value", 1);
  $query ->orderBy('field_topic_weight_value', 'ASC');
  $result = $query->execute()->fetchAll();

  $delta = 0;
  $topic_title = '';
  foreach ($result as $i => $row){
    if($row->tid == $tid){
      $delta = $i;
      $topic_title = $row->title;
    }
  }
  return array('delta' => $delta, 'title' => $topic_title);
}

/**
 * field_topic_value = 1
 * weight peger på funder_page theme_field delta
 *
 *
 *
 * @param $cid
 *   Call-main-page node id
 * @param $tid
 *   Call-topic nid
 * @return $funder_agencies
 *   Funding agencies for this call that has funding for call_topic by delta.
  */
function mkb_eval_get_topic_funding_agencies($cid, $delta){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_fp_theme_funding", "field_fp_theme_funding", "field_fp_theme_funding.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_funding_agency", "field_funding_agency", "field_funding_agency.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_short_name", "field_short_name", "field_short_name.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query ->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_short_name.entity_id");
  $query ->addField("field_call_id", "entity_id", "funder_page_nid");
  $query ->addField("field_short_name", "field_short_name_value", "short_name");
  $query ->addField("field_country", "field_country_iso2", "iso2");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_fp_theme_funding.delta", $delta)
    ->condition("field_fp_theme_funding.field_fp_theme_funding_value", 0, '<>')
    ->condition("field_funding_agency.bundle", 'call_funder_page')
    ->condition("field_country.bundle", 'organisation');
  $query ->orderBy('field_country_iso2', 'ASC');
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    $funding_agencies = array();
    foreach ($result as $row){
      $funding_agencies[$row->funder_page_nid] = '<p class="eval_short_name">' . $row->short_name .
        '</p>' . $row->iso2;
    }
    return $funding_agencies;
  }
  return $result;
}

/**
 * @param $budget_nid
 *   Application-partner-budget node id.
 * @return $funder_pages
 *   Funder page.
 *
  */
function mkb_eval_get_funder_page($budget_id){
  $query = db_select("field_data_field_funder_page", "field_funder_page");
  $query ->addField("field_funder_page", "field_funder_page_target_id", "funder_page_nid");
  $query
    ->condition("field_funder_page.bundle", 'application_partner_budget')
    ->condition("field_funder_page.entity_type", 'node')
    ->condition("field_funder_page.entity_id", $budget_id);
  $query->distinct();
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $nid
 *   Call-funder-page nid.
 * @return $array
 *   Avaliable funding, EU funding and Extra funding.
  */
function mkb_eval_get_fa_fundings($nid){
  $query = db_select("field_data_field_funding", "funding");
  $query ->leftJoin("field_data_field_eu_funding", "eu_funding", "eu_funding.entity_id = funding.entity_id");
  $query ->leftJoin("field_data_field_extra_funding", "extra_funding", "extra_funding.entity_id = eu_funding.entity_id");
  $query ->addField("funding", "field_funding_value", "funding");
  $query ->addField("eu_funding", "field_eu_funding_value", "eu_funding");
  $query ->addField("extra_funding", "field_extra_funding_value", "extra_funding");
  $query
    ->condition("funding.bundle", 'call_funder_page')
    ->condition("funding.entity_type", 'node')
    ->condition("funding.entity_id", $nid);
  $result = $query->execute()->fetchAll();

  $fundings = array(
      'funding' => isset($result[0]->funding) ? $result[0]->funding : 0,
      'eu_funding' => isset($result[0]->eu_funding) ? $result[0]->eu_funding : 0,
      'extra_funding' => isset($result[0]->extra_funding) ? $result[0]->extra_funding : 0,
      );
  return $fundings;
}

/**
 * @param $nid
 *   Call-funder-page nid.
 * @return $avaliable_funding
 *   Avaliable funding.
  */
function mkb_eval_get_avaliable_funding($nid){
  $query = db_select("field_data_field_funding", "field_funding");
  $query ->addField("field_funding", "field_funding_value", "avaliable_funding");
  $query
    ->condition("field_funding.bundle", 'call_funder_page')
    ->condition("field_funding.entity_type", 'node')
    ->condition("field_funding.entity_id", $nid);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $nid
 *   Call-funder-page nid.
 * @param $topic_delta
 *   Topic delta.
 * @return $avaliable_funding
 *   Avaliable funding.
  */
function mkb_eval_get_topic_avaliable_funding($nid, $topic_delta){
  $query = db_select("field_data_field_fp_theme_funding", "field_fp_theme_funding");
  $query ->addField("field_fp_theme_funding", "field_fp_theme_funding_value", "avaliable_funding");
  $query
    ->condition("field_fp_theme_funding.bundle", 'call_funder_page')
    ->condition("field_fp_theme_funding.entity_type", 'node')
    ->condition("field_fp_theme_funding.entity_id", $nid)
    ->condition("field_fp_theme_funding.delta", $topic_delta);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state
 * @param $cid
 *   call-main-page node id
 * @param $eid
 *   Evaluation configuration node id
 * @param $fid
 *   Filter node id
 * @param $tid (optional)
 *   By topic: TRUE or FALSE
 * @return $form
 *   Form.
  */
function mkb_eval_selection_get_form($form, &$form_state, $cid, $eid, $fid, $tid = NULL){
  // Load Evaluation configuration node
  $eval_conf = node_load($eid);
  $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
  $eval_conf_stage = $eval_conf_wrapper->field_call_stage->value();
  $eval_conf_type = $eval_conf_wrapper->field_eval_conf_type->name->value();
  $eval_conf_score_calc = $eval_conf_wrapper->field_conf_score_calculation->value();

  // Load filter
  $filter = node_load($fid);
  $filter_wrapper = entity_metadata_wrapper('node', $filter);
  $filter_by_funder = $filter_wrapper->field_filter_partner_budget->value();
  
  // Get filtered groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid, $eid);

  // Determine stage
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $call_wrapper->field_current_stage->value();

  // Get all funding agencies for this call and this topic
  if(isset($tid)){
    $topic = mkb_eval_get_topic_delta_n_title($cid, $tid);
    $title = $topic['title'];
    $funding_agencies = mkb_eval_get_topic_funding_agencies($cid, $topic['delta']);

    // Unset all groups that doesnt have this topic selected
    foreach ($groups as $gid => $group){
      $has_topic = mkb_eval_has_topic($group->applications['application_project_info'], $tid);
      if($has_topic == FALSE){
        unset($groups[$gid]);
      }
    }
  }
  else{
    $title = 'Application selection for all topics';
    $funding_agencies = mkb_eval_get_all_funding_agencies($cid);
  }

  // Initiate groups content
  $content = array();
  foreach ($groups as $gid => $group){
    $content[$gid] = array(
        'gid' => $gid,
        'acronym' => mkb_eval_get_acronym($group->applications['application_project_info']),
        'rank' => 0,
        'score' => '-',
//         'select' => '',
//         'select' => array(
//           '#id' => '1',
//           '#type' => 'checkbox',
//           '#title' => t(''),
//           '#default_value' => 1, // Get default value
//             ),
//         'select' => '<input type="checkbox" name="selected_1" id="' . $group['application_project_info'] . '">',
        );
    foreach ($funding_agencies as $fid => $funding_agency){
      $content[$gid][$fid] = 0;
    }
    $content[$gid]['total'] = 0;
  }

  $default_value = array();
  $requested_arr = array();
  foreach ($groups as $gid => $group){
    // Checkboxes default values by project_info stage
    $project_info = node_load($group->applications['application_project_info']);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
    if($current_stage == 1){
      $selected = ($project_info_wrapper->field_app_selected_1->value()) ?
        $project_info_wrapper->field_app_selected_1->value() : FALSE;
      if($selected) $default_value[$project_info->nid] = $project_info->nid;
    }
    else{
      $selected = ($project_info_wrapper->field_app_selected_2->value()) ?
        $project_info_wrapper->field_app_selected_2->value() : FALSE;
      if($selected) $default_value[$project_info->nid] = $project_info->nid;
    }

    // Add funder_pages and requested to each group
    $groups[$gid]->funder_pages = array();
    if(isset($group->applications['application_partner_budget'])){
      foreach ($group->applications['application_partner_budget'] as $budget_id){
        // Check if partner_budget authors are project coordinator or project partner
        $author_og_roles = mkb_eval_get_author_og_roles($gid,$budget_id);
        if (isset($author_og_roles) && (in_array("project coordinator", $author_og_roles) || in_array("project partner", $author_og_roles))) {
          // Get budget requested for each application_partner_budget and add it to the funding agency col (fid)
          $fid = mkb_eval_get_funder_page($budget_id);
          $budget = mkb_application_get_budget_table($budget_id);

          $num_col = count($budget[10]);
          $requested = intval(round($budget[10][$num_col-1]));

          if(array_key_exists($fid, $funding_agencies)){
            $content[$gid][$fid] = $content[$gid][$fid] + $requested;
            // Add requested from each application to requested_arr for table header requested
            if(!isset($requested_arr[$fid])) $requested_arr[$fid] = 0;
            if($selected==1){
            $requested_arr[$fid] += $requested;
            }
          }
        }

        // Set groups funder_page
        if(!in_array($fid, $groups[$gid]->funder_pages)) {
          $groups[$gid]->funder_pages[] = $fid;
        }
      }
    }
  }

  // Group evaluation data
  foreach ($groups as $gid => $group){
    if($filter_by_funder == 1){
      // field_filter_partner_budget is checked in filter 
      foreach ($funding_agencies as $fid => $funding_agency){
        if(in_array($fid, $group->funder_pages)){
          // Get all user ids from funder_pages
          $funder_page_uids = array_merge(mkb_eval_get_uids_manager_funder_pages($fid),
              mkb_eval_get_uids_evaluator_funder_pages($fid));

          // Get evaluations of each group
          $evaluations = mkb_eval_get_all_evaluations($funder_page_uids, $eval_conf->nid, $gid);

          $score_sum = 0;
          foreach ($evaluations as $nid => $evaluation){
            $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);
            $score = $evaluation_wrapper->field_eval_score->value();
            $score_sum += isset($score) ? $score : 0;
          }
          
          // Calculate mean score
            $score_mean = (count($evaluations) == 0) ? $score_sum : $score_sum/count($evaluations);
          
          // Set score          
          $content[$gid]['score'] = number_format($score_mean,1);
        }
      }
    }
    else{
      // field_filter_partner_budget is NOT checked in filter 
      $evaluations = mkb_eval_get_evaluations($gid, array($eval_conf->nid => $eval_conf->nid));
      $score_sum = 0;
      foreach ($evaluations as $nid => $evaluation){
        $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);
        $score = $evaluation_wrapper->field_eval_score->value();
        $score_sum += isset($score) ? $score : 0;
      }
      // Calculate mean
        $score_mean = (count($evaluations) == 0) ? $score_sum : $score_sum/count($evaluations);
      // Set score          
      $content[$gid]['score'] = number_format($score_mean,1);
    }
  }

  // Calculate and add row totals
  foreach ($content as $gid => $row){
    $row_total = 0;
    foreach ($funding_agencies as $nid => $funding_agency){
        $row_total += $row[$nid];
    }
    $content[$gid]['total'] = $row_total;
  }

  // Sort by score
  field_sort($content,"score","desc");

  $i=0;
  foreach ($content as $gid => $row){
    $content[$gid]['rank'] = $i+1;
    $i++;
  }

  // Build header
  $header = array(
      0 => array(
        'label' => 'Funding agency',
      ),
      1 => array(
        'label' => 'Avaliable funding',
      ),
      2 => array(
        'label' => 'Requested funding',
      ),
      3 => array(
        'label' => 'Deficit',
      ),
    );
  $avaliabel_total = 0;
  $requested_total = 0;
  $deficit_total = 0;
  foreach ($funding_agencies as $nid => $funding_agency){
    if(isset($tid)){
      $avaliable_funding = mkb_eval_get_topic_avaliable_funding($nid, $topic['delta']);
    }
    else{
      $avaliable_funding = mkb_eval_get_avaliable_funding($nid);
      if(!$avaliable_funding) $avaliable_funding = 0;
    }
    // Each funding agency
    if(isset($requested_arr[$nid])){
       $requested = (int)$requested_arr[$nid];
    }
    else{
      $requested = 0;
    }
    $header[0][$nid] = $funding_agency;
    $header[1][$nid] = $avaliable_funding;
    $header[2][$nid] = $requested;
    $header[3][$nid] = (int)$avaliable_funding-$requested;
    // Totals
    $avaliabel_total += $avaliable_funding;
    $requested_total += $requested;
    $deficit = (int)$avaliable_funding-$requested;
    //if($deficit<0) $deficit_total += $deficit;
    $deficit_total += $deficit;
  }
  // Add total label (right top)
  $header[0]['total'] = 'Total';
  $header[1]['total'] = $avaliabel_total;
  $header[2]['total'] = $requested_total;
  $header[3]['total'] = $deficit_total;

  // Application labels
  $header[4] = array('Select', 'Id', 'Acronym', 'Rank', 'Score', 'Requested funding');

  // Build form
  foreach ($header as $i => $row){
    foreach ($row as $j => $field){
      $form['header'][$i][$j] = array(
          '#type' => 'hidden',
          '#value' => $field,
          );
    }
  }

  // Form index by project-info node id
  foreach ($content as $gid => $row){
    $project_info_nid = $groups[$gid]->applications['application_project_info'];
    $checkboxes[$project_info_nid] = '';
    foreach ($row as $index => $field){
      $form[$project_info_nid][$index] = array(
          '#markup' => $field,
          );
    }
  }

  $form['checkboxes'] = array(
    '#type' => 'checkboxes',
    '#options' => $checkboxes,
    '#default_value' => $default_value,
    '#attributes' => array(
        'onchange' => "Totals();"),
  );

  //Topics - Add js
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'mkb_eval') . '/js/application_select.js');

  $form['#theme'] = array('mkb_eval_application_selection_form_table');

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save selection'),
  );
  return $form;
}

/**
 * @param $uids (optional)
 *   User ids
 * @param $eval_conf_nid
 *   Evaluation configuration node id
 * @param $gid
 *   Group node id
 * @return $evaluation
 *   Evaluation node
  */
function mkb_eval_get_all_evaluations($uids = NULL, $eval_conf_nid, $gid){
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nid, '=')
    ->fieldCondition('og_group_ref', 'target_id', $gid, '=');

  if(isset($uids)) $query->propertyCondition('uid', $uids, 'IN');

  $result = $query->execute();

  $evaluations = array();
  if (isset($result['node'])) {
    $evaluation_nids = array_keys($result['node']);
    $evaluations = entity_load('node', $evaluation_nids);
  }
  return $evaluations;
}

/**
 * @param $node_type
 *   Node type
 * @return $nid
 *   Node id.
  */
function mkb_eval_get_node_type($type){
  $query = db_select("node", "n");
  $query ->addField("n", "nid", "eid");
  $query
    ->condition("n.type", $type)
    ->condition("n.status", 1);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $nid
 *   Node id
 * @return Array of author's og roles for node author
  */
function mkb_eval_get_author_og_roles($gid,$nid){
  $query = db_select("node", "node");
  $query ->leftJoin("og_users_roles", "og_users_roles", "og_users_roles.uid = node.uid");
  $query ->leftJoin("og_role", "og_role", "og_users_roles.rid = og_role.rid");
  $query ->addField("og_role", "name", "og_role");
  $query
    ->condition("node.nid", $nid)
    ->condition("og_users_roles.gid", $gid);
  $result = $query->execute()->fetchAll();
  $og_roles = Array();
  foreach ($result as $row) {
    array_push($og_roles, $row->og_role);
  }
  return $og_roles;
}

/**
* Modification of theme_tableselect
*/
function mkb_eval_tableselect($variables) {
  $element = $variables['element'];
  $rows = array();
  $header = $element['#header'];
  if (!empty($element['#options'])) {
    // Generate a table row for each selectable item in #options.
    foreach (element_children($element) as $key) {
      $row = array();

      $row['data'] = array();
      if (isset($element['#options'][$key]['#attributes'])) {
        $row += $element['#options'][$key]['#attributes'];
      }
      // Render the checkbox / radio element.
      $row['data'][] = drupal_render($element[$key]);

      // As theme_table only maps header and row columns by order, create the
      // correct order by iterating over the header fields.
      foreach ($element['#header'] as $fieldname => $title) {
        $row['data'][] = $element['#options'][$key][$fieldname];
      }
      $rows[] = $row;
    }
    // Add an empty header or a "Select all" checkbox to provide room for the
    // checkboxes/radios in the first table column.
    if ($element['#js_select']) {
      // Add a "Select all" checkbox.
      drupal_add_js('misc/tableselect.js');
      array_unshift($header, array('class' => array('select-all')));
    }
    else {
      // Add an empty header when radio buttons are displayed or a "Select all"
      // checkbox is not desired.
      array_unshift($header, '');
    }
  }
  return theme('table', array('header' => $header, 'rows' => $rows, 'empty' => $element['#empty'], 'attributes' => $element['#attributes']));
}

/**
* Modification of theme_table
*/
function mkb_eval_table($variables) {
  $header = $variables['header'];
  $rows = $variables['rows'];
  $attributes = $variables['attributes'];
  $caption = $variables['caption'];
  $colgroups = $variables['colgroups'];
  $sticky = $variables['sticky'];
  $empty = $variables['empty'];
  $rows_multiple = $variables['rows_multiple'];

  // Add sticky headers, if applicable.
  if (count($header)) {
    drupal_add_js('sites/all/modules/mkb_eval/js/mkb_tableheader.js');
//     drupal_add_js('misc/tableheader.js');
    // Add 'sticky-enabled' class to the table to identify it for JS.
    // This is needed to target tables constructed by this function.
    //$attributes['class'] = empty($attributes['class']) ? 'sticky-enabled' : ($attributes['class'] .' sticky-enabled');
  }
  $output = '<table'. drupal_attributes($attributes) .">\n";
  if (isset($caption)) {
    $output .= '<caption>'. $caption ."</caption>\n";
  }
    // Multiple header rows
    if(!$rows_multiple == NULL){
      $thead_set = '';
      // Format the table header:
      if (count($header)) {
          foreach($header as $number => $head){
            $ts = tablesort_init($head);
            // HTML requires that the thead tag has tr tags in it followed by tbody
            // tags. Using if clause to check and see if we have any rows and whether
            // the thead tag is already open
            if(count($rows) && $thead_set != 1){
                $output .= ' <thead><tr>';
                $thead_set = 1;
            }else{
                $output .= ' <tr>';
            }
            //$output .= (count($rows) ? ' <thead><tr>' : ' <tr>');
            foreach ($head as $cell) {
              $cell = tablesort_header($cell, $head, $ts);
              $output .= _theme_table_cell($cell, TRUE);
            }
        }
            // Using ternary operator to close the tags based on whether or not there are rows
            $output .= (count($rows) ? " </tr></thead>\n" : "</tr>\n");
      }
      else {
        $ts = array();
      }
    // One header row
    }else{
         // Format the table header:
      if (count($header)) {
        $ts = tablesort_init($header);
        // HTML requires that the thead tag has tr tags in it followed by tbody
        // tags. Using ternary operator to check and see if we have any rows.
        $output .= (count($rows) ? ' <thead><tr>' : ' <tr>');
        foreach ($header as $cell) {
          $cell = tablesort_header($cell, $header, $ts);
          $output .= _theme_table_cell($cell, TRUE);
        }
        // Using ternary operator to close the tags based on whether or not there are rows
        $output .= (count($rows) ? " </tr></thead>\n" : "</tr>\n");
      }
      else {
        $ts = array();
      }
    }
  // Format the table rows:
  if (count($rows)) {
    $output .= "<tbody>\n";
    $flip = array('even' => 'odd', 'odd' => 'even');
    $class = 'even';
    foreach ($rows as $number => $row) {
      $attributes = array();
      $attributes['class'] = '';
      // Check if we're dealing with a simple or complex row
      if (isset($row['data'])) {
        foreach ($row as $key => $value) {
          if ($key == 'data') {
            $cells = $value;
          }
          elseif ($key !== 'class') {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $cells = $row;
      }
      if (count($cells)) {
        // Add odd/even class
        $class = $flip[$class];
        if (isset($attributes['class'])) {
          $attributes['class'] .= ' '. $class;
        }
        else {
          $attributes['class'] = $class;
        }
        // Build row
        $output .= ' <tr'. drupal_attributes($attributes) .'>';
        $i = 0;
        foreach ($cells as $cell) {
          $cell = tablesort_cell($cell, $header, $ts, $i++);
          $output .= _theme_table_cell($cell);
        }
        $output .= " </tr>\n";
      }
    }
    $output .= "</tbody>\n";
  }
  $output .= "</table>\n";
  return $output;
}

/**
 * Even though this function operates on mulitiple evaluations the last else statement is working as if
 * there where only one evaluation.
 *
 * @param $groups (note &)
 *   Group nodes
 * @param $term_name
 *   Evaluation type term name
  */
function mkb_eval_filter_applications(&$groups, $term_name){
  // Get term ID by term_name in evaluation type vocabulary
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
  ->entityCondition('bundle', array('evaluation_type'))
  ->propertyCondition('name', $term_name)
  ->propertyOrderBy('weight');
  $result = $query->execute();
  $tids = array_keys($result['taxonomy_term']);
  $tid = isset($tids[0]) ? $tids[0] : 0;

  // Get eval_conf which has tid as evaluation type
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation_conf')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_eval_conf_type', 'target_id', $tid, '=');
  $result = $query->execute();

  // If Evaluation configuration is found
  if (isset($result['node'])) {
    $eval_conf_nids = array_keys($result['node']);
    $eval_conf = node_load($eval_conf_nids[0]);

    // Find evaluations and check if they are approved
    foreach ($groups as $gid => $group){
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'evaluation')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_eval_conf', 'target_id', $eval_conf->nid, '=')
        ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
      $result = $query->execute();

      if (isset($result['node'])) {
        $eval_nids = array_keys($result['node']);
        $eval = node_load($eval_nids[0]);
        $eval_wrapper = entity_metadata_wrapper('node', $eval);
        $recommendation = $eval_wrapper->field_eval_recommendation->value();

        // Remove application if evaluation is not approved (recommendation = 0)
        if($recommendation == 2){
          unset($groups[$gid]);
        }
      }
      else{
        unset($groups[$gid]);
      }
    }
  }
}

/**
 * This function is for mkb_eval.evaluation.inc and is used with the overviews of evalautions
 *
 * @param $groups (note &)
 *   Group nodes
 * @param $content (note &)
 *   Content from mkb_eval.evaluation.inc
 * @param $term_name
 *   Evaluation type term name
  */
function mkb_eval_filter_eval_applications(&$groups, &$content, $term_name){
  // Get term ID by term_name in evaluation type vocabulary
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
  ->entityCondition('bundle', array('evaluation_type'))
  ->propertyCondition('name', $term_name)
  ->propertyOrderBy('weight');
  $result = $query->execute();
  $tids = array_keys($result['taxonomy_term']);
  $tid = isset($tids[0]) ? $tids[0] : 0;

  // Get eval_conf which has tid as evaluation type
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation_conf')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_eval_conf_type', 'target_id', $tid, '=');
  $result = $query->execute();

  // If Evaluation configuration is found
  if (isset($result['node'])) {
    $eval_conf_nids = array_keys($result['node']);
    $eval_conf = node_load($eval_conf_nids[0]);

    // Find evaluations and check if they are approved
    foreach ($groups as $gid => $group){
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'evaluation')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_eval_conf', 'target_id', $eval_conf->nid, '=')
        ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
      $result = $query->execute();

      if (isset($result['node'])) {
        $eval_nids = array_keys($result['node']);
        $eval = node_load($eval_nids[0]);
        $eval_wrapper = entity_metadata_wrapper('node', $eval);
        $recommendation = $eval_wrapper->field_eval_recommendation->value();

        // Remove application if evaluation is not approved (recommendation = 0)
        if($recommendation == 2){
          unset($groups[$gid]);
          unset($content[$gid]);
        }
      }
      else{
        unset($groups[$gid]);
        unset($content[$gid]);
      }
    }
  }
}

/**
 * This function is used for most overviews to load groups
 * with a filter.
 *
 * eid is used with expert evaluators/evaluations
 *
 * @param $cid
 *   call-main-page node id
 * @param $fid
 *   Filter node id
 * @param $eid (optional)
 *   Evaluation configuration node id
  */
function mkb_eval_get_filtered_groups($cid, $fid, $eid = NULL, $tid = NULL){
  // Load current user
  $account = $GLOBALS['user'];

  // Load filter node
  $filter_node = node_load($fid);
  $fields_info = field_info_instances('node', $filter_node->type);

  // Build filter with values from filter node
  $filter = array();
  foreach ($fields_info as $field_name => $field_info){
    // Field values
    $field_items = field_get_items('node', $filter_node, $field_name);
    if(!empty($field_items)){
      foreach ($field_items as $field_item){
        $filter[$field_name][] = $field_item['value'];
      }
    }
  }

  // Load evaluation configuration node and term type (eg. "formality")
  $stage = 1;
  if(isset($eid)){
    $eval_conf = node_load($eid);
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
    $eval_conf_type_term = $eval_conf_wrapper->field_eval_conf_type->value();
    $stage =  $eval_conf_wrapper->field_call_stage->value();
  }

  // Load all evaluation configuration types and key by type and nid
  // eg. eval_confs['Formality][13284][stdclass]
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  //$call_stage = $call_wrapper->field_current_stage->value();

  $query = db_select("node", "n");
  $query ->leftJoin("field_data_field_call_id", "field_call_id", "field_call_id.entity_id = n.nid");  
  $query ->leftJoin("field_data_field_call_stage", "field_call_stage", "field_call_stage.entity_id = n.nid");    
  $query ->addField("n", "nid", "nid");
  $query
    ->condition("n.type", 'evaluation_conf')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.bundle", 'evaluation_conf')    
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_call_stage.entity_type", 'node')
    ->condition("field_call_stage.bundle", 'evaluation_conf')    
    ->condition("field_call_stage.field_call_stage_value", $stage);
  $result = $query->execute()->fetchAll();
  
  $eval_confs = array();  
  if($result !== FALSE){
    foreach ($result as $row){
      $eval_conf = node_load($row->nid);
      $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
      $type = $eval_conf_wrapper->field_eval_conf_type->value();
      $eval_confs[$type->name][] = $eval_conf;
    }
  }

  // Get all groups for this call
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'group')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_group_application', 'target_id', $cid, '=')
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
  $result = $query->execute();

  $groups = array();
  if (isset($result['node'])) {
    $group_nids = array_keys($result['node']);
    $groups = entity_load('node', $group_nids);
  }

  // Load data for filters if enabled
  if(in_array(1, $filter['field_filter_partner_budget'])){
    // Get funder pages current user is "call manager" or "contact person" for
    $funder_pages = array_merge(mkb_eval_get_manager_funder_pages($cid, $account->uid),
                                mkb_eval_get_evaluator_funder_pages($cid, $account->uid));
    $funder_pages = array_unique($funder_pages);
    $funder_pages = array_values($funder_pages);
    // Get partner budgets
    if($funder_pages) $partner_budgets = mkb_eval_get_partner_budgets($funder_pages);
  }

  // Run through filter and set unset group accordingly
  foreach ($groups as $gid => $group){
    // Build applications array with node ids from application types
    $aids = mkb_eval_get_aids($gid);

    $applications = array(
        'application_project_info' => FALSE,
        'application_partner_info' => array(),
        'application_partner_budget' => array(),
        );
    foreach ($aids as $aid){
      if($aid->type == 'application_project_info') $applications['application_project_info'] = $aid->aid;
      if($aid->type == 'application_partner_info') $applications['application_partner_info'][] = $aid->aid;
      if($aid->type == 'application_partner_budget') $applications['application_partner_budget'][] = $aid->aid;
    }

    // Remove all groups that doesn´t have a project-info
    if(!$applications['application_project_info']){
      unset($groups[$gid]);
      continue;
    }

    // Load project info to check against filter
    $project_info = node_load($applications['application_project_info']);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);

    //  Submit 1
    if(in_array(1, $filter['field_filter_submit_1_en'])){
      if(!in_array($project_info_wrapper->field_app_submitted->value(), $filter['field_filter_submit_1'])){
        unset($groups[$gid]);
        continue;
      }
    }

    //  Submit 2
    if(in_array(1, $filter['field_filter_submit_2_en'])){
      if(!in_array($project_info_wrapper->field_app_submitted_2->value(), $filter['field_filter_submit_2'])){
        unset($groups[$gid]);
        continue;
      }
    }

    //  Select 1
    if(in_array(1, $filter['field_filter_select_1_en'])){
      if(!in_array($project_info_wrapper->field_app_selected_1->value(), $filter['field_filter_select_1'])){
        unset($groups[$gid]);
        continue;
      }
    }

    //  Select 2
    if(in_array(1, $filter['field_filter_select_2_en'])){
      if(!in_array($project_info_wrapper->field_app_selected_2->value(), $filter['field_filter_select_2'])){
        unset($groups[$gid]);
        continue;
      }
    }

    // Formality check
    if(in_array(1, $filter['field_filter_formality_en'])){
      if(isset($eval_confs['Formality'][0])){
        // If Pending (0) i checked in filter we do not unset any groups
        if(!in_array(0, $filter['field_filter_formality'])){
          // Get eval_conf
          $eval_conf = $eval_confs['Formality'][0];
          // Load evaluations
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'evaluation')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_eval_conf', 'target_id', $eval_conf->nid, '=')
        ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
      $result = $query->execute();

      // Evaluation(s) exist
      if(isset($result['node'])) {
            $eval_nids = array_keys($result['node']);
            $evals = entity_load('node', $eval_nids);

            $f_unset = FALSE;
            foreach ($evals as $nid => $eval){
              $eval_wrapper = entity_metadata_wrapper('node', $eval);
              $recommendation = $eval_wrapper->field_eval_recommendation->value();
              $status = $eval_wrapper->field_eval_submit->value();

              // Filter values are calculateed as: 10*status+recommendation
              $filter_value = 10*$status+$recommendation;
              if(!in_array($filter_value, $filter['field_filter_formality'])) $f_unset = TRUE;
            }

            // Remove application if one of the evaluations do not match the filter
            if($f_unset){
              unset($groups[$gid]);
              continue;
            }
          }
          // Evaluation(s) does not exist.
          else{
            unset($groups[$gid]);
            continue;
          }
        }
      }
    }

    // Eligibility check
    if(in_array(1, $filter['field_filter_eligibility_en'])){
      if(isset($eval_confs['Eligibility'][0])){
        // If Pending (0) i checked in filter we do not unset any groups
        if(!in_array(0, $filter['field_filter_eligibility'])){
          // Get eval_conf
          $eval_conf = $eval_confs['Eligibility'][0];

          // Load evaluations
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'evaluation')
            ->propertyCondition('status', NODE_PUBLISHED)
            ->fieldCondition('field_eval_conf', 'target_id', $eval_conf->nid, '=')
            ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
          $result = $query->execute();

          // Evaluation(s) exist
          if (isset($result['node'])) {

            $eval_nids = array_keys($result['node']);
            $evals = entity_load('node', $eval_nids);

            $f_unset = FALSE;
            foreach ($evals as $nid => $eval){
              $eval_wrapper = entity_metadata_wrapper('node', $eval);
              $recommendation = $eval_wrapper->field_eval_recommendation->value();
              $status = $eval_wrapper->field_eval_submit->value();

              // Filter values are calculateed as: 10*status+recommendation
              $filter_value = 10*$status+$recommendation;
              if(!in_array($filter_value, $filter['field_filter_eligibility'])) $f_unset = TRUE;
            }

            // Remove application if one of the evaluations do not match the filter
            if($f_unset){
              unset($groups[$gid]);
              continue;
            }
          }
          // Evaluation(s) does not exist.
          else{
            unset($groups[$gid]);
            continue;
          }
        }
      }
    }

    // Quality check
    if(in_array(1, $filter['field_filter_quality_en'])){
      if(isset($eval_confs['Quality'][0])){
        // If Pending (0) i checked in filter we do not unset any groups
        if(!in_array(0, $filter['field_filter_quality'])){
          // Get eval_conf
          $eval_conf = $eval_confs['Quality'][0];

          // Load evaluations
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'evaluation')
            ->propertyCondition('status', NODE_PUBLISHED)
            ->fieldCondition('field_eval_conf', 'target_id', $eval_conf->nid, '=')
            ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
          $result = $query->execute();

          // Evaluation(s) exist
          if (isset($result['node'])) {

            $eval_nids = array_keys($result['node']);
            $evals = entity_load('node', $eval_nids);

            $f_unset = FALSE;
            foreach ($evals as $nid => $eval){
              $eval_wrapper = entity_metadata_wrapper('node', $eval);
              $recommendation = $eval_wrapper->field_eval_recommendation->value();
              $status = $eval_wrapper->field_eval_submit->value();

              // Filter values are calculateed as: 10*status+recommendation
              $filter_value = 10*$status+$recommendation;
              if(!in_array($filter_value, $filter['field_filter_quality'])) $f_unset = TRUE;
            }

            // Remove application if one of the evaluations do not match the filter
            if($f_unset){
              unset($groups[$gid]);
              continue;
            }
          }
          // Evaluation(s) does not exist.
          else{
            unset($groups[$gid]);
            continue;
          }
        }
      }
    }

    // Show only the groups this expert evaluator is assigned to
    if(in_array(1, $filter['field_filter_expert_assigned'])){
      if(isset($eid)){
        // Get expert evaluators for this group
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'expert_evaluators')
          ->propertyCondition('status', NODE_PUBLISHED)
          ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
          ->fieldCondition('field_eval_conf', 'target_id', $eid, '=');
        $result = $query->execute();

        $unset = TRUE;
        if (isset($result['node'])) {
          $expert_evaluators_nids = array_keys($result['node']);
          $expert_evaluator = node_load($expert_evaluators_nids[0]);
          $expert_evaluator_wrapper = entity_metadata_wrapper('node', $expert_evaluator);

          foreach ($expert_evaluator_wrapper->field_expert_application_id->getIterator() as $delta => $application_expert_wrapper) {
            $evaluator_uid = $application_expert_wrapper->field_expert_usr->raw();
            if($account->uid == $evaluator_uid) $unset = FALSE;
          }
        }
        if($unset){
          unset($groups[$gid]);
          continue;
        }
      }
      else{
        drupal_set_message('Experts assigned is checked but eid not given as argument', 'warning');
      }
    }

    // Funding agency in partner budget:
    // Current user is 'call manager' in funding agency used in this groups partner budget as funding agency.
    if(in_array(1, $filter['field_filter_partner_budget'])){
      if(isset($applications['application_partner_budget']) && isset($partner_budgets)){
        $unset = TRUE;
        foreach ($applications['application_partner_budget'] as $budget_nid){
          if(in_array($budget_nid, $partner_budgets)){
            $unset = FALSE;
          }
        }
        if($unset){
          unset($groups[$gid]);
          continue;
        }
      }
      else{
        unset($groups[$gid]);
        continue;
      }
    }

    // By topic
    if(in_array(1, $filter['field_filter_topic'])){
      $has_topic = mkb_eval_has_topic($applications['application_project_info'], $tid);
      if($has_topic == FALSE){
        unset($groups[$gid]);
        continue;
      }
    }

    // Add data to group if it is passing filters
    // Add applications
    $groups[$gid]->applications = $applications;

    // Add evaluations
    if(isset($eid)){
      // Add evaluation configuration node to group
      $groups[$gid]->eval_conf = $eval_conf;

      if($eval_conf_type_term->name == 'Formality'){
        $evaluation = mkb_eval_get_evaluation(NULL, $eid, $gid);
      }
      elseif($eval_conf_type_term->name == 'Eligibility' || $eval_conf_type_term->name == 'Quality'){
        $funder_pages = array();
        $funder_pages = array_merge(mkb_eval_get_manager_funder_pages($cid, $account->uid),
            mkb_eval_get_evaluator_funder_pages($cid, $account->uid));
        $funder_pages = array_unique($funder_pages);
        $funder_pages = array_values($funder_pages);

        if(!empty($funder_pages)){
          $funder_page_uids = array();
          $funder_page_uids = array_merge(mkb_eval_get_uids_manager_funder_pages($funder_pages[0]),
              mkb_eval_get_uids_evaluator_funder_pages($funder_pages[0]));
        }
        $evaluation = mkb_eval_get_evaluation($funder_page_uids, $eid, $gid);
      }
      elseif($eval_conf_type_term->name == 'Expert' || $eval_conf_type_term->name == 'Rapporteur'){
        // Get expert evaluators for this group
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'expert_evaluators')
          ->propertyCondition('status', NODE_PUBLISHED)
          ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
          ->fieldCondition('field_eval_conf', 'target_id', $eid, '=');
        $result = $query->execute();

        $unset = TRUE;
        if (isset($result['node'])) {
          $expert_evaluators_nids = array_keys($result['node']);
          $expert_evaluator = node_load($expert_evaluators_nids[0]);
          $expert_evaluator_wrapper = entity_metadata_wrapper('node', $expert_evaluator);

          foreach ($expert_evaluator_wrapper->field_expert_application_id->getIterator() as $delta => $application_expert_wrapper) {
            $evaluator_uid = $application_expert_wrapper->field_expert_usr->raw();
            if($account->uid == $evaluator_uid){
              $evaluation = mkb_eval_get_evaluation(array($account->uid), $eid, $gid);
            }
          }
        }
      }
      else{
        $evaluation = new stdClass();
      }
      $evaluation_arr = (array) $evaluation;
      if(!empty($evaluation_arr)) $groups[$gid]->evaluation = $evaluation;
    }
  }

  return $groups;
}


/**
 * @param $uids (optional)
 *   User ids
 * @param $eval_conf_nid
 *   Evaluation configuration node id
 * @param $gid
 *   Group node id
 * @return $evaluation
 *   Evaluation node
  */
function mkb_eval_get_evaluation($uids = NULL, $eval_conf_nid, $gid){
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nid, '=')
    ->fieldCondition('og_group_ref', 'target_id', $gid, '=');

  if(isset($uids)) $query->propertyCondition('uid', $uids, 'IN');

  $result = $query->execute();

  $evaluation = new stdClass();
  if (isset($result['node'])) {
    $evaluation_nids = array_keys($result['node']);
    $evaluation = node_load($evaluation_nids[0]);
  }
  return $evaluation;
}

/**
 * @param $gid
 *   Group node id
 * @param $eval_confs (optional)
 *   Evaluation configuration nodes
 * @return $evaluations
 *   Evaluation nodes
  */
function mkb_eval_get_evaluations($gid, $eval_confs = array()){
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'evaluation')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
  if(!empty($eval_confs)) {
    $eval_confs_nids = array_keys($eval_confs);
    $query->fieldCondition('field_eval_conf', 'target_id', $eval_confs_nids, 'IN');
  }

  $result = $query->execute();
  
  $evaluations = array();
  if (isset($result['node'])) {
    $evaluation_nids = array_keys($result['node']);
    $evaluations = entity_load('node', $evaluation_nids);
  }
  return $evaluations;
}

/**
 * @param $evaluation
 *   Evaluation
 * @return $value
 *   Evaluation recommendation text value
  */
function mkb_eval_get_recommendation_value($evaluation){
  $field_items = field_get_items('node', $evaluation, 'field_eval_recommendation');
  $recommendation = field_view_value('node', $evaluation, 'field_eval_recommendation', $field_items[0]);
  $value = isset($recommendation['#markup']) ? $recommendation['#markup'] : '';
  return $value;
}

/**
 * @param $groups
 *   Groups
 * @param $eval_confs
 *   Evaluation configuration nodes
 * @return $eval_conf_info
 *   Evaluation configurations info with questions and options as text
  */
function mkb_eval_get_conf_info($eval_confs){
  $eval_conf_info = array();
  foreach ($eval_confs as $nid => $eval_conf){
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
    $eval_conf_type_term = $eval_conf_wrapper->field_eval_conf_type->value();
    // Type
    $eval_conf_info[$nid]['type'] = $eval_conf_type_term->name;

    // Questions
    $field_items = field_get_items('node', $eval_conf, 'field_conf_questions');
    if(!empty($field_items)){
      foreach ($field_items as $i => $field_item){
        $field_value = field_view_value('node', $eval_conf, 'field_conf_questions', $field_items[$i]);
        $eval_conf_info[$nid]['questions'][$i] = $field_value['#markup'];
      }
    }

    // Options
    $field_items = field_get_items('node', $eval_conf, 'field_conf_options');
    if(!empty($field_items)){
      foreach ($field_items as $i => $field_item){
        $field_value = field_view_value('node', $eval_conf, 'field_conf_options', $field_items[$i]);
        $eval_conf_info[$nid]['options'][$i] = $field_value['#markup'];
      }
    }
  }
  return $eval_conf_info;
}

/**
 * Get evaluations from groups and evalution configurations to diplay multiple evaluations
 *
 * @param $groups
 *   Groups
 * @param $eval_confs
 *   Evaluation configuration nodes
 * @param $options
 *   Set options to true to include in display:
 *   Project-info acronym
 *   Evaluation type
 *   Evaluation author realname
 *   Topic: Organise return content by topic or not
 * @return $content
 *   Evaluations
  */
function mkb_eval_get_evaluation_view($groups, $eval_confs, $options = array()){
  // Set options
  $display_acronym = $options['acronym'];
  $display_eval_type = $options['eval_type'];
  $display_eval_author = $options['eval_author'];
  $by_topic = $options['topic'];

  // Get all topics
  if($by_topic){
    $topics = mkb_eval_get_all_topics();
  }

  // Load evaluation configuration info once
  $eval_confs_info = mkb_eval_get_conf_info($eval_confs);

  // Build content
  $content = array();
  foreach ($groups as $gid => $group){
    // Get project info
    $project_info_nid = mkb_eval_get_aid($gid, 'application_project_info');
    $project_info_node = node_load($project_info_nid);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info_node);

    // Get project info topic if options is set for topic
    if($by_topic) $project_info_topic = $project_info_wrapper->field_app_topics[0]->value();

    // Get evaluations
    $evaluations = mkb_eval_get_evaluations($gid, $eval_confs);

    $group_evaluations = array();
    $weight = 0;
    if(!empty($evaluations)){
      foreach ($evaluations as $nid => $evaluation){
        $evaluation_view = node_view($evaluation);
        $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);
        $eval_conf = $eval_confs[$evaluation_wrapper->field_eval_conf->raw()];
        $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
        $eval_conf_type = $eval_confs_info[$eval_conf->nid]['type'];

        // Initiate content_row
        $content_row = array();

        // Status
        $eval_submit = $evaluation_wrapper->field_eval_submit->value();
        $status = ($eval_submit == 0) ? 'Incomplete' : 'Complete';
        $content_row['status'] = array(
            '#markup' => '<b>Status:</b> ' . $status . '</br>',
            '#access' => TRUE,
            '#weight' => $weight++,
            );

        // Project info acronym
        if($display_acronym){
          $acronym = $project_info_wrapper->field_app_acronym->value();
          $acronym_text = isset($acronym) ? $acronym : '';

          $content_row['acronym'] = array(
              '#markup' => '<b>Application:</b> ' . $acronym_text . '</br>',
              '#access' => TRUE,
              '#weight' => $weight++,
              );
        }

        // Evaluator
        if($display_eval_author){
          $eval_author = user_load($evaluation->uid);
          $content_row['realname'] = array(
              '#markup' => '<b>Evaluator:</b> ' . $eval_author->realname . '</br>',
              '#access' => TRUE,
              '#weight' => $weight++,
              );
        }

        foreach (element_children($evaluation_view) as $field_name){
          if($field_name == 'field_eval_conf' && $display_eval_type){
            $content_row['type'] = array(
              '#markup' => '<b>Evaluation type:</b> ' . $eval_conf_wrapper->label() . '</br>',
              '#access' => TRUE,
              '#weight' => $weight++,
              );
          }
          if($field_name == 'field_eval_answers'){
            // Questionnaire
            $header = array('Questions', 'Answers');
            $rows = array();

            $questions = $eval_confs_info[$eval_conf->nid]['questions'];
            $options = $eval_confs_info[$eval_conf->nid]['options'];
            foreach ($evaluation_wrapper->field_eval_answers as $i => $answer) {
              // Question
              $question = $questions[$i];
              $rows[$i][0] = $question;
              // Answer
              $answer = $options[$answer->value()];
              $rows[$i][1] = $answer;
            }

            // Table
            $table = array(
                'header' => $header,
                'rows' => $rows,
                'attributes' => array(
                    'class' => array('table_class'),
                    'width' => '50%',
                    ),
                'sticky' => FALSE,
                'empty' => 'No questions.',
                'colgroups' => array(),
                'caption' => '',
                );

            // Add table to content
            $content_row['questionnaire'] = array(
              '#markup' => theme_table($table),
              '#access' => TRUE,
              '#weight' => $weight++,
              );
          }
          if($field_name == 'field_eval_score'){
            $content_row['score'] = $evaluation_view[$field_name];
            $content_row['score']['#weight'] = $weight++;
          }
          if($field_name == 'field_eval_recommendation'){
            $recommendation = mkb_eval_get_recommendation_value($evaluation);
            $content_row['recommendation'] = $evaluation_view[$field_name];
            $content_row['recommendation']['#weight'] = $weight++;
          }
          if($field_name == 'field_eval_radio'){
            // Get radio titles from eval conf
            $titles = array();
            $new_field = $evaluation_view[$field_name];
            foreach ($eval_conf_wrapper->field_conf_radio->getIterator() as $delta => $radio_wrapper) {
              $radio_text = $radio_wrapper->value();
              $subs = explode('#', $radio_text);
              $titles[$delta] = $subs[0];
            }

            $field_items = field_get_items('node', $evaluation, $field_name, $langcode = NULL);
            $i = 0;
    //         $weight = $evaluation_view[$field_name]['#weight'];
            foreach ($field_items as $item){
              $answer = ($item['value'] == 1) ? 'Yes' : 'No';

              // Create items array with answer
              $new_item = array(
                  'value' => $answer,
                  'format' => NULL,
                  'safe_value' => $answer,
                  );
              $new_field_name = $field_name . '_' . $i;
              $field_view = mkb_eval_get_default_field_view($weight++, $titles[$i], 'inline', $new_field_name, 'text', $new_item, $answer);
              $content_row[$field_name . '_' . $i] = $field_view;
              $i++;
            }
          }
          if($field_name == 'field_eval_text_area'){
            // Get text area titles from eval conf
            $titles = array();
            $new_field = $evaluation_view[$field_name];
            foreach ($eval_conf_wrapper->field_conf_text_areas->getIterator() as $delta => $text_area_wrapper) {
              $text_area_text = $text_area_wrapper->value();
              $subs = explode('#', $text_area_text);
              $titles[$delta] = $subs[0];
            }
            // Create new field array and add it to content
            $field_items = field_get_items('node', $evaluation, $field_name, $langcode = NULL);
            $i = 0;
    //         $weight = $evaluation_view[$field_name]['#weight'];
            foreach ($field_items as $item){
              // Get sanitized text
              $text_area_value = field_view_value('node', $evaluation, $field_name, $item);
              // Create new field array
              $new_field_name = $field_name . '_' . $i;
              $field_view = mkb_eval_get_default_field_view($weight++, $titles[$i], 'above', $new_field_name, 'text_long', $item, $text_area_value['#markup']);
              $content_row[$field_name . '_' . $i] = $field_view;
              $i++;
            }
          }
        }
        // Add each group evaluations to content with either topic or no topic
        if($by_topic){

          $content[$project_info_topic->nid][$eval_conf_type][$gid][$nid] = $content_row;
        }
        else{
          $content[$eval_conf_type][$gid][$nid] = $content_row;
        }
      }
    }
  }

  return $content;
}

/**
 * @return $nodes
 *   Topic nodes (themes)
  */
function mkb_eval_get_all_topics(){
  // Get all topics
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'call_topic')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_topic_level', 'value', 1, '=')
    ->fieldOrderBy('field_topic_weight', 'value', 'ASC');

  $result = $query->execute();

  $topics = array();
  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);

    foreach ($nodes as $node) {
      $topics[$node->nid] = $node;
      $rows[$node->nid] = array();
    }
  }
  return $topics;
}

/**
 * @param $name
 *   Evaluation type term name
 * @return $node
 *   Evaluation configuration node
  */
function mkb_eval_get_eval_conf_by_term_name($name){
  $eval_confs = node_load_multiple(array(), array('type' => 'evaluation_conf'));
  $conf = new stdClass();
  foreach ($eval_confs as $nid => $eval_conf){
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
    $eval_conf_type_term = $eval_conf_wrapper->field_eval_conf_type->value();
    $row_type_name = $eval_conf_type_term->name;
    if($name==$row_type_name) $conf = $eval_conf;
  }
  return $conf;
}

/**
 * @param $name
 *   Evaluation type term name
 * @return $node
 *   Evaluation configuration node
  */
function mkb_eval_get_eval_confs_by_term_name($name){
  $eval_confs = node_load_multiple(array(), array('type' => 'evaluation_conf'));
  foreach ($eval_confs as $nid => $eval_conf){
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
    $eval_conf_type_term = $eval_conf_wrapper->field_eval_conf_type->value();
    $row_type_name = $eval_conf_type_term->name;
    if($name!=$row_type_name) unset($eval_confs[$nid]);
  }
  return $eval_confs;
}

/*
 * From mkb_experts module which as been removed.
 * Make Create or Edit link depending of an instance exists for current user
 * Call from PHP page
 */
function mkb_experts_make_application_link() {
  global $user;
  $uid = $user -> uid;
  $query = db_select('node', 'n');
  $query
    ->fields('n', array('nid'))
    ->condition('n.type', 'eval_expert_application')
    ->condition('n.uid', $uid);
  $result = $query->execute()->fetchAll();
  if ($result) {
    $nid = $result[0] -> nid;
  $link = l('Edit application','node/' . $nid . '/edit');
  }
  else $link = l('Create application','node/add/evaluation-expert');
  return $link;
}


/**
 * Display a single evalution node
 *
 * @param $node
 *   Node
 * @return $content
 *   Node content
  */
function mkb_eval_evaluation_view($node){

  $node_view = node_view($node);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $eval_conf = $node_wrapper->field_eval_conf->value();
  $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);

  // Initiate content and weight
  $content = array();
  $weight = 0;

  $gid = $node->og_group_ref['und'][0]['target_id'];

  // Application acronym
//  $gid = $node_wrapper->og_group_ref->getIdentifier();
  $group_content = mkb_application_get_group_content($gid, 'application_project_info');
  $project_info_node = node_load($group_content[0]);
  $project_info_wrapper = entity_metadata_wrapper('node', $project_info_node);
  $acronym = $project_info_wrapper->field_app_acronym->value();
  $content['acronym'] = array(
      '#markup' => '<b>Application:</b> ' . $acronym . '</br>',
      '#access' => TRUE,
      );


  // Evaluator
  $account = user_load($node->uid);
  $content['realname'] = array(
      '#markup' => '<b>Evaluator:</b> ' . $account->realname . '</br>',
      '#access' => TRUE,
      );
  foreach (element_children($node_view) as $field_name){
    if($field_name == 'field_eval_conf'){
      $content['type'] = array(
        '#markup' => '<b>Evaluation type:</b> ' . $eval_conf_wrapper->label() . '</br>',
        '#access' => TRUE,
        );
    }

    if($field_name == 'field_eval_answers'){
      // Questionnaire
      $header = array();
      $rows = array();

      // Options
      $options = array();
      foreach ($eval_conf_wrapper->field_conf_options->getIterator() as $delta => $option_wrapper) {
        $options[$delta] = $option_wrapper->value();
      }

      // Answers as text
      $answers = array();
      foreach ($node_wrapper->field_eval_answers->getIterator() as $delta => $answer_wrapper) {
        $answer_index = $answer_wrapper->value();
        $answers[$delta] = $answer_index . ' - ' . $options[$answer_index];
      }

      // Questions
      foreach ($eval_conf_wrapper->field_conf_questions->getIterator() as $delta => $question_wrapper) {
        $question = $question_wrapper->value();
        $rows[$delta] = array(
            'question' => $question,
            'answer' => $answers[$delta],
            );
      }

      // Table
      $table = array(
          'header' => $header,
          'rows' => $rows,
          'attributes' => array(
              'class' => array('table_class'),
              'width' => '50%',
              ),
          'sticky' => FALSE,
          'empty' => 'No questions.',
          'colgroups' => array(),
          'caption' => '',
          );
      $content['questionnaire'] = theme_table($table);
    }
    if($field_name == 'field_eval_score'){
      $content['score'] = $node_view[$field_name];
    }
    if($field_name == 'field_eval_radio'){
      // Get radio titles from eval conf
      $titles = array();
      $new_field = $node_view[$field_name];
      foreach ($eval_conf_wrapper->field_conf_radio->getIterator() as $delta => $radio_wrapper) {
        $radio_text = $radio_wrapper->value();
        $subs = explode('#', $radio_text);
        $titles[$delta] = $subs[0];
      }

      $field_items = field_get_items('node', $node, $field_name, $langcode = NULL);
      $i = 0;
      $weight = $node_view[$field_name]['#weight'];
      foreach ($field_items as $item){
        $answer = ($item['value'] == 1) ? 'Yes' : 'No';

        // Create items array with answer
        $new_item = array(
            'value' => $answer,
            'format' => NULL,
            'safe_value' => $answer,
            );
        $new_field_name = $field_name . '_' . $i;
        $field_view = mkb_eval_get_default_field_view($weight, $titles[$i], 'inline', $new_field_name, 'text', $new_item, $answer);
        $content[$field_name . '_' . $i] = $field_view;
        $i++;
      }
    }
    if($field_name == 'field_eval_text_area'){
      // Get text area titles from eval conf
      $titles = array();
      $new_field = $node_view[$field_name];
      foreach ($eval_conf_wrapper->field_conf_text_areas->getIterator() as $delta => $text_area_wrapper) {
        $text_area_text = $text_area_wrapper->value();
        $subs = explode('#', $text_area_text);
        $titles[$delta] = $subs[0];
      }
      // Create new field array and add it to content
      $field_items = field_get_items('node', $node, $field_name, $langcode = NULL);
      $i = 0;
      $weight = $node_view[$field_name]['#weight'];
      foreach ($field_items as $item){
        // Get sanitized text
        $text_area_value = field_view_value('node', $node, $field_name, $item);
        // Create new field array
        $new_field_name = $field_name . '_' . $i;
        $field_view = mkb_eval_get_default_field_view($weight++, $titles[$i], 'above', $new_field_name, 'text_long', $item, $text_area_value['#markup']);
        $content[$field_name . '_' . $i] = $field_view;
        $i++;
      }
    }
  }
  return $content;
}

/**
 * @param $weight
 *   Weight
 * @param $title
 *   Title
 * @param $label_display
 *   Label display
 * @param $field_name
 *   Field name
 * @param $field_type
 *   Field type
 * @param $items
 *   Items
 * @param $value
 *   Value
 * @return $field_view
 *   Field view
  */
function mkb_eval_get_default_field_view($weight, $title, $label_display, $field_name, $field_type, $items, $value){
  $field_view = array(
      '#theme' => 'field',
      '#weight' => $weight,
      '#title' => $title,
      '#access' => TRUE,
      '#label_display' => $label_display,
      '#view_mode' => 'full',
      '#language' => 'und',
      '#field_name' => $field_name,
      '#field_type' => $field_type,
      '#field_translatable' => 0,
      '#entity_type' => 'node',
      '#bundle' => 'evaluation',
      '#items' => array(0 => $items),
      '#formatter' => 'text_default',
      0 => array('#markup' => $value)
      );
  return $field_view;
}

/**
 * @param $cid
 *   Call-main-page node id
 * @return $funder_agencies
 *   Funding agencies for this call.
  */
function mkb_eval_get_all_funding_agency_countries($cid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_funding_agency", "field_funding_agency", "field_funding_agency.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_short_name", "field_short_name", "field_short_name.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query ->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_short_name.entity_id");
  $query ->addField("field_country", "field_country_iso2", "iso2");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_funding_agency.bundle", 'call_funder_page')
    ->condition("field_country.bundle", 'organisation');
  $query ->orderBy('field_country_iso2', 'ASC');
  $query ->distinct();
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    $funding_agencies = array();
    foreach ($result as $row){
      $funding_agencies[$row->iso2] = $row->iso2;
    }
    return $funding_agencies;
  }
  return $result;
}

/**
 * @param $nid
  *   application-partner-budget node id.
 * @return $country
 *   Funding agency country.
 */
function mkb_eval_get_budget_funder_page_iso2($nid){
  $query = db_select("field_data_field_funder_page", "field_funder_page");
  $query->leftJoin("field_data_field_funding_agency", "field_funding_agency", "field_funding_agency.entity_id = field_funder_page.field_funder_page_target_id");
  $query->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query->leftJoin("countries_country", "countries_country", "countries_country.iso2 = field_country.field_country_iso2");
  $query->addField("countries_country", "iso2", "iso2");
  $query->condition("field_funder_page.entity_id", $nid);
  $query->condition("field_funder_page.bundle", 'application_partner_budget');
  $query->condition("field_funding_agency.bundle", 'call_funder_page');
  $query->condition("field_country.bundle", 'organisation');
  $query->distinct();
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $nid
 *   Group node id.
 * @param $stage (optional)
 *   Stage 1 or 2. Use 0 for getting pdf files for all stages.
 * @return links
 *   links to pds files.
 *
 */
function mkb_eval_get_stage_pdf_link($gid, $stage = 0){
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'application_pdf')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
  if($stage != 0) $query->fieldCondition('field_pdf_call_stage', 'value', $stage, '=');
  $result = $query->execute();

  $links = "";
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    
    // Get all uri´s for pdf files
    $list_of_paths = array();
    foreach($nodes as $nid => $node){
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $pdf_field = $node_wrapper->field_pdf_file->value();

      if($pdf_field){
        $file_path = file_create_url($pdf_field['uri']);
        $list_of_paths[] = l($pdf_field['filename'], $file_path);
      }
      
    }

    // If stage is 0 add all files as a list
    if($stage == 0){
      $links = theme("item_list", array(
          'items' => $list_of_paths,
          'type' => 'ul',
          'title' => '',
      ));
    }
    else{
      if(isset($list_of_paths[0])) {
        $url = file_create_url($list_of_paths[0]);
        $links = l(t('View'), $url);
      }
    }
  }
  return $links;
}
