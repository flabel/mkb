<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for relation_proposals template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Evaluation filter node id.
 * @return template
 *   The template relation_proposals.tpl is called with $variables.
 */
function mkb_eval_relation_proposals($cid, $fid, $gid_x, $gid_y){
  $account = $GLOBALS['user'];  
  
  // Load filtered groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid);
  $gids = array_keys($groups);
  
  $acronyms = array();
  foreach ($groups as $gid => $group){
    $acronyms[$gid] = mkb_eval_get_acronym($group->applications['application_project_info']);
  }
  
  if($gid_y != 0) $header = array('Proposals', 'Author', 'Explanation');
  else $header = array('Proposal', 'Author', 'Explanation');
  
  $query = db_select("node", "node");
  $query->leftJoin("field_data_field_rel_proposal_1", "rel_1", "rel_1.entity_id = node.nid");
  $query->leftJoin("field_data_field_rel_proposal_2", "rel_2", "rel_2.entity_id = node.nid");
  $query->addField("node", "nid", "nid");
  $query->addField("rel_1", "field_rel_proposal_1_value", "gid_1");
  $query->addField("rel_2", "field_rel_proposal_2_value", "gid_2");
  
  if($gid_y != 0){
    $and_1 = db_and();
    $and_1->condition("rel_1.field_rel_proposal_1_value", $gid_x);
    $and_1->condition("rel_2.field_rel_proposal_2_value", $gid_y);
    
    $and_2 = db_and();
    $and_2->condition("rel_1.field_rel_proposal_1_value", $gid_y);
    $and_2->condition("rel_2.field_rel_proposal_2_value", $gid_x);
    
    $query
      ->condition("node.type", "application_relation")
      ->condition(db_or()->condition($and_1)->condition($and_2));
  }
  else{
    $query
      ->condition("node.type", "application_relation")
      ->condition(db_or()
                  ->condition("rel_1.field_rel_proposal_1_value", $gid_x)
                  ->condition("rel_2.field_rel_proposal_2_value", $gid_x)
      );
  }
  $query
    ->orderBy('gid_1')
    ->orderBy('gid_2');

  $result = $query->execute()->fetchAll();
  
  $rows_x = array();
  $rows_y = array();
  $rows_xy = array();
  if($result != FALSE && $gid_x != $gid_y){
    foreach($result as $row){
      // Add data to rows according to gids
      if($gid_y == 0){
        if($gid_x == $row->gid_1) $gid_2 = $row->gid_2;
        else $gid_2 = $row->gid_1;
        // Determine gid_y if not in arg        
        $rows_x[] = mkb_eval_add_relation_data($gid_x, $gid_2, $row, $acronyms);
      }
      else{
        if(($gid_x == $row->gid_1 && $gid_y == $row->gid_2) || ($gid_x == $row->gid_2 && $gid_y == $row->gid_1))
          $rows_xy[] = mkb_eval_add_relation_data($gid_x, $gid_y, $row, $acronyms);
        elseif($gid_x == $row->gid_1) 
          $rows_x[] = mkb_eval_add_relation_data($gid_x, $row->gid_2, $row, $acronyms);
        elseif($gid_x == $row->gid_2) 
          $rows_x[] = mkb_eval_add_relation_data($gid_x, $row->gid_1, $row, $acronyms);
        elseif($gid_y == $row->gid_1) 
          $rows_y[] = mkb_eval_add_relation_data($gid_y, $row->gid_2, $row, $acronyms);
        elseif($gid_y == $row->gid_2) 
          $rows_y[] = mkb_eval_add_relation_data($gid_y, $row->gid_1, $row, $acronyms);
      }
    }
  }
  $rows = array_merge($rows_xy, $rows_x, $rows_y);

  $variables['acronym_x'] = $acronyms[$gid_x];
  if($gid_y != 0) $variables['acronym_y'] = $acronyms[$gid_y];
  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('relation_proposals', $variables);
}

function mkb_eval_add_relation_data($gid_1, $gid_2, $row, $acronyms){
  $n_row = array();
  // Add acronyms      
  $n_row[] = $gid_1 . ': ' . $acronyms[$gid_1] . '<br>' . 
                $gid_2 . ': ' . $acronyms[$gid_2];
  
  // Get application relation wrapper
  $app_relation = node_load($row->nid);
  $app_relation_wrapper = entity_metadata_wrapper('node', $app_relation);

  // Add author
  $author = $app_relation_wrapper->author->value();
  $n_row[] = l($author->realname, 'user-profile/' . $author->uid);
  
  // Add explanation
  $explanation = $app_relation_wrapper->field_rel_explanation->value();
  $n_row[] = nl2br($explanation);
  
  return $n_row;
}
