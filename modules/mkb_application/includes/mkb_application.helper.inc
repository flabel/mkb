<?php

/**
 * @param $gid
 *   Group node id
 * @param $uid
 *   User id.
 * @param $types
 *   Node types.
 * @return og_membership_ids
 *   og_membership ids.
 */
function mkb_application_get_node_type_ids($gid, $uid, $types){
  $node_ids = array();
  $query = db_select("og_membership", "og_membership");
  $query->leftJoin("node", "node", "node.nid = og_membership.etid");
  $query ->addField("node", "nid", "nid");
  $query
    ->condition("og_membership.entity_type", "node")
    ->condition("og_membership.group_type", "node")
    ->condition("og_membership.gid", $gid)
    ->condition("node.type", $types, 'IN')
    ->condition("node.uid", $uid);
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    foreach ($result as $row){
      $node_ids[] = $row->nid;
    }
  }
  return $node_ids;
}

/**
 * @param $gid
 *   Group node id.
 * @return $is_coordinator_or_editor
 */
function mkb_application_is_coordinator_or_editor($gid){
  global $user;
  $og_roles = og_get_user_roles('node', $gid, $user->uid);
  if(in_array('project coordinator', $og_roles) || in_array('project editor', $og_roles)){
    return TRUE;
  }
  return FALSE;
}

/**
 * @param $gid
 *   Group node id.
 * @return $group_content
 *   Groups application_project_info acronym or group title
 *   Users in group
 *   Content in group (project_info, partner_info and partner_budget)
 *
 */
function mkb_application_get_group_user_and_roles($gid){
  //Group title
  $group_title = '';
  $nids = mkb_application_get_group_content($gid, 'application_project_info');
  if(!empty($nids)){
    $project_info_node = node_load(end($nids));
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info_node);
    $group_title = $project_info_wrapper->field_app_acronym->value();
  }
  else{
    $query = db_select("node", "n");
    $query
    ->fields("n", array("title"))
    ->condition("n.nid", $gid, "=")
    ->condition("n.type", "group", "=");
    $result = $query->execute();
    $group_title = $result->fetchField();
  }

  //User data
  $query = db_select("og_membership", "og_membership");
  $query->leftJoin("users", "users", "users.uid = og_membership.etid");
  $query->leftJoin("realname", "realname", "realname.uid = users.uid");
  $query->leftJoin("field_data_field_country", "field_data_field_country", "field_data_field_country.entity_id = users.uid");
  $query->leftJoin("countries_country", "countries_country", "countries_country.iso2 = field_data_field_country.field_country_iso2");
  $query->leftJoin("og_users_roles", "og_users_roles", "og_users_roles.uid = realname.uid");
  $query->leftJoin("og_role", "og_role", "og_role.rid = og_users_roles.rid");
  $query->addField("og_membership", "entity_type", "entity_type");
  $query->addField("users", "uid", "uid");
  $query->addField("realname", "realname", "realname");
  $query->addField("countries_country", "name", "country");
  $query->addField("og_role", "name", "role");
  $query->condition("og_membership.entity_type", "user");
  $query->condition("field_data_field_country.entity_type", "user");
  $query->condition("field_data_field_country.bundle", "user");
  $query->condition("og_membership.gid", $gid);
  $query->condition("og_users_roles.gid", $gid);
  $query->condition("og_role.name", "administrator", "<>");
  $query->condition("og_role.name", "project editor", "<>");
  $query->distinct();
  $user_result = $query->execute()->fetchAll();

  $users_uid = array();
  $coordinator = array('uid' => '', 'is_coordinator' => FALSE);
  foreach ($user_result as $row){
    array_push($users_uid, $row->uid);
    if($row->uid == $GLOBALS['user']->uid && $row->role == "project coordinator"){
      $coordinator = array('uid' => $row->uid, 'is_coordinator' => TRUE);
    }
  }

  $rows = array();
  if($users_uid){
    $query = db_select("og_membership", "og_membership");
    $query->leftJoin("node", "node", "node.nid = og_membership.etid");
    $query->addField("og_membership", "entity_type", "entity_type");
    $query->addField("node", "uid", "author_uid");
    $query->addField("node", "nid", "nid");
    $query->addField("node", "type", "type");
    $query->condition("og_membership.gid", $gid);
    $query->condition("og_membership.entity_type", "node");
    $query->condition("node.uid", $users_uid, "in");
    $db_or = db_or();
    $db_or->condition("node.type", "application_project_info");
    $db_or->condition("node.type", "application_partner_info");
    $db_or->condition("node.type", "application_partner_budget");
    $query->condition($db_or);
    $node_result = $query->execute()->fetchAll();
    $rows = array_merge($user_result, $node_result);
  }
  else{
    $rows = $user_result;
  }
  return array('group_title' => $group_title, 'rows' => $rows, 'coordinator' => $coordinator);
}

