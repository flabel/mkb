<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for relation_admin template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Evaluation filter node id.
 * @return template
 *   The template relation_admin.tpl is called with $variables.
 */
function mkb_eval_relation_admin($cid, $fid){
  $account = $GLOBALS['user'];  
  
  // Load filtered groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid);

  $header = array('Proposals');
  $rows = array();
  $gids = array_keys($groups);
  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;
    
    // Add acronym to header and first cell in rows
    $acronym = mkb_eval_get_acronym($applications['application_project_info']);
    $header[$gid] = $acronym;
    $rows[$gid][0] = $acronym;
  }
  
  foreach($gids as $gid_x){
    foreach($gids as $gid_y){
      $query = db_select("node", "node");
      $query ->leftJoin("field_data_field_rel_proposal_1", "rel_1", "rel_1.entity_id = node.nid");
      $query ->leftJoin("field_data_field_rel_proposal_2", "rel_2", "rel_2.entity_id = node.nid");
      $query ->addField("node", "nid", "nid");
      
      $and_1 = db_and();
      $and_1->condition("rel_1.field_rel_proposal_1_value", $gid_x);
      $and_1->condition("rel_2.field_rel_proposal_2_value", $gid_y);
      
      $and_2 = db_and();
      $and_2->condition("rel_1.field_rel_proposal_1_value", $gid_y);
      $and_2->condition("rel_2.field_rel_proposal_2_value", $gid_x);
      
      $query
        ->condition("node.type", "application_relation")
        ->condition("node.uid", $account->uid)
        ->condition(db_or()->condition($and_1)->condition($and_2));

      $nid = $query->execute()->fetchField();
      if($gid_x != $gid_y){
        if($nid) $rows[$gid_x][$gid_y] = l('Edit', 'node/' . $nid . '/edit/' . $cid. '/' . $fid . '/' . $gid_x . '/' . $gid_y, array('query' => drupal_get_destination()));
        else $rows[$gid_x][$gid_y] = l('Create', 'node/add/application-relation' . '/' . $cid. '/' . $fid . '/' . $gid_x . '/' . $gid_y, array('query' => drupal_get_destination()));
      }
      else $rows[$gid_x][$gid_y] = '';
    }
  }

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('relation_admin', $variables);
}

function mkb_eval_application_matrix($groups){
  
}
