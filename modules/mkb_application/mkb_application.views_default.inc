<?php
/**
 * @file
 * mkb_application.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mkb_application_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'application_ws_call_funder_page';
  $view->description = 'info from call-funder-page';
  $view->tag = 'mkb application';
  $view->base_table = 'node';
  $view->human_name = 'Application ws call-funder-page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'call-funder-page header';
  $handler->display->display_options['header']['area']['content'] = '<h3>Funding agencies and funding</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_group_application_target_id']['id'] = 'field_group_application_target_id';
  $handler->display->display_options['relationships']['field_group_application_target_id']['table'] = 'field_data_field_group_application';
  $handler->display->display_options['relationships']['field_group_application_target_id']['field'] = 'field_group_application_target_id';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_call_indentifier_node']['id'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['relationships']['reverse_field_call_indentifier_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_call_indentifier_node']['field'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['relationships']['reverse_field_call_indentifier_node']['relationship'] = 'field_group_application_target_id';
  /* Field: Content: Funding agency */
  $handler->display->display_options['fields']['field_funding_agency']['id'] = 'field_funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['table'] = 'field_data_field_funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['field'] = 'field_funding_agency';
  $handler->display->display_options['fields']['field_funding_agency']['relationship'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['fields']['field_funding_agency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_funding_agency']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Funding */
  $handler->display->display_options['fields']['field_funding']['id'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['table'] = 'field_data_field_funding';
  $handler->display->display_options['fields']['field_funding']['field'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['relationship'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['fields']['field_funding']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_funding']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Conditions short */
  $handler->display->display_options['fields']['field_conditions_short']['id'] = 'field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['table'] = 'field_data_field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['field'] = 'field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['relationship'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['fields']['field_conditions_short']['element_label_colon'] = FALSE;
  /* Field: Content: Contact persons */
  $handler->display->display_options['fields']['field_contact_persons']['id'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['table'] = 'field_data_field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['field'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['relationship'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['fields']['field_contact_persons']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_persons']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact_persons']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_persons']['multi_type'] = 'ol';
  /* Sort criterion: Content: Funding agency (field_funding_agency) */
  $handler->display->display_options['sorts']['field_funding_agency_target_id']['id'] = 'field_funding_agency_target_id';
  $handler->display->display_options['sorts']['field_funding_agency_target_id']['table'] = 'field_data_field_funding_agency';
  $handler->display->display_options['sorts']['field_funding_agency_target_id']['field'] = 'field_funding_agency_target_id';
  $handler->display->display_options['sorts']['field_funding_agency_target_id']['relationship'] = 'reverse_field_call_indentifier_node';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_call_indentifier_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_funder_page' => 'call_funder_page',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  $export['application_ws_call_funder_page'] = $view;

  $view = new view();
  $view->name = 'application_ws_call_main_page';
  $view->description = 'info from call-main-page';
  $view->tag = 'mkb application';
  $view->base_table = 'node';
  $view->human_name = 'Application ws call-main-page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_funding_mode' => 'field_funding_mode',
    'field_stages' => 'field_stages',
    'field_call_open' => 'field_call_open',
    'field_date_launch' => 'field_date_launch',
    'field_date_pre_preposals_open' => 'field_date_pre_preposals_open',
    'field_date_pre_preposals_close' => 'field_date_pre_preposals_close',
    'field_date_pre_preposals_notific' => 'field_date_pre_preposals_notific',
    'field_date_full_proposals_open' => 'field_date_full_proposals_open',
    'field_date_full_proposals_close' => 'field_date_full_proposals_close',
    'field_date_full_proposals_notifi' => 'field_date_full_proposals_notifi',
  );
  $handler->display->display_options['row_options']['separator'] = '<br/>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Call description header';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2>Call description</h2>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_group_application_target_id']['id'] = 'field_group_application_target_id';
  $handler->display->display_options['relationships']['field_group_application_target_id']['table'] = 'field_data_field_group_application';
  $handler->display->display_options['relationships']['field_group_application_target_id']['field'] = 'field_group_application_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<b>[title]</b>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Funding mode */
  $handler->display->display_options['fields']['field_funding_mode']['id'] = 'field_funding_mode';
  $handler->display->display_options['fields']['field_funding_mode']['table'] = 'field_data_field_funding_mode';
  $handler->display->display_options['fields']['field_funding_mode']['field'] = 'field_funding_mode';
  $handler->display->display_options['fields']['field_funding_mode']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_funding_mode']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Number of call stages */
  $handler->display->display_options['fields']['field_stages']['id'] = 'field_stages';
  $handler->display->display_options['fields']['field_stages']['table'] = 'field_data_field_stages';
  $handler->display->display_options['fields']['field_stages']['field'] = 'field_stages';
  $handler->display->display_options['fields']['field_stages']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_stages']['label'] = 'Stages';
  /* Field: Content: Call open creating application */
  $handler->display->display_options['fields']['field_call_open']['id'] = 'field_call_open';
  $handler->display->display_options['fields']['field_call_open']['table'] = 'field_data_field_call_open';
  $handler->display->display_options['fields']['field_call_open']['field'] = 'field_call_open';
  $handler->display->display_options['fields']['field_call_open']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_call_open']['label'] = 'Call open';
  $handler->display->display_options['fields']['field_call_open']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Call open';
  /* Field: Time schedule */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Time schedule';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<br/><b>Time schedule</b>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Date launch */
  $handler->display->display_options['fields']['field_date_launch']['id'] = 'field_date_launch';
  $handler->display->display_options['fields']['field_date_launch']['table'] = 'field_data_field_date_launch';
  $handler->display->display_options['fields']['field_date_launch']['field'] = 'field_date_launch';
  $handler->display->display_options['fields']['field_date_launch']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_launch']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-proposals open */
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['id'] = 'field_date_pre_preposals_open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['table'] = 'field_data_field_date_pre_preposals_open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['field'] = 'field_date_pre_preposals_open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['label'] = 'Date pre preposals open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-proposals close */
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['id'] = 'field_date_pre_preposals_close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['table'] = 'field_data_field_date_pre_preposals_close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['field'] = 'field_date_pre_preposals_close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['label'] = 'Date pre preposals close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-proposals notification */
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['id'] = 'field_date_pre_preposals_notific';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['table'] = 'field_data_field_date_pre_preposals_notific';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['field'] = 'field_date_pre_preposals_notific';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['label'] = 'Date pre preposals notification';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date full proposals open */
  $handler->display->display_options['fields']['field_date_full_proposals_open']['id'] = 'field_date_full_proposals_open';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['table'] = 'field_data_field_date_full_proposals_open';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['field'] = 'field_date_full_proposals_open';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date full proposals close */
  $handler->display->display_options['fields']['field_date_full_proposals_close']['id'] = 'field_date_full_proposals_close';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['table'] = 'field_data_field_date_full_proposals_close';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['field'] = 'field_date_full_proposals_close';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date full proposals notification */
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['id'] = 'field_date_full_proposals_notifi';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['table'] = 'field_data_field_date_full_proposals_notifi';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['field'] = 'field_date_full_proposals_notifi';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_main_page' => 'call_main_page',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['application_ws_call_main_page'] = $view;

  return $export;
}
