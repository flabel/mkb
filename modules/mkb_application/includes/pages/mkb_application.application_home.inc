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
function mkb_application_home_function($gid){
  $variables = array();

  // Group
  $group = node_load($gid);

  // Call
  $cid = mkb_application_get_call_main_nid($gid);
  $call = isset($cid) ? node_load($cid) : array();

  // Application
  $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
  $project_info = empty($project_info_nids) ? array() : node_load(end($project_info_nids));
  $variables['group'] = $group;
  $variables['call'] = $call;
  $variables['project_info'] = $project_info;
  return theme('application_home', $variables);
}