/**
 * Determines access to create and edit for application content types (project_info,
 * partner_info and partner_budget) according to:
 * 1. Any user in a group can only create one of each content types.
 * 2. Call is open
 * 3. Application is selected for this stage
 *
 * @param $node
 *   Node.
 * @param $multiple
 *   Get multiple content types or just one.
 *
 */
function mkb_application_group_content_control($node, $multiple = FALSE){
  if(isset($_SESSION["mkb_gid"])){
    $gid = $_SESSION["mkb_gid"];
    $call_open = mkb_application_gid_call_open($gid);

    $stages = mkb_application_stages($gid)+1;
    $current_stage = mkb_application_current_stage($gid);
    $group_content_nids = mkb_application_get_group_content($gid, 'application_project_info');
    $project_info = empty($group_content_nids) ? array() : node_load($group_content_nids[0]);
    $app_selected_1 = isset($project_info->field_app_selected_1['und'][0]['value']) ? $project_info->field_app_selected_1['und'][0]['value'] : 0;

    //If node is new (node/add)
    if(!isset($node->nid) || isset($node->is_new)){
      if(($call_open && $current_stage == 1) || ($call_open && $current_stage == 2 && $stages == 2 && $app_selected_1 == 1)){
        // Get the user id from row in "edit_application"
        $uid = arg(3);
	if($uid[0] == 'u'){
	  $uid = substr($uid, 2, strlen($uid));
	}
        if(user_load($uid) !== FALSE){
          // Grab the number of application nodes the user has already created.
          $query = db_select("node", "n");
          $query->leftJoin("og_membership", "o", "n.nid = o.etid");
          $query
          ->fields("n", array("nid"))
          ->condition("n.type", $node->type)
          ->condition("o.gid", $gid)
          ->condition("o.entity_type", "node");
          if($multiple){
            $query
            ->condition("n.uid", $uid);
          }
          $result = $query->execute();
          $num_of_results = $result->rowCount();

          //Max allowed number of nodes
          $limit = 1;

          // If the user is at/has exceeded the limit, set a message and send the user
          // off somewhere else.
          if ($limit <= $num_of_results) {
            drupal_set_message($node->type . ' already exist. Cannot create new.', 'warning');
            drupal_set_message('Number of results: ' . $num_of_results, 'warning');
            drupal_goto('groups/workspace/edit_app/' . $_SESSION["mkb_gid"]);
          }
        }
        else{
          drupal_set_message('User does not exist.', 'warning');
          drupal_goto('groups/workspace/edit_app/' . $_SESSION["mkb_gid"]);
        }
      }
      //If call is closed
      else{
        drupal_set_message('Call is closed.', 'warning');
        drupal_goto('groups/workspace/edit_app/' . $_SESSION["mkb_gid"]);
      }
    }
    //If node is not new (node/edit)
    else{
      // If call is closed
      if(!($call_open && $current_stage == 1) && !($call_open && $current_stage == 2 && $stages == 2 && $app_selected_1 == 1)){
        drupal_set_message('Call is closed.', 'warning');
        drupal_goto('groups/workspace/edit_app/' . $_SESSION["mkb_gid"]);
      }
    }
  }
  //If group id (gid) session variable is not set
  else{
    drupal_set_message('Please create the ' . $node->type . ' through the links in the group workspace.', 'warning');
    drupal_goto('groups/about-partnering');
  }
}

