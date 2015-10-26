<div id="hor-zebra">
<h2><?php print $call_main->title;?></h2>
<h1><?php if(isset($project_info['title'])) print $project_info['title'];?></h1>
<p><b>Id </b><?php print $group->nid;?></p>
<p><b>Acronym </b><?php if(isset($project_info['field_app_acronym'])) print $project_info['field_app_acronym']['und'][0]['value'];?></p>
<p><b>Consortium</b></p>
<table>
<tr>
  <th>No</th>
  <th>Acronym</th>
  <th>Partner</th>
  <th>Contact</th>
  <th>Country</th>
  <th>Total EUR</th>
  <th>Requested EUR</th>
</tr>
<?php
 // dpm($project_info);
 // dpm($applications);
if(isset($project_info)){
  $node = node_load($project_info['nid']);
  $coordinator_uid = $node->uid;
  }
else $coordinator_uid = FALSE;
$index = 1;
foreach ($applications as $partner_uid => $partner){
  $acronym = "";
  if(isset($partner['partner_info']['field_par_acronym']['und'][0]['value'])) $acronym = $partner['partner_info']['field_par_acronym']['und'][0]['value'];
  $my_org = "";
  if(isset($partner['user']['my_org'])) $my_org = $partner['user']['my_org'];
  $total = "";
  $requested = "";
  if(isset($partner['budget_table'][10])){
    $num_col = count($partner['budget_table'][10]);
    $total = $partner['budget_table'][10][$num_col-2];
    $requested = $partner['budget_table'][10][$num_col-1];
  }
  if($index % 2) print '<tr class="odd">'; else print '<tr class="even">';
  if ($partner_uid == $coordinator_uid) $coord = ' Coord.'; else $coord = '';
  print "<td>" . $index . $coord . "</td>";
  print "<td>" . $acronym . "</td>";
  print "<td>" . $my_org . "</td>";
  print "<td>" . $partner['user']['realname'] . "</td>";
  print "<td>" . $partner['user']['country'] . "</td>";
  print "<td>" . $total . "</td>";
  print "<td>" . $requested . "</td>";
  print "</tr>";
  $index++;
}
?>
</table>
<br/>
<?php
if(isset($project_info)){
  $node = node_load($project_info['nid']);
  $project_info_view = node_view($node);

  foreach ($project_info['fields'] as $field){
    $field_name = "field_app_" . $field;
    if(array_key_exists($field_name, $project_info) && !empty($project_info[$field_name]) && !empty($project_info[$field_name]['und'])){
      if($field_name == "field_app_topics" || $field_name == "field_app_keywords"){
        print "<b>" . $project_info['labels'][$field_name]['title'] . "</b>";
        print "<ul>";
        foreach ($project_info[$field_name]['und'] as $row){
          print "<li>" . $row['value'] . "</li>";
        }
        print "</ul>";
      }
      elseif($field_name == "field_app_dow" || $field_name == "field_app_video"){
				if (!empty($project_info[$field_name]['und'][0]['description'])) $url_label = $project_info[$field_name]['und'][0]['description'];
				else $url_label = $project_info['labels'][$field_name]['title'];
        print isset($project_info_view[$field_name]) ?
          render($project_info_view[$field_name]) : '<p><b>' . $url_label . ':</b> None';
      }
      else{
        print "<b>" . $project_info['labels'][$field_name]['title'] . "</b>";
        print "<p>" . nl2br($project_info[$field_name]['und'][0]['value']) . "</p>";
      }
    }
  }
  // Description of work
  if (!empty($project_info['field_attachments'])) {
    $list_of_paths = array();
    foreach($project_info['field_attachments']['und'] as $index => $file){
      $link = !empty($file['description']) ? $file['description'] : $file['filename'];
      $file_uri = $file['uri'];
      $file_path = file_create_url($file_uri);
      $list_of_paths[] = l($link, $file_path);
    }
    print theme("item_list", array(
      'items' => $list_of_paths,
      'type' => 'ul',
      'title' => 'Attachments',
    ));		
  }
}
?>

