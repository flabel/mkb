<div id="hor-zebra">
<h2><?php print $call_main->title;?></h2>
<h1><?php if(isset($project_info['title'])) print $project_info['title'];?></h1>
<p><b>Id </b><?php print $group->nid;?></p>
<p><b>Acronym </b><?php if(isset($project_info['field_app_acronym'])) print $project_info['field_app_acronym']['und'][0]['value'];?></p>
<?php if(isset($variables['app_pp_view']['field_pp_duration'])) print drupal_render($variables['app_pp_view']['field_pp_duration']);?>
<p><b>Summary</b><p><?php if(isset($variables['app_pp_view'])) print drupal_render($variables['app_pp_view']['body']);?>

<p><b>Consortium</b></p>
<table>
<tr>
  <th>No</th>
  <th>Partner</th>
  <th>Contact</th>
  <th>Country</th>
  <th>Total </br>1000€</th>
  <th>Funded </br>1000€</th>
  <th>Funder</th>  
</tr>
<?php
  //dpm($variables['app_pp_view']);
 // dpm($project_info);
 // dpm($applications);
if(isset($project_info)){
  $node = node_load($project_info['nid']);
  $coordinator_uid = $node->uid;
  }
else $coordinator_uid = FALSE;
$index = 1;
foreach ($applications as $partner_uid => $partner){
  $user_org_name = "";
  if(isset($partner['user']['user_org_name'])) $user_org_name = $partner['user']['user_org_name'];
  $total = "";
  $requested = "";
  if(isset($partner['budget_table'][10])){
    $num_col = count($partner['budget_table'][10]);
    $total = $partner['budget_table'][10][$num_col-2];
    $requested = $partner['budget_table'][10][$num_col-1];
  }

  $fa_org_name = "";
  if(isset($partner['fa_org_name'])) $fa_org_name = $partner['fa_org_name'];
  
  if($index % 2) print '<tr class="odd">'; else print '<tr class="even">';
  if ($partner_uid == $coordinator_uid) $coord = ' Coord.'; else $coord = '';
  print "<td>" . $index . $coord . "</td>";
  print "<td>" . $user_org_name . "</td>";
  print "<td>" . l($partner['user']['realname'], 'user-profile/' . $partner_uid) . "</td>";
  print "<td>" . $partner['user']['country'] . "</td>";
  print "<td>" . $total . "</td>";
  print "<td>" . $requested . "</td>";
  print "<td>" . $fa_org_name . "</td>";  
  print "</tr>";
  $index++;
}
?>
</table>
<br/>

<?php
//$set_total_budget_msg = FALSE;
//if(!isset($total_budget)) $set_total_budget_msg = TRUE;
//else{
  //print "<p><b>Budget</b></p>";
  //mkb_application_print_budget_table($total_budget);
//}

if(isset($variables['app_pp_view']['field_pp_link'])) print nl2br(drupal_render($variables['app_pp_view']['field_pp_link']));
print "<br>";
if(isset($variables['app_pp_view']['field_pp_project_progress'])) print drupal_render($variables['app_pp_view']['field_pp_project_progress']);

//if($set_total_budget_msg) drupal_set_message(t('The total budget table will be generated when all partners have made a budget.'), $type = 'warning');
?>
</div>
