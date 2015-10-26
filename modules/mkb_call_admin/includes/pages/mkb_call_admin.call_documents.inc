<?php

/**
 * Generates content for call_documents template.
 *
 * @param $gid
 *   Group node id
 * @return form
 *   Call documents template.
 */
function mkb_call_admin_call_documents_function($cid){
  $variables = array();
  $call_node = node_load($cid);
  $call = node_view($call_node);
  $variables['call'] = $call;
  
  // Find all funder pages and conditions pdf
  $query = db_select("field_data_field_call_id", "f");
  $query
  ->fields("f", array("entity_id"))
  ->condition("f.field_call_id_target_id", $cid)
  ->condition("f.bundle", "call_funder_page");
  $result = $query->execute()->fetchAll();
  $variables['fa_conditions'] = array();
  foreach($result as $row){
    $fa_node_id = $row->entity_id;
    $fa_node = node_load($fa_node_id);
	if (!empty($fa_node -> field_attachments)) {
	  $variables['fa_conditions'][$fa_node_id] = $fa_node;
	}
  }
  return theme('call_admin_call_documents_template', $variables);
}
