<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Alter form for application_partner_budget
 *
 * @param $form
 *   Form
 * @param $form_state
 *   Form state
 * @param $form_id
 *   Form id
 * @return $form
 *   Altered form.
 */
function mkb_application_partner_budget($form, $form_state, $form_id){
	if (isset($_SESSION["mkb_gid"])) {
		$gid = $_SESSION["mkb_gid"];
		$nid = mkb_application_get_call_main_nid($gid);

		//Set gid in group audience and remove group audience from form
		$form['og_group_ref']['und'][0]['default']['#default_value'][0] = $gid;
		$form['og_group_ref']['#access'] = FALSE;

		//SET TITLE
		$form['title']['#default_value'] = 'Partner budget';
		$form['title']['#disabled'] = TRUE;

		//GET BUDGET CATEGORIES, DESCRIPTIONS AND IN KIND
		$budget_categories = mkb_application_get_values($nid, 'budget_categories');
		$budget_cat_descrip = mkb_application_get_values($nid, 'budget_cat_descrip');
		$budget_in_kind = mkb_application_get_value($nid, 'budget_in_kind');

		//BUDGET_WRAPPER
		$form['budget'] = array(
			//'#weight' => '3',
			'#type' => 'fieldset',
			'#title' =>'Budget',
			'#prefix' => '<div id="budget_wrapper-div">',
			'#suffix' => '</div>',
			'#collapsible' => FALSE,
			'#collapsed' => FALSE,
		);

		//FUNDING AGENCY - Selectbox
		$form['budget']["field_funder_page"] = $form["field_funder_page"];
		unset( $form["field_funder_page"]);

		//FUNDING AGENCY - Add ajax
		$form['budget']["field_funder_page"]["und"]["#ajax"] = array(
			'callback' => 'budget_wrapper_callback',
			'wrapper' => 'budget_wrapper-div',
			'method' => 'replace',
			'effect' => 'fade',
		);

		// Get user id from url and set $_SESSION["app_uid"] for form after ajax
		// $_SESSION["app_uid"] is unset in mkb_application.module function mkb_application_node_presave($node)
                $id = arg(3);
                if($id[0] == 'u'){
                  $uid = substr($id, 2, strlen($id));
                }

		if(isset($uid) && is_numeric($uid)){
			$_SESSION["app_uid"] = $uid;
		}
		// load user id from session
		if(isset($_SESSION["app_uid"])) $account = user_load($_SESSION["app_uid"]);
		else $account = user_load($form['uid']['#value']);

		//FUNDING AGENCY - Setup options
		$user_roles = og_get_user_roles('node', $gid, $account->uid, FALSE, TRUE);
		$fa_options = array();
		// ICT-AGRI: Special for SmartAgriFood call
		$gnode = node_load($gid);
		$call_id = $gnode -> field_group_application['und'][0]['target_id'];
        if ($call_id == 13796) {
 		  // ICT-AGRI: Project coordinator is forced to seek funding from SmartAgriFood
          if(in_array('project coordinator', $user_roles)){
            $fa_options = array('14139' => 'SmartAgriFood');
          }
 		  // ICT-AGRI: Project partners cannot seek funding from SmartAgriFood
          else {
		    $fa_options = mkb_application_get_fa_options_by_country($nid, $account->uid);
		    unset($fa_options['14139']);
          }
		}
        else {
		  $fa_options = mkb_application_get_fa_options_by_country($nid, $account->uid);
        }
		$form['budget']["field_funder_page"]["und"]["#options"] = $fa_options;
		//FUNDING SCHEME - Selectbox
		$form['budget']["field_bud_funding_scheme"] = $form["field_bud_funding_scheme"];
		$form['budget']["field_bud_funding_scheme"]["und"]["#options"] = array();
		unset($form["field_bud_funding_scheme"]);

		//FUNDING SCHEME - Visibility
		$fs_visible = TRUE;
		$table_visible = true;
		if(isset($_POST["field_funder_page"]["und"])){
			if($_POST["field_funder_page"]["und"] == $form['budget']["field_funder_page"]["und"]["#default_value"][0]
					|| (isset($_SESSION["fa_default"]) && $_SESSION["fa_default"] == $_POST["field_funder_page"]["und"])){
				//dpm("nothing has changed");
				$fa_default = $_POST["field_funder_page"]["und"];
				$form['budget']["field_bud_funding_scheme"]["und"]["#options"] = mkb_application_get_fs_options($fa_default);
			}
			else{
				//dpm("new funding agency selected");
				$fa_default = $_POST["field_funder_page"]["und"];
				$form['budget']["field_bud_funding_scheme"]["und"]["#options"] = mkb_application_get_fs_options($fa_default);
				$form['budget']["field_bud_funding_scheme"]["und"]["#options"] = array("_none" => "- Select -") + $form['budget']["field_bud_funding_scheme"]["und"]["#options"];
				$table_visible = FALSE;
			}
			$_SESSION["fa_default"] = $_POST["field_funder_page"]["und"];
		}
		else{
			if(isset($form['budget']["field_funder_page"]["und"]["#default_value"][0])){
				//dpm("default value");
				$fa_default = $form['budget']["field_funder_page"]["und"]["#default_value"][0];
				$form['budget']["field_bud_funding_scheme"]["und"]["#options"] = mkb_application_get_fs_options($fa_default);
			}
			else{
				//dpm("no default values yet");
				$form['budget']["field_funder_page"]["und"]["#options"] = array("_none" => "- Select -") + $form['budget']["field_funder_page"]["und"]["#options"];
				$fs_visible = FALSE;
				$table_visible = FALSE;
			}
			unset($_SESSION["fa_default"]);
		}

		//FUNDING SCHEME - Add ajax
		$form['budget']["field_bud_funding_scheme"]["und"]["#ajax"] = array(
			'callback' => 'budget_wrapper_callback',
			'wrapper' => 'budget_wrapper-div',
			'method' => 'replace',
			'effect' => 'fade',
		);

		//FUNDING SCHEME - Visibility
		$form['budget']["field_bud_funding_scheme"]['und']['#access'] = TRUE;
		if(!$fs_visible){
			$form['budget']["field_bud_funding_scheme"]['und']['#access'] = FALSE;
		}

		//TABLE - Get funding scheme nid (fs_nid)
		if(isset($_POST["field_bud_funding_scheme"]["und"]) && $_POST["field_bud_funding_scheme"]["und"] != "_none"){
			if($_POST["field_bud_funding_scheme"]["und"] == $form['budget']["field_bud_funding_scheme"]["und"]["#default_value"][0]){
				//nothing has changed
				$fs_nid = $_POST["field_bud_funding_scheme"]["und"];
			}
			else{
				//new funding scheme selected
				$fs_nid = $_POST["field_bud_funding_scheme"]["und"];
			}
		}
		elseif(!isset($_POST["field_bud_funding_scheme"]["und"])){
			if(isset($form['budget']["field_bud_funding_scheme"]["und"]["#default_value"][0])){
				//default value
				$fs_nid = $form['budget']["field_bud_funding_scheme"]["und"]["#default_value"][0];
			}
			else{
				//no default values yet
				$table_visible = false;
			}
		}
		elseif($_POST["field_bud_funding_scheme"]["und"] == "_none"){
			//has default value but - Select - selected in funding scheme
			$table_visible = false;
		}

		//TABLE - FUNDING SCHEME - Conditions
		//TABLE - CALL FUNDING PAGE - Contact persons
		if(isset($fa_default) && $table_visible){
		  // Funding scheme conditions
		  $funding_scheme = node_load($fs_nid);
		  $funding_scheme_wrapper = entity_metadata_wrapper('node', $funding_scheme);
		  if (!empty($funding_scheme->field_fun_schc)) $funding_scheme_conditions = $funding_scheme_wrapper->field_fun_schc->value->value();
		  if (!isset($funding_scheme_conditions)) $funding_scheme_conditions = '';
		  // Funder page: Contact persons and documents
		  $funder_page = node_load($fa_default);
		  $funder_page_wrapper = entity_metadata_wrapper('node', $funder_page);
		  // Contact persons list
		  $contact_persons = $funder_page_wrapper->field_contact_persons->value();
		  foreach($contact_persons as $contact_person){
			  $list_of_paths[] = l($contact_person->realname, "user-profile/" . $contact_person->uid);
		  }
		  $contact_list = theme("item_list", array(
				 'items' => $list_of_paths,
				 'type' => 'ul',
				 'title' => 'Contact persons',
				 ));
		  // Funder page documents
		  $documents = $funder_page_wrapper->field_attachments->value();
		  $list_of_paths = array();
		  foreach($documents as $file){
		    $link = !empty($file['description']) ? $file['description'] : $file['filename'];
		    $file_uri = $file['uri'];
		    $file_path = file_create_url($file_uri);
		    $list_of_paths[] = l($link, $file_path);
		  }
		  if(!empty($list_of_paths)) {
		    $document_list = theme("item_list", array(
				 'items' => $list_of_paths,
				 'type' => 'ul',
				 'title' => 'Documents',
		    ));
		  }
		  else $document_list = '';
		}

		//TABLE - Headers
		$table_header = "";
		if($table_visible){
			$table_header .= '<tr><th rowspan="2">Project activities</td>';
			foreach($budget_categories as $row) {
					$table_header .= '<th colspan="2">' . $row->value . '</th>';
				}
			$table_header .= '</tr>';
			$table_header .= '<tr>';
			foreach($budget_cat_descrip as $row) {
					$table_header .= '<td colspan="2">' . wordwrap($row->value,40,'<br>') . '</td>';
				}
			$table_header .= '</tr>';
			$table_header .= '<tr><th>Cost item</th>';
			foreach($budget_categories as $row) {
						$table_header .= '<th>Total</th>';
						$table_header .= '<th>Requested</th>';
					}
			$table_header .= '</tr>';
		}

		// CREATE TABLE ROW WITH MAX FUNDED
		if ($table_visible) {
			$max_request = mkb_application_get_values($fs_nid, 'fun_rm');
			$max_str = '<tr><td>Max funded</td>';
			for ($i=0; $i<count($budget_categories); $i++) {
				if (isset($max_request[$i])) $max_str.= '<td>&nbsp;</td><td>' . $max_request[$i]->value . ' %</td>';
				else $max_str.= '<td>&nbsp;</td><td>&nbsp;</td>';
		 }
		 $max_str.= '</tr>';
		}
		else {
			$max_request = null;
			$max_str = '';
		}

		//TABLE_WRAPPER - Fieldset
		$form['budget']["table_wrapper"] = array(
			'#tree' => FALSE,
			'#weight' => '10',
			'#type' => 'table',
			//'#title' => 'Budget table',
			'#collapsible' => TRUE,
			//'#collapsed' => FALSE,
			'#prefix' => '<div id="budget_table-div"><table><tbody>' . $table_header,
			'#suffix' => $max_str . '</tbody></table></div>',
//        '#suffix' => $fs_condition_str . $cfp_contact_persons_str .'</tbody></table></div>',
		);

		//TABLE - rebuild table rows from fs nid
		$form['budget']['table_wrapper']['table'] = array();
		if($table_visible){
			$form['budget']['table_wrapper']['table']['field_bud_pm'] = budget_table_row('pm', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_pc'] = budget_table_row('pc', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_ts'] = budget_table_row('ts', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_cs'] = budget_table_row('cs', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_eq'] = budget_table_row('eq', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_sc'] = budget_table_row('sc', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_oc'] = budget_table_row('oc', $fs_nid, $form, count($budget_categories));
			$form['budget']['table_wrapper']['table']['field_bud_ic'] = budget_table_row('ic', $fs_nid, $form, count($budget_categories));
		}

		if(!$fs_visible){
			$form['budget']['table_wrapper']['#collapsed'] = TRUE;
			$form['budget']['table_wrapper']['#states'] = array('visible' => FALSE);
//         $form['budget']['fa_info']['#collapsed'] = TRUE;
//         $form['budget']['fa_info']['#states'] = array('visible' => FALSE);
		}
		else{
			$form['budget']['table_wrapper']['#collapsed'] = FALSE;
			$form['budget']['table_wrapper']['#states'] = array('visible' => TRUE);
//         $form['budget']['fa_info']['#collapsed'] = FALSE;
//         $form['budget']['fa_info']['#states'] = array('visible' => TRUE);
		}
		if($table_visible){
			//FUNDING AGENCY CONDITIONS AND CONTACT
			$form['budget']['fa_info'] = array(
				'#weight' => '8',
				'#type' => 'fieldset',
				'#title' => 'Funding agency conditions and contact persons',
				'#description' => $funding_scheme_conditions . '<br>' . $document_list . '<br>' . $contact_list,
				'#collapsible' => FALSE,
				//'#collapsed' => FALSE,
				'#states' => array('visible' => FALSE),
			);
		}

		//Remove budget table fields from form
		unset($form["field_bud_pm"]);
		unset($form["field_bud_pc"]);
		unset($form["field_bud_ts"]);
		unset($form["field_bud_cs"]);
		unset($form["field_bud_eq"]);
		unset($form["field_bud_sc"]);
		unset($form["field_bud_oc"]);
		unset($form["field_bud_ic"]);

	}
	return $form;
}

