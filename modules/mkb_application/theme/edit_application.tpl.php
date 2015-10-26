<?php
$custom_header = array('Member', 'Role', 'Project-info', 'Partner-info', 'Partner-budget');
$custom_rows = array();
$uid = 0;
$custom_index = 0;
//Build custom rows from rows
$rows = $variables['rows'];
//dpm($rows);
for($i=0; $i<count($rows); $i++){
  //User
  if($rows[$i]->entity_type == 'user'){
    $uid = $rows[$i]->uid;
    $custom_rows[$custom_index][$uid] = array();
    $custom_rows[$custom_index][$uid]['realname'] = l($rows[$i]->realname, 'user-profile/' . $uid);
    if($uid == $GLOBALS['user']->uid && $variables['coordinator']['is_coordinator']){
      $custom_rows[$custom_index][$uid]['role'] = "project coordinator";
    }
    else{
      $custom_rows[$custom_index][$uid]['role'] = $rows[$i]->role;
    }

    // If current user is coordinator
    if($variables['coordinator']['uid'] == $GLOBALS['user']->uid){
      // row->uid == coordinator
      if($uid == $variables['coordinator']['uid']){
        $custom_rows[$custom_index][$uid]['project_info'] = '<a href="/node/add/application-project-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_info'] = '<a href="/node/add/application-partner-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_budget'] = '<a href="/node/add/application-partner-budget/u=' . $uid . '">Create</a>';
      }
      else{
        $custom_rows[$custom_index][$uid]['project_info'] = '';
        $custom_rows[$custom_index][$uid]['partner_info'] = '<a href="/node/add/application-partner-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_budget'] = '<a href="/node/add/application-partner-budget/u=' . $uid . '">Create</a>';
      }
    }
    // If current user is editor
    elseif(isset($variables['editor']['uid']) && $variables['editor']['uid'] == $GLOBALS['user']->uid){
      // row->uid == coordinator
      if($uid == $variables['coordinator']['uid']){
        $custom_rows[$custom_index][$uid]['project_info'] = '<a href="/node/add/application-project-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_info'] = '<a href="/node/add/application-partner-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_budget'] = '<a href="/node/add/application-partner-budget/u=' . $uid . '">Create</a>';
      }
      // row->uid == editor
      if($uid == $variables['editor']['uid']){
        $custom_rows[$custom_index][$uid]['project_info'] = '';
        $custom_rows[$custom_index][$uid]['partner_info'] = '<a href="/node/add/application-partner-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_budget'] = '<a href="/node/add/application-partner-budget/u=' . $uid . '">Create</a>';
      }
      else{
        $custom_rows[$custom_index][$uid]['project_info'] = '';
        $custom_rows[$custom_index][$uid]['partner_info'] = '<a href="/node/add/application-partner-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_budget'] = '<a href="/node/add/application-partner-budget/u=' . $uid . '">Create</a>';
      }
    }
    // If row->user is == current user
    elseif($uid == $GLOBALS['user']->uid){
        $custom_rows[$custom_index][$uid]['project_info'] = '';
        $custom_rows[$custom_index][$uid]['partner_info'] = '<a href="/node/add/application-partner-info/u=' . $uid . '">Create</a>';
        $custom_rows[$custom_index][$uid]['partner_budget'] = '<a href="/node/add/application-partner-budget/u=' . $uid . '">Create</a>';
    }
    else{
      $custom_rows[$custom_index][$uid]['project_info'] = '';
      $custom_rows[$custom_index][$uid]['partner_info'] = '';
      $custom_rows[$custom_index][$uid]['partner_budget'] = '';
    }
  }
  elseif($rows[$i]->entity_type == 'node'){
  //Node
    $author_uid = $rows[$i]->author_uid;
    if($rows[$i]->type == 'application_project_info'){
      $custom_rows[$custom_index][$author_uid]['project_info'] = '<a href="/node/' . $rows[$i]->nid . '">View/Edit</a>';
    }
    if($rows[$i]->type == 'application_partner_info'){
      $custom_rows[$custom_index][$author_uid]['partner_info'] = '<a href="/node/' . $rows[$i]->nid . '">View/Edit</a>';
    }
    if($rows[$i]->type == 'application_partner_budget'){
      $custom_rows[$custom_index][$author_uid]['partner_budget'] = '<a href="/node/' . $rows[$i]->nid . '">View/Edit</a>';
    }
  }
// Modification to allow editing of partner info and partner budget and not project info. The meaning of this code?
//if (isset($custom_rows[$custom_index][$uid]['project_info'])) $custom_rows[$custom_index][$uid]['project_info'] = '';
}

print '<h2 class="block-title">Edit application</h2>';
print '<p><b>Group:</b> ' . $variables['group_title'] . '</p>';
$table = array(
    'header' => $custom_header,
    'rows' => $custom_rows[0],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => FALSE,
    'empty' => 'No applications fulfill the filter for this page.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);
?>

