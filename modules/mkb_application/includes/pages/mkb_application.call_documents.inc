<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Generates content for call_documents template.
 *
 * @param $gid
 *   Group node id
 * @return form
 *   Call documents template.
 */
function mkb_application_call_documents_function($gid){
  $variables = array();
  $cid = mkb_application_get_call_main_nid($gid);
  if ($cid) {
    $call_node = node_load($cid);
    $call = node_view($call_node);
    $variables['call'] = $call;
  }
  return theme('call_documents_template', $variables);
}