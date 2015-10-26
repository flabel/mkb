<?php
drupal_set_title('');
print '<h2 class="block-title">Call documents</h2>';
$call = $variables['call'];
$list_of_paths = array();
if(isset($call['#node']->field_call_documents['und'])){
 foreach($call['#node']->field_call_documents['und'] as $index => $file){
  $link = !empty($file['description']) ? $file['description'] : $file['filename'];
  $file_uri = $file['uri'];
  $file_path = file_create_url($file_uri);
  $list_of_paths[] = l($link, $file_path);
 }
 print theme("item_list", array(
		 'items' => $list_of_paths,
		 'type' => 'ul',
		 'title' => 'Documents',
 ));
}
else{
 print '<p>There are no call documents.</p>';
}

$conditions_paths = array();
if (!empty($variables['fa_conditions'])) {
 print '</br>';
 print '<h2 class="block-title">Regulations by Funding Agency</h2>';
 $fa_conditions = $variables['fa_conditions'];
 foreach($fa_conditions as $fa_condition) {
     $country = mkb_call_admin_get_funder_page_country($fa_condition->nid);
	 foreach($fa_condition->field_attachments['und'] as $index => $file){
	   $link = !empty($file['description']) ? $file['description'] : $file['filename'];
       $file_uri = $file['uri'];
       $file_path = file_create_url($file_uri);
       $conditions_paths[$country][] = l($link, $file_path);
	 }
 }

 foreach ($conditions_paths as $country => $condition_path){
   print theme("item_list", array(
  		 'items' => $condition_path,
  		 'type' => 'ul',
  		 'title' => $country,
   ));
 }
}

?>