<?php
$set_total_budget_msg = FALSE;
if(!isset($total_budget)) $set_total_budget_msg = TRUE;
else{
  print "<p><b>Total budget</b></p>";
  mkb_application_print_budget_table($total_budget);
}
?>
<h2>Partner information</h2>
<?php

// A short version without parnter infomation
$short = arg(4);
if ($short) goto end_page;

$index = 1;
foreach ($applications as $partner){
  if(isset($partner['partner_info'])){
    $acronym = "";
    if(isset($partner['partner_info']['field_par_acronym']['und'][0]['value'])) $acronym = $partner['partner_info']['field_par_acronym']['und'][0]['value'];
    $title = "";
    if(isset($partner['partner_info']['title'])) $title = $partner['partner_info']['title'];
    $my_org = "";
    if(!empty($partner['user']['my_org'])) $my_org = $partner['user']['my_org'];
    else{
      drupal_set_message($partner['user']['realname'] . t(' has not created a profile with "My organisation". Please create/update in Home > My profile.'), $type = 'warning');
    }

    print "<p><b>" . $index . " " . $acronym  . " " . $partner['user']['country'] . "</b></p>";
    print "<p><b>" . $partner['user']['realname'] . "</b>, " . $my_org . "</p>";

    foreach ($partner_info['fields'] as $field){
      $field_name = "field_par_" . $field;
      if(array_key_exists($field_name, $partner['partner_info']) && $partner['partner_info'][$field_name]){
        print "<b>" . $partner_info['labels'][$field_name]['title'] . "</b>";
        print "<p>" . nl2br($partner['partner_info'][$field_name]['und'][0]['value']) . "</p>";
      }
    }
	// SME declaration
	if (isset($partner['partner_info']['field_par_sme']) && !empty($partner['partner_info']['field_par_sme'])) {
      print "<b>" . $partner_info['labels']['field_par_sme']['title'] . "</b>";
	  print '<p>';
	  $sme_checks = array();
	  $checks = $partner['partner_info']['field_par_sme']['und'];
	  foreach ($checks as $check) {
	    $sme_checks[] = $check['value'];
	  }
	  foreach ($partner_info['sme_options'] as $key => $option) {
	    if ($key>0) print '</br>';
		if (in_array($key,$sme_checks)) print '&#9745; ';
		else print '&#9744; ';
		print $option;
	  }
	  print '</p>';
	}
  }
  else{
    drupal_set_message($partner['user']['realname'] . t(' has not created a partner info. Please create one to see partner information and partner budget.'), $type = 'warning');
  }

  if(isset($partner['budget_table']) && isset($partner['partner_info'])){
    print '<p><b>Budget</b> from <b>' . $partner['funding_page_title'] . '</b></p>';
    mkb_application_print_budget_table($partner['budget_table']);
	$field_name = 'field_bud_budget_info';
    if(array_key_exists($field_name, $partner['partner_budget']) && $partner['partner_budget'][$field_name]){
      print "<b>" . t('Supplementary budget information') . "</b>";
      print "<p>" . nl2br($partner['partner_budget'][$field_name]['und'][0]['value']) . "</p>";
    }

  // Budget documents
  if (!empty($partner['partner_budget']['field_bud_documents'])) {
    $list_of_paths = array();
    foreach($partner['partner_budget']['field_bud_documents']['und'] as $index => $file){
      $link = !empty($file['description']) ? $file['description'] : $file['filename'];
      $file_uri = $file['uri'];
      $file_path = file_create_url($file_uri);
      $list_of_paths[] = l($link, $file_path);
    }
    print theme("item_list", array(
      'items' => $list_of_paths,
      'type' => 'ul',
      'title' => 'Budget documents',
    ));
  }
  }
  elseif(!isset($partner['budget_table'])){
    drupal_set_message($partner['user']['realname'] . t(' has not created a partner budget.'), $type = 'warning');
  }
  // index is used for numbering the partners
  $index++;
}
if($set_total_budget_msg) drupal_set_message(t('The total budget table will be generated when all partners have made a budget.'), $type = 'warning');

end_page:
?>
</div>
