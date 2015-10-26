<?php
module_load_include('inc', 'mkb_pm', 'includes/mkb_pm.helper');

/**
 * @param gid
 *  Group node id
 * @param apcid
 *  Application project configuration node id
 * @return template
 *  Rendered template guide_template
 */
function mkb_pm_guide($gid, $apcid){
  $apc = node_load($apcid);
  $apc_wrapper = entity_metadata_wrapper('node', $apc);

  $title = $apc_wrapper->title->value(array('sanitize' => TRUE));
  $body = $apc_wrapper->body->value->value(array('sanitize' => TRUE));
  
  $list_of_paths = array();
  foreach ($apc_wrapper->field_apc_template_files->getIterator() as $delta => $file_wrapper) {
    $file = $file_wrapper->value();
    $link = !empty($file['description']) ? $file['description'] : $file['filename'];
    $file_uri = $file['uri'];
    $file_path = file_create_url($file_uri);
    $list_of_paths[] = l($link, $file_path);
  }
  if (!empty($list_of_paths)) {
    $templates = theme("item_list", array(
       'items' => $list_of_paths,
       'type' => 'ul',
       'title' => 'Templates',
    ));
  }
  else $templates = '';
  
  $variables['title'] = $title;
  $variables['body'] = $body;
  $variables['templates'] = $templates;
  return theme('guide_template', $variables);
}