/**
 * @param $gid
 *   Group node id (gid).
 * @return $stage
 * Stages
 */
function mkb_application_stages($gid){
  $query = db_select("field_data_field_group_application", "field_group_application");
  $query->leftJoin("field_data_field_stages", "field_stages", "field_stages.entity_id = field_group_application.field_group_application_target_id");
  $query ->addField("field_stages", "field_stages_value", "stages");
  $query
  ->condition("field_group_application.entity_type", "node")
  ->condition("field_group_application.entity_id", $gid);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $gid
 *   Group node id (gid).
 * @return $current_stage
 *   Current stage (returning 1 or 2)
 */
function mkb_application_current_stage($gid){
  $query = db_select("field_data_field_group_application", "field_group_application");
  $query->leftJoin("field_data_field_current_stage", "field_current_stage", "field_current_stage.entity_id = field_group_application.field_group_application_target_id");
  $query ->addField("field_current_stage", "field_current_stage_value", "current_stage");
  $query
  ->condition("field_group_application.entity_type", "node")
  ->condition("field_group_application.entity_id", $gid);
  $result = $query->execute()->fetchField();
  return $result;
}

/**
 * @param $gid
 *   Group node id (gid).
 * @return $call_open
 *   $call_open
 */
function mkb_application_gid_call_open($gid){
  $query = db_select("field_data_field_call_open_edit", "ca");
  $query->leftJoin("field_data_field_group_application", "g", "ca.entity_id = g.field_group_application_target_id");
  $query
  ->fields("ca", array("field_call_open_edit_value"))
  ->condition("g.entity_id", $gid);
  $result = $query->execute();
  $call_open = $result->fetchField();
  return $call_open;
}

/**
 * Param Call-main-page nid
 * Returns the call_funder_page titles
 */
function mkb_application_get_fa_options_by_country($nid, $uid) {
  $c_query = db_select("field_data_field_country", "c");
  $c_query
  ->fields("c", array("field_country_iso2"))
  ->condition("c.entity_id", $uid)
  ->condition("c.bundle", "user");
  $user_country = $c_query->execute()->fetchField();

  $query = db_select("node", "n");
  $query->leftJoin("field_data_field_call_id", "ci", "ci.entity_id = n.nid");
  $query->leftJoin("field_data_field_funding_agency", "fa", "fa.entity_id = n.nid");
  $query->leftJoin('field_data_field_country', 'co', "co.entity_id = fa.field_funding_agency_target_id");
  $query->leftJoin('field_data_field_country_specific', 'cs', "cs.entity_id = n.nid");
  $query
  ->fields("n", array("title", "nid"))
//  ->fields("co", array("field_country_iso2"))
  ->condition("ci.field_call_id_target_id", $nid)
  ->condition("co.bundle", "organisation")
  ->condition("n.type", "call_funder_page");
   $db_or = db_or();
   $db_or->condition("co.field_country_iso2", $user_country);
   $db_or->condition("cs.field_country_specific_value", 0);
  $query->condition($db_or);
  $result = $query->execute()->fetchAll();
  $options = array();
  foreach($result as $row){
    $options[$row->nid] = $row->title;
  }
  return $options;
}

/**
 * Param Funding agency nid
 * Returns the funding scheme titles
 */
function mkb_application_get_fs_options($nid) {
  $query = db_select("field_data_field_funder_page", "fa");
  $query->leftJoin("node", "n", "fa.entity_id = n.nid");
  $query
  ->fields("n", array("title", "nid"))
  ->condition("fa.field_funder_page_target_id", $nid)
  ->condition("fa.bundle", "funding_scheme");
  $result = $query->execute()->fetchAll();

  $options = array();
  foreach($result as $row){
    $options[$row->nid] = $row->title;
  }
  return $options;
}


/**
 * @param $gid
 *   Group id (node id of group).
 * @param $content_type
 *   Content type.
 * @return $group_content
 *   All node ids of this content type pointing to this group with group_audience field.
 */
function mkb_application_get_group_content($gid, $type){
  $query = db_select("og_membership", "og_membership");
  $query ->leftJoin("node", "node", "node.nid = og_membership.etid");
  $query ->addField("node", "nid", "nid");
  $query
  ->condition("og_membership.gid", $gid)
  ->condition("og_membership.entity_type", 'node')
  ->condition("node.type", $type);
  $result = $query->execute()->fetchAll();
  $group_content = array();
  foreach ($result as $row){
    $group_content[] = $row->nid;
  }
  return $group_content;
}

/**
  * Return my_organisation title from user uid
 */
function mkb_application_get_my_org($uid){
  $query = db_select("profile", "profile");
  $query->leftJoin("field_data_field_my_organisation", "my_org", "my_org.entity_id = profile.pid");
  $query->leftJoin("node", "node", "node.nid = my_org.field_my_organisation_target_id");
  $query->addField("node", "title", "my_org");
  $query
  ->condition("profile.uid", $uid)
  ->condition("node.type", "organisation");
  $result = $query->execute();
  $my_org = $result->fetchField();
  return $my_org;
}

/**
  * Return topics
 */
function mkb_application_get_topics($nid){
  $query = db_select("field_data_field_call_id", "ci");
  $query->leftJoin("node", "node", "node.nid = ci.entity_id");
  $query->leftJoin("field_data_field_topic_parent", "tp", "tp.entity_id = ci.entity_id");
  $query->leftJoin("field_data_field_topic_level", "tl", "tl.entity_id = ci.entity_id");
  $query->leftJoin("field_data_field_topic_weight", "tw", "tw.entity_id = ci.entity_id");
  $query->addField("tp", "field_topic_parent_target_id", "pid");
  $query->addField("node", "nid", "nid");
  $query->addField("node", "title", "title");
  $query
  ->condition("ci.bundle", "call_topic")
  ->condition("ci.field_call_id_target_id", $nid)
  ->orderBy('tp.field_topic_parent_target_id', 'ASC')
  ->orderBy('tw.field_topic_weight_value', 'ASC');
  $result = $query->execute();
  $data = $result->fetchAll();
  $data_copy = $data;

  $topics = array();
  foreach ($data as $row){
    if(!$row->pid){
      $topics[$row->nid] = "<b>" . $row->title . "</b>";
      foreach ($data_copy as $row_copy){
        if($row_copy->pid == $row->nid){
          $topics[$row_copy->nid] = $row_copy->title;
        }
      }
    }
  }
  return $topics;
}

/**
  * Return true if logged-in-user is administrator, project coordinator or project editor in the group,
  * else return false
 */
function mkb_application_user_og_auth($gid){
  $uid = $GLOBALS['user']->uid;
  $query = db_select("og_users_roles", "og_users_roles");
  $query->leftJoin("og_role", "og_role", "og_role.rid = og_users_roles.rid");
  $query
  ->fields("og_users_roles", array("rid"))
  ->condition("og_users_roles.uid", $uid, "=")
  ->condition("og_users_roles.gid", $gid, "=");
  $db_or = db_or();
  $db_or->condition("og_role.name", "administrator");
  $db_or->condition("og_role.name", "project coordinator");
  $db_or->condition("og_role.name", "project editor");
  $query->condition($db_or);
  $result = $query->execute();
  $num_of_results = $result->rowCount();
  if($num_of_results != 0) return TRUE;
  else return FALSE;
}
/**
  * Return Group -> call-main-page: call_open
 */
function mkb_application_call_open(){
  $query = db_select("field_data_field_call_open", "ca");
  $query->leftJoin("node", "n", "ca.entity_id = n.nid");
  $query
  ->fields("ca", array("entity_id"))
  ->fields("n", array("title"))
  ->condition("ca.field_call_open_value", "1");
  $result = $query->execute();
  $data = $result->fetchAll();
  return $data;
}

/**
 * Returns the call-main-page nid
 */
function mkb_application_get_call_main_nid($gid) {
  $query = db_select("field_data_field_group_application", "a");
  $query
  ->fields("a", array("field_group_application_target_id"))
  ->condition("a.entity_id", $gid, "=");
  $result = $query->execute();
  if ($result) {
    $app_id = $result->fetchField();
    return $app_id;
  }
  else return FALSE;
}

/**
 * Returns value from a single value field
 */
function mkb_application_get_value($nid, $field_name) {
  $query = db_select("field_data_field_" . $field_name, "x");
  $query
  ->fields("x", array("field_" . $field_name . "_value"))
  ->condition("x.entity_id", $nid, "=");
  $result = $query->execute();
  $value = $result->fetchField();
  return $value;
}

/**
 * Returns values aliased as "delta" and "value" from a multiple value field
 */
function mkb_application_get_values($nid, $field_name) {
  $query = db_select("field_data_field_" . $field_name, "x");
  $query->addField("x", "delta", "delta");
  $query->addField("x", "field_" . $field_name . "_value", "value");
  $query->condition("x.entity_id", $nid, "=");
  $query->orderBy("delta");
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * Returns disabled
 */
function mkb_application_get_disabled($nid, $row_name) {
  $clm_str = $row_name . "_value";
  $query = db_select("field_data_" . $row_name, "x");
  $query
  ->fields("x", array("delta", $clm_str))
  ->condition("x.entity_id", $nid, "=");
  $result = $query->execute()->fetchAll();;
  $disabled = array(false, true, false, true, false, true); // table column 1, 3, 5 never disabled
  foreach($result as $row){
    $disabled[2*($row->$clm_str - 1) + 1] = false;  // table column 2, 4, 6 = array-index 1, 3, 5
  }
  return $disabled;
}

/**
 * Returns is_application. True if a call-main-page is chosen in group, else false.
 * Used in Group workspace sidebar block.
 */
function mkb_application_group_is_application($gid) {
  $query = db_select("field_data_field_group_application", "a");
  $query
  ->fields("a", array("entity_id"))
  ->condition("a.entity_id", $gid, "=");
  $result = $query->execute()->fetchField();
  if(is_numeric($result)) return true;
  return $result;
}

function mkb_application_get_content_type_labels($content_type){
  $fields = array();
  $instances = field_info_instances('node', $content_type);
  $extra_fields = field_info_extra_fields('node', $content_type, 'form');

  // Fields.
  foreach ($instances as $name => $instance) {
    $field = field_info_field($instance['field_name']);
    $fields[$instance['field_name']] = array(
      'title' => $instance['label'],
      'weight' => $instance['widget']['weight'],
    );
  }

  // Non-field elements.
  foreach ($extra_fields as $name => $extra_field) {
    $fields[$name] = array(
      'title' => $extra_field['label'],
      //'weight' => $extra_field['weight'],
    );
  }
    return $fields;
}

function mkb_application_get_call_from_budget_id($nid){
  $query = db_select("og_membership", "o");
  $query
  ->fields("o", array("gid"))
  ->condition("o.etid", $nid, "=")
  ->condition("o.entity_type", "node", "=");
  $result = $query->execute();
  $gid = $result->fetchField();
  return $gid;
}


/**
 * Param application partner budget nid
 */
function mkb_application_get_budget_table($nid){
  //ROW LABELS
  $row_labels = mkb_application_get_content_type_labels("application_partner_budget");
  //dpm($row_labels);

  // COL LABELS
  $gid = mkb_application_get_call_from_budget_id($nid);
  $call_id = mkb_application_get_call_main_nid($gid);

  //Budget data
  $budget_node = node_load($nid);

  $call_node = node_load($call_id);
  $categories = field_get_items('node', $call_node, 'field_budget_categories');

  //ROW[0]
  $table[0][0] = $nid;
  $table[0][1] = "Cost item";
  for($i=0; $i<count($categories); $i++){
    $table[0][$i+2] = $categories[$i]['value'];
  }

  $num_cat = count($categories);
  if($num_cat > 1){
    $table[0][$num_cat+2] = "Sum (1000 .)";
  }

  //ROW[1]
  for($i=0; $i<$num_cat; $i++){
    $table[1][$i*2] = "Total";
    $table[1][$i*2+1] = "Requested";
  }
  if($num_cat > 1){
    $table[1][$i*2] = "Total";
    $table[1][$i*2+1] = "Requested";
  }

  //Budget data
  $num_col = $num_cat*2;
  $row_names = array("pm", "pc", "ts", "cs", "eq", "sc", "oc", "ic");
  for($i=0; $i<count($row_names); $i++){
    $row_name = "field_bud_" . $row_names[$i];
    $table[$i+2][0] = $row_labels[$row_name]['title'];
    $total_sum = 0;
    $requested_sum = 0;
    for($j=0; $j<$num_col; $j++){
        //skip first 2 rows and first col
      $table[$i+2][$j+1] = 0;
      if(isset($budget_node->{$row_name}['und'][$j]['value'])){
        $table[$i+2][$j+1] = $budget_node->{$row_name}['und'][$j]['value'];
        // No sum if only one category
        if($num_cat > 1){
          //even col number
          if($j%2){
            $requested_sum += $budget_node->{$row_name}['und'][$j]['value'];
          }
          //odd col number
          else{
            $total_sum += $budget_node->{$row_name}['und'][$j]['value'];
          }
        }
      }
    }
    //format and add row sums
    if($num_cat > 1){
      $formatted_total_sum = number_format($total_sum, 1);
      $table[$i+2][$num_col+1] = $formatted_total_sum;
      $formatted_requested_sum = number_format($requested_sum, 1);
      $table[$i+2][$num_col+2] = $formatted_requested_sum;
    }
  }

  //COL SUM
    //Add the two sum col to number of col
  if($num_cat > 1) $num_col += 2;
  $col_sum = array();
    //calculate col sums
    //skip pm
  for($i=1; $i<count($row_names); $i++){
    for($j=0; $j<$num_col; $j++){
      if(!isset($col_sum[$j])){
        $col_sum[$j] = 0;
      }
      $col_sum[$j] += $table[$i+2][$j+1];
    }
  }
  //add col sum to table
  $table[count($row_names)+2][0] = "Sum (1000 .)";
  for($i=0; $i<count($col_sum); $i++){
    $formatted_col_sum = number_format($col_sum[$i], 1);
    $table[count($row_names)+2][$i+1] = $formatted_col_sum;
  }

  return $table;
}

function mkb_application_print_budget_table($table){
print '<table>';
  print '<tbody>';
  for($i=0; $i<count($table); $i++){
    if($i>1){
      if($i % 2){
        print '<tr class="even">';
      }
      else{
        print '<tr class="odd">';
      }
    }
    else{
      print "<tr>";
    }
    for($j=0; $j<count($table[$i]); $j++){
      if($i==0){
        if($j==1){
          print '<th rowspan="2" class="budget_table_0_1">' . $table[$i][$j] . '</th>';
        }
        elseif($j>1){
          print '<th colspan="2" class="budget_table_0">' . $table[$i][$j] . '</th>';
        }
      }
      elseif($i==1){
        print '<th class="td_align_right">' . $table[$i][$j] . '</th>';
      }
      else{
        if($j==0){
          print '<td>' . $table[$i][$j] . '</td>';
        }
        else{
          print '<td class="td_align_right">' . $table[$i][$j] . '</td>';
        }
      }
    }
    print "</tr>";
  }
  print "</tbody>";
print "</table>";
print "</br>";
}
