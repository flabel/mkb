<?php
print '<h2 class="block-title">Call documents</h2>';
$call = $variables['call'];
$list_of_paths = array();
if(isset($call) && isset($call['#node']->field_call_documents['und'])){
  foreach($call['#node']->field_call_documents['und'] as $index => $file){
      $file_uri = $file['uri'];
      $file_path = file_create_url($file_uri);
      $list_of_paths[] = l($file['filename'], $file_path);
  }
  print theme("item_list", array(
      'items' => $list_of_paths,
      'type' => 'ul',
      'title' => 'Documents',
  ));
}
else{
  print '<p>There are no call documents.</p>';
  print '<p>You may not have selected a call in the group page.</p>';
}
?>

