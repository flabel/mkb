<?php

/*
 * Content for the rapports block
 */
function mkb_pm_rapports_block_content() {
  $content = '';
  $gid = mkb_groups_block_content_gid();
  if($gid == 0) return $content;
  
  // Get Call
  $cid = mkb_application_get_call_main_nid($gid);
  $call = node_load($cid);

  // Get Application project info
  $group_content = mkb_application_get_group_content($gid, 'application_project_info');
  if(isset($group_content[0])) $project_info = $group_content[0];
  else return $content;
  $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
  $submitted_1 = $project_info_wrapper->field_app_submitted->value();
  $selected_1 = $project_info_wrapper->field_app_selected_1->value();
  $selected_2 = $project_info_wrapper->field_app_selected_2->value();
  
  // Check if group is checked as application
  $is_application = mkb_application_group_is_application($gid);
  if(!$is_application) return $content;
  
  // Get Application publish configurations
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'application_publish_conf')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->fieldCondition('field_call_id', 'target_id', $cid)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $content = '';
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = entity_load('node', $nids);
    
    $index = 0;
    foreach($nodes as $nid => $node){
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $is_open = $node_wrapper->field_apc_open_close->value();

      $webform_ids = $node_wrapper->field_apc_webform_ids->value();
      $has_webform =  !empty($webform_ids);

      if($is_open && !$has_webform){
        // Get status and check if application should have menu for this apc
        $status = $node_wrapper->field_apc_project_status->value();
        $status_ok = FALSE;
        if($status == 0 && $submitted_1 == 1) $status_ok = TRUE;
        if($status == 1 && $selected_1 == 1) $status_ok = TRUE;
        if($status == 2 && $selected_2 == 1) $status_ok = TRUE;

        // Create menu and links
        if($status_ok){

          // Get Application project publish if it exist
          $group_content = mkb_application_get_group_content($gid, 'application_project_publish');
          if(isset($group_content[0])){
            $app_pp_nid = $group_content[0];
            
            $app_pp_link_path = 'node/' . $app_pp_nid . '/edit';
            $app_pp_link_text = 'Edit';
          }
          else{
            $app_pp_link_path = 'node/add/application-project-publish/' . $gid;
            $app_pp_link_text = 'Create';
          }
          
          if($index == 0) $content = '<div class="block-menu"><ul class="menu clearfix">';
          
          $content .= '<li class="first leaf menu-depth-1">' . $node_wrapper->label();
            $content .= '<ul class="menu clearfix">';
            $content .= '<li class="first leaf menu-depth-1">' . l('Guide',  'groups/workspace/guide/' . $gid . '/' . $nid, 
              array('query' => drupal_get_destination())) . '</li>';
            $content .= '<li class="leaf menu-depth-1">' . l($app_pp_link_text,  $app_pp_link_path, 
              array('query' => drupal_get_destination())) . '</li>';
            $content .= '<li class="leaf menu-depth-1">' . l('View',  'groups/workspace/rapport/' . $gid . '/' . $nid,
              array('query' => drupal_get_destination())) . '</li>'; 
            $content .= '</ul>';
          $content .= '</li>';
          
          if($index == count($nodes)) $content.= '</ul></div>';
        }
      }
      $index++;
    }
  }  
  return $content;
}