/**
* Callback element needs only select the portion of the form to be updated.
* Since #ajax['callback'] return can be HTML or a renderable array (or an
* array of commands), we can just return a piece of the form.
*/
function budget_wrapper_callback($form, $form_state) {
  return render($form["budget"]);
}

function funding_scheme_callback($form, $form_state) {
  return render($form['budget']);
}

/**
 * Creates rows in the budget table
 * @param unknown_type $row_name
 * @param unknown_type $form
 */
function budget_table_row($row_name, $fs_nid, $form, $n_budget_categories) {
  //Label
  $label = $form['field_bud_' . $row_name]['und']['#title'];

  //Disabled in funding scheme
  $disabled = mkb_application_get_disabled($fs_nid, 'field_fun_' . $row_name);
  $element = array(
      '#tree' => TRUE,
      '#type' => 'container',
      '#attributes' => array(
          'class' => array(
              0 => 'field-type-number-decimal',
              1 => 'field-name-field-bud-' . $row_name,
              2 => 'field-widget-number',
              )
          ),
      '#language' => 'und',
      );

  $element['und'] = array();

  for ($i=0; $i<6; $i++) {
    if($form['field_bud_' . $row_name]['und'][$i]['value']['#default_value']){
      $default_value = $form['field_bud_' . $row_name]['und'][$i]['value']['#default_value'];
    }
    else{
      $default_value = 0.0;
    }
    if($disabled[$i]){
      $default_value = 0.0;
    }
    if ($i < 2*$n_budget_categories) $access = 1; else $access = 0;
    $element['und'][$i] = array();
    $element['und'][$i]['value'] = array(
      '#type' => 'textfield',
      '#delta' => $i,
      '#default_value' => $default_value,
      '#prefix' => '<td>',
      '#suffix' => '</td>',
      '#size' => 14,
      '#maxlength' => 12,
      '#disabled' => $disabled[$i],
      '#number_type' => 'decimal',
      '#element_validate' => array('number_field_widget_validate'),
      '#field_parents' => array(),
      '#field_name' => 'field_bud_' . $row_name,
      '#language' => 'und',
      '#scale' => 1,
      '#precision' => 10,
      '#access' => $access,
    );

     if ($i == 0) $element['und'][$i]['value']["#prefix"] = '<tr><td>' . $label . '</td><td>';
     if ($i == 5) $element['und'][$i]['value']["#sufffix"] = '</td></tr>';
  }
  return $element;
}
