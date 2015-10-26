<?php
/**
 * @file
 * mkb_call_admin.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mkb_call_admin_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'call_coordinator_mail';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Call coordinator mail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Call: Mail to coordinators';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    8 => '8',
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Call';
  $handler->display->display_options['header']['area']['content'] = '<strong>[field_group_application]</strong>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: Global: Send e-mail */
  $handler->display->display_options['fields']['views_send']['id'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['table'] = 'views';
  $handler->display->display_options['fields']['views_send']['field'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['label'] = 'Email';
  /* Field: OG membership: Group ID */
  $handler->display->display_options['fields']['gid']['id'] = 'gid';
  $handler->display->display_options['fields']['gid']['table'] = 'og_membership';
  $handler->display->display_options['fields']['gid']['field'] = 'gid';
  $handler->display->display_options['fields']['gid']['label'] = 'ID';
  $handler->display->display_options['fields']['gid']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['path'] = 'groups/workspace/application_page/[gid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Coordinator';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Content: Submitted */
  $handler->display->display_options['fields']['field_app_submitted']['id'] = 'field_app_submitted';
  $handler->display->display_options['fields']['field_app_submitted']['table'] = 'field_data_field_app_submitted';
  $handler->display->display_options['fields']['field_app_submitted']['field'] = 'field_app_submitted';
  $handler->display->display_options['fields']['field_app_submitted']['label'] = 'Submit';
  /* Field: Content: Submit time */
  $handler->display->display_options['fields']['field_app_submit_time']['id'] = 'field_app_submit_time';
  $handler->display->display_options['fields']['field_app_submit_time']['table'] = 'field_data_field_app_submit_time';
  $handler->display->display_options['fields']['field_app_submit_time']['field'] = 'field_app_submit_time';
  $handler->display->display_options['fields']['field_app_submit_time']['label'] = 'Submit time 1';
  $handler->display->display_options['fields']['field_app_submit_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_submit_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: app_selected_1 */
  $handler->display->display_options['fields']['field_app_selected_1']['id'] = 'field_app_selected_1';
  $handler->display->display_options['fields']['field_app_selected_1']['table'] = 'field_data_field_app_selected_1';
  $handler->display->display_options['fields']['field_app_selected_1']['field'] = 'field_app_selected_1';
  $handler->display->display_options['fields']['field_app_selected_1']['label'] = 'Selected';
  /* Field: Content: Call identifier */
  $handler->display->display_options['fields']['field_group_application']['id'] = 'field_group_application';
  $handler->display->display_options['fields']['field_group_application']['table'] = 'field_data_field_group_application';
  $handler->display->display_options['fields']['field_group_application']['field'] = 'field_group_application';
  $handler->display->display_options['fields']['field_group_application']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['field_group_application']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_group_application']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Description of work */
  $handler->display->display_options['fields']['field_app_dow']['id'] = 'field_app_dow';
  $handler->display->display_options['fields']['field_app_dow']['table'] = 'field_data_field_app_dow';
  $handler->display->display_options['fields']['field_app_dow']['field'] = 'field_app_dow';
  $handler->display->display_options['fields']['field_app_dow']['label'] = 'DOW';
  $handler->display->display_options['fields']['field_app_dow']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_app_dow']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_app_dow']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_app_dow']['click_sort_column'] = 'fid';
  /* Sort criterion: OG membership: Group ID */
  $handler->display->display_options['sorts']['gid']['id'] = 'gid';
  $handler->display->display_options['sorts']['gid']['table'] = 'og_membership';
  $handler->display->display_options['sorts']['gid']['field'] = 'gid';
  /* Contextual filter: Content: Call identifier (field_group_application) */
  $handler->display->display_options['arguments']['field_group_application_target_id']['id'] = 'field_group_application_target_id';
  $handler->display->display_options['arguments']['field_group_application_target_id']['table'] = 'field_data_field_group_application';
  $handler->display->display_options['arguments']['field_group_application_target_id']['field'] = 'field_group_application_target_id';
  $handler->display->display_options['arguments']['field_group_application_target_id']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['arguments']['field_group_application_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_group_application_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_group_application_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_group_application_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_group_application_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application_project_info' => 'application_project_info',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: OG membership: Group ID */
  $handler->display->display_options['filters']['gid']['id'] = 'gid';
  $handler->display->display_options['filters']['gid']['table'] = 'og_membership';
  $handler->display->display_options['filters']['gid']['field'] = 'gid';
  $handler->display->display_options['filters']['gid']['operator'] = '>';
  $handler->display->display_options['filters']['gid']['value']['value'] = '0';
  $handler->display->display_options['filters']['gid']['group'] = 1;
  /* Filter criterion: Content: Submitted (field_app_submitted) */
  $handler->display->display_options['filters']['field_app_submitted_value_1']['id'] = 'field_app_submitted_value_1';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['table'] = 'field_data_field_app_submitted';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['field'] = 'field_app_submitted_value';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_app_submitted_value_1']['expose']['operator_id'] = 'field_app_submitted_value_1_op';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['expose']['label'] = 'Submitted 1';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['expose']['operator'] = 'field_app_submitted_value_1_op';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['expose']['identifier'] = 'field_app_submitted_value_1';
  $handler->display->display_options['filters']['field_app_submitted_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: app_selected_1 (field_app_selected_1) */
  $handler->display->display_options['filters']['field_app_selected_1_value']['id'] = 'field_app_selected_1_value';
  $handler->display->display_options['filters']['field_app_selected_1_value']['table'] = 'field_data_field_app_selected_1';
  $handler->display->display_options['filters']['field_app_selected_1_value']['field'] = 'field_app_selected_1_value';
  $handler->display->display_options['filters']['field_app_selected_1_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['operator_id'] = 'field_app_selected_1_value_op';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['label'] = 'Selected 1';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['operator'] = 'field_app_selected_1_value_op';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['identifier'] = 'field_app_selected_1_value';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'call-coordinator-mail';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Coordinator mail';
  $handler->display->display_options['menu']['name'] = 'menu-call-admin';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'xls';
  $handler->display->display_options['style_options']['filename'] = 'coordinator.xls';
  $handler->display->display_options['path'] = 'coordinator-download/%';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['call_coordinator_mail'] = $view;

  $view = new view();
  $view->name = 'call_description_definition';
  $view->description = 'info from call-main-page included in call description';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call description definition';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Call definitions and status';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_call_open' => 'field_call_open',
    'body' => 'body',
    'php' => 'php',
    'field_current_stage' => 'field_current_stage',
    'field_call_documents' => 'field_call_documents',
    'field_contact_persons' => 'field_contact_persons',
    'field_funding_mode' => 'field_funding_mode',
    'field_stages' => 'field_stages',
    'nothing' => 'nothing',
    'field_date_launch' => 'field_date_launch',
    'field_date_pre_preposals_open' => 'field_date_pre_preposals_open',
    'field_date_pre_preposals_close' => 'field_date_pre_preposals_close',
    'field_date_pre_preposals_notific' => 'field_date_pre_preposals_notific',
    'field_date_full_proposals_open' => 'field_date_full_proposals_open',
    'field_date_full_proposals_close' => 'field_date_full_proposals_close',
    'field_date_full_proposals_notifi' => 'field_date_full_proposals_notifi',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_call_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_current_stage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_call_documents' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_persons' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_funding_mode' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_stages' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_launch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_pre_preposals_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_pre_preposals_close' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_pre_preposals_notific' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_full_proposals_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_full_proposals_close' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_full_proposals_notifi' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Call open creating application */
  $handler->display->display_options['fields']['field_call_open']['id'] = 'field_call_open';
  $handler->display->display_options['fields']['field_call_open']['table'] = 'field_data_field_call_open';
  $handler->display->display_options['fields']['field_call_open']['field'] = 'field_call_open';
  $handler->display->display_options['fields']['field_call_open']['label'] = 'Call open for creating new applications';
  /* Field: Content: Call open for edit */
  $handler->display->display_options['fields']['field_call_open_edit']['id'] = 'field_call_open_edit';
  $handler->display->display_options['fields']['field_call_open_edit']['table'] = 'field_data_field_call_open_edit';
  $handler->display->display_options['fields']['field_call_open_edit']['field'] = 'field_call_open_edit';
  /* Field: Content: Current stage */
  $handler->display->display_options['fields']['field_current_stage']['id'] = 'field_current_stage';
  $handler->display->display_options['fields']['field_current_stage']['table'] = 'field_data_field_current_stage';
  $handler->display->display_options['fields']['field_current_stage']['field'] = 'field_current_stage';
  $handler->display->display_options['fields']['field_current_stage']['alter']['text'] = 'Current stage: [field_current_stage]';
  $handler->display->display_options['fields']['field_current_stage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_current_stage']['element_default_classes'] = FALSE;
  /* Field: Content: Call documents */
  $handler->display->display_options['fields']['field_call_documents']['id'] = 'field_call_documents';
  $handler->display->display_options['fields']['field_call_documents']['table'] = 'field_data_field_call_documents';
  $handler->display->display_options['fields']['field_call_documents']['field'] = 'field_call_documents';
  $handler->display->display_options['fields']['field_call_documents']['click_sort_column'] = 'fid';
  /* Field: Content: Contact persons */
  $handler->display->display_options['fields']['field_contact_persons']['id'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['table'] = 'field_data_field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['field'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_persons']['alter']['text'] = '[field_contact_persons]';
  $handler->display->display_options['fields']['field_contact_persons']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_contact_persons']['alter']['path'] = 'user/[field_contact_persons-target_id]/contact';
  $handler->display->display_options['fields']['field_contact_persons']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact_persons']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_persons']['separator'] = '<br>';
  /* Field: Content: Funding mode */
  $handler->display->display_options['fields']['field_funding_mode']['id'] = 'field_funding_mode';
  $handler->display->display_options['fields']['field_funding_mode']['table'] = 'field_data_field_funding_mode';
  $handler->display->display_options['fields']['field_funding_mode']['field'] = 'field_funding_mode';
  $handler->display->display_options['fields']['field_funding_mode']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_funding_mode']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Theme funding */
  $handler->display->display_options['fields']['field_theme_funding']['id'] = 'field_theme_funding';
  $handler->display->display_options['fields']['field_theme_funding']['table'] = 'field_data_field_theme_funding';
  $handler->display->display_options['fields']['field_theme_funding']['field'] = 'field_theme_funding';
  /* Field: Content: Number of call stages */
  $handler->display->display_options['fields']['field_stages']['id'] = 'field_stages';
  $handler->display->display_options['fields']['field_stages']['table'] = 'field_data_field_stages';
  $handler->display->display_options['fields']['field_stages']['field'] = 'field_stages';
  $handler->display->display_options['fields']['field_stages']['relationship'] = 'field_group_application_target_id';
  $handler->display->display_options['fields']['field_stages']['label'] = 'Stages';
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
  $export['call_description_definition'] = $view;

  $view = new view();
  $view->name = 'call_description_funders';
  $view->description = 'info from call-funder-page included in call description';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call description-funders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Funding agencies, contributions, conditions and contact';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Click on Funding Agency to see funding details';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_call_id_node']['id'] = 'reverse_field_call_id_node';
  $handler->display->display_options['relationships']['reverse_field_call_id_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_call_id_node']['field'] = 'reverse_field_call_id_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['id'] = 'field_funding_agency_target_id';
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['table'] = 'field_data_field_funding_agency';
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['field'] = 'field_funding_agency_target_id';
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['relationship'] = 'reverse_field_call_id_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'field_funding_agency_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['title']['label'] = 'Funding agency';
  /* Field: Content: Funding */
  $handler->display->display_options['fields']['field_funding']['id'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['table'] = 'field_data_field_funding';
  $handler->display->display_options['fields']['field_funding']['field'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_funding']['label'] = 'Funding (1000 €)';
  $handler->display->display_options['fields']['field_funding']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_funding']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Conditions short */
  $handler->display->display_options['fields']['field_conditions_short']['id'] = 'field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['table'] = 'field_data_field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['field'] = 'field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_conditions_short']['label'] = 'Conditions';
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Funding schemes';
  $handler->display->display_options['fields']['view']['view'] = 'call_description_funding_schemes';
  $handler->display->display_options['fields']['view']['display'] = 'panel_pane_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!nid]';
  /* Field: Content: Contact persons */
  $handler->display->display_options['fields']['field_contact_persons']['id'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['table'] = 'field_data_field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['field'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_contact_persons']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_contact_persons']['alter']['path'] = 'user/[field_contact_persons-target_id]/contact';
  $handler->display->display_options['fields']['field_contact_persons']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact_persons']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_persons']['separator'] = '<br>';
  /* Field: Content: Country specific */
  $handler->display->display_options['fields']['field_country_specific']['id'] = 'field_country_specific';
  $handler->display->display_options['fields']['field_country_specific']['table'] = 'field_data_field_country_specific';
  $handler->display->display_options['fields']['field_country_specific']['field'] = 'field_country_specific';
  $handler->display->display_options['fields']['field_country_specific']['relationship'] = 'reverse_field_call_id_node';
  /* Sort criterion: Content: Funding (field_funding) */
  $handler->display->display_options['sorts']['field_funding_value']['id'] = 'field_funding_value';
  $handler->display->display_options['sorts']['field_funding_value']['table'] = 'field_data_field_funding';
  $handler->display->display_options['sorts']['field_funding_value']['field'] = 'field_funding_value';
  $handler->display->display_options['sorts']['field_funding_value']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['sorts']['field_funding_value']['order'] = 'DESC';
  /* Sort criterion: Field: Country (field_country) */
  $handler->display->display_options['sorts']['field_country_iso2']['id'] = 'field_country_iso2';
  $handler->display->display_options['sorts']['field_country_iso2']['table'] = 'field_data_field_country';
  $handler->display->display_options['sorts']['field_country_iso2']['field'] = 'field_country_iso2';
  $handler->display->display_options['sorts']['field_country_iso2']['relationship'] = 'field_funding_agency_target_id';
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
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_main_page' => 'call_main_page',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'field_funding_agency_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['title']['label'] = 'Funding agency';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'funding-details/[nid]';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Funding */
  $handler->display->display_options['fields']['field_funding']['id'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['table'] = 'field_data_field_funding';
  $handler->display->display_options['fields']['field_funding']['field'] = 'field_funding';
  $handler->display->display_options['fields']['field_funding']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_funding']['label'] = 'Funding (1000 €)';
  $handler->display->display_options['fields']['field_funding']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_funding']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Conditions short */
  $handler->display->display_options['fields']['field_conditions_short']['id'] = 'field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['table'] = 'field_data_field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['field'] = 'field_conditions_short';
  $handler->display->display_options['fields']['field_conditions_short']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_conditions_short']['label'] = 'Conditions';
  /* Field: Content: Contact persons */
  $handler->display->display_options['fields']['field_contact_persons']['id'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['table'] = 'field_data_field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['field'] = 'field_contact_persons';
  $handler->display->display_options['fields']['field_contact_persons']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_contact_persons']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_contact_persons']['alter']['path'] = 'user/[field_contact_persons-target_id]/contact';
  $handler->display->display_options['fields']['field_contact_persons']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_contact_persons']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contact_persons']['separator'] = '<br>';
  /* Field: Content: Country specific */
  $handler->display->display_options['fields']['field_country_specific']['id'] = 'field_country_specific';
  $handler->display->display_options['fields']['field_country_specific']['table'] = 'field_data_field_country_specific';
  $handler->display->display_options['fields']['field_country_specific']['field'] = 'field_country_specific';
  $handler->display->display_options['fields']['field_country_specific']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['field_country_specific']['label'] = '';
  $handler->display->display_options['fields']['field_country_specific']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'call-funders';
  $export['call_description_funders'] = $view;

  $view = new view();
  $view->name = 'call_description_funding_schemes';
  $view->description = 'Funding schemes in call description';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call description funding schemes';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: field_funder_page */
  $handler->display->display_options['arguments']['field_funder_page_target_id']['id'] = 'field_funder_page_target_id';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['table'] = 'field_data_field_funder_page';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['field'] = 'field_funder_page_target_id';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['ui_name'] = 'field_funder_page';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_funder_page_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'funding_scheme' => 'funding_scheme',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_funder_page_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'field_funder_page',
    ),
  );
  $export['call_description_funding_schemes'] = $view;

  $view = new view();
  $view->name = 'call_description_time';
  $view->description = 'info from call-main-page  included in call description';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call description time';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Time Schedule';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_launch' => 'field_date_launch',
    'field_date_pre_preposals_open' => 'field_date_pre_preposals_open',
    'field_date_pre_registration_clos' => 'field_date_pre_registration_clos',
    'field_date_pre_preposals_close' => 'field_date_pre_preposals_close',
    'field_date_pre_preposals_notific' => 'field_date_pre_preposals_notific',
    'field_date_full_proposals_open' => 'field_date_full_proposals_open',
    'field_date_full_proposals_close' => 'field_date_full_proposals_close',
    'field_date_full_proposals_notifi' => 'field_date_full_proposals_notifi',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_launch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_pre_preposals_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_pre_registration_clos' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_pre_preposals_close' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_pre_preposals_notific' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_full_proposals_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_full_proposals_close' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_full_proposals_notifi' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Field: Content: Date launch */
  $handler->display->display_options['fields']['field_date_launch']['id'] = 'field_date_launch';
  $handler->display->display_options['fields']['field_date_launch']['table'] = 'field_data_field_date_launch';
  $handler->display->display_options['fields']['field_date_launch']['field'] = 'field_date_launch';
  $handler->display->display_options['fields']['field_date_launch']['label'] = 'Call launch';
  $handler->display->display_options['fields']['field_date_launch']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_launch']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_launch']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_launch']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-proposals open */
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['id'] = 'field_date_pre_preposals_open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['table'] = 'field_data_field_date_pre_preposals_open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['field'] = 'field_date_pre_preposals_open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['label'] = 'Submission tool for pre-proposals open';
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_preposals_open']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-registration close */
  $handler->display->display_options['fields']['field_date_pre_registration_clos']['id'] = 'field_date_pre_registration_clos';
  $handler->display->display_options['fields']['field_date_pre_registration_clos']['table'] = 'field_data_field_date_pre_registration_clos';
  $handler->display->display_options['fields']['field_date_pre_registration_clos']['field'] = 'field_date_pre_registration_clos';
  $handler->display->display_options['fields']['field_date_pre_registration_clos']['label'] = 'Deadline for pre-registration';
  $handler->display->display_options['fields']['field_date_pre_registration_clos']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_registration_clos']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-proposals close */
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['id'] = 'field_date_pre_preposals_close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['table'] = 'field_data_field_date_pre_preposals_close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['field'] = 'field_date_pre_preposals_close';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['label'] = 'Deadline for submission of pre-proposals';
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_preposals_close']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date pre-proposals notification */
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['id'] = 'field_date_pre_preposals_notific';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['table'] = 'field_data_field_date_pre_preposals_notific';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['field'] = 'field_date_pre_preposals_notific';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['label'] = 'Notification of pre-proposal selection';
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_pre_preposals_notific']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date full proposals open */
  $handler->display->display_options['fields']['field_date_full_proposals_open']['id'] = 'field_date_full_proposals_open';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['table'] = 'field_data_field_date_full_proposals_open';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['field'] = 'field_date_full_proposals_open';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['label'] = 'Submission tool open for full proposals';
  $handler->display->display_options['fields']['field_date_full_proposals_open']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_full_proposals_open']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_full_proposals_open']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_full_proposals_open']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date full proposals close */
  $handler->display->display_options['fields']['field_date_full_proposals_close']['id'] = 'field_date_full_proposals_close';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['table'] = 'field_data_field_date_full_proposals_close';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['field'] = 'field_date_full_proposals_close';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['label'] = 'Deadline for submission of full proposals';
  $handler->display->display_options['fields']['field_date_full_proposals_close']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_full_proposals_close']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_full_proposals_close']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_full_proposals_close']['settings'] = array(
    'format_type' => 'medium',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date full proposals notification */
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['id'] = 'field_date_full_proposals_notifi';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['table'] = 'field_data_field_date_full_proposals_notifi';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['field'] = 'field_date_full_proposals_notifi';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['label'] = 'Notification of full proposal selection';
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_full_proposals_notifi']['settings'] = array(
    'format_type' => 'medium',
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
  $export['call_description_time'] = $view;

  $view = new view();
  $view->name = 'call_setup';
  $view->description = 'Table with calls and links to call pages and call description';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call setup';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Call setup';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_call_open' => 'field_call_open',
    'nothing_1' => 'nothing_1',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_call_open' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Header';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = 'This page list the calls defined by call main pages and provides links to edit call themes and topics, to the call description and to funding agency pages for the call. The page remains empty until a call main page has been created.';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Call';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Call open for edit */
  $handler->display->display_options['fields']['field_call_open_edit']['id'] = 'field_call_open_edit';
  $handler->display->display_options['fields']['field_call_open_edit']['table'] = 'field_data_field_call_open_edit';
  $handler->display->display_options['fields']['field_call_open_edit']['field'] = 'field_call_open_edit';
  $handler->display->display_options['fields']['field_call_open_edit']['exclude'] = TRUE;
  /* Field: Content: Call open creating application */
  $handler->display->display_options['fields']['field_call_open']['id'] = 'field_call_open';
  $handler->display->display_options['fields']['field_call_open']['table'] = 'field_data_field_call_open';
  $handler->display->display_options['fields']['field_call_open']['field'] = 'field_call_open';
  $handler->display->display_options['fields']['field_call_open']['label'] = 'Open';
  $handler->display->display_options['fields']['field_call_open']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_call_open']['alter']['text'] = '[field_call_open]<br>[field_call_open_edit]';
  /* Field: Content: Topics  */
  $handler->display->display_options['fields']['field_call_topics']['id'] = 'field_call_topics';
  $handler->display->display_options['fields']['field_call_topics']['table'] = 'field_data_field_call_topics';
  $handler->display->display_options['fields']['field_call_topics']['field'] = 'field_call_topics';
  $handler->display->display_options['fields']['field_call_topics']['label'] = 'Themes/topics ';
  $handler->display->display_options['fields']['field_call_topics']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_call_topics']['alter']['text'] = 'Edit themes/topics';
  $handler->display->display_options['fields']['field_call_topics']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_call_topics']['alter']['path'] = 'call-topics-setup/[nid]';
  $handler->display->display_options['fields']['field_call_topics']['empty'] = 'Call topics disabled';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Call description';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Call description';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'call_description/[nid]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Funder pages */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Funder pages';
  $handler->display->display_options['fields']['nothing']['label'] = 'Funder pages';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Funder pages';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'call-setup-pages/[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_main_page' => 'call_main_page',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'call-setup';
  $export['call_setup'] = $view;

  $view = new view();
  $view->name = 'call_setup_pages';
  $view->description = 'List of pages for calls';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Call setup pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Call setup pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'call pages';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Funder pages and funding schemes related to this call. 
Titles are links to edit.';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'No pages';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No pages found for this call';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_call_id_node']['id'] = 'reverse_field_call_id_node';
  $handler->display->display_options['relationships']['reverse_field_call_id_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_call_id_node']['field'] = 'reverse_field_call_id_node';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_funder_page_node']['id'] = 'reverse_field_funder_page_node';
  $handler->display->display_options['relationships']['reverse_field_funder_page_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_funder_page_node']['field'] = 'reverse_field_funder_page_node';
  $handler->display->display_options['relationships']['reverse_field_funder_page_node']['relationship'] = 'reverse_field_call_id_node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['id'] = 'field_funding_agency_target_id';
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['table'] = 'field_data_field_funding_agency';
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['field'] = 'field_funding_agency_target_id';
  $handler->display->display_options['relationships']['field_funding_agency_target_id']['relationship'] = 'reverse_field_call_id_node';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'reverse_field_funder_page_node';
  $handler->display->display_options['fields']['nid_2']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Call main page';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'field_funding_agency_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['fields']['title']['label'] = 'Funder page';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid_1]/edit/?destination=call-setup-pages/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'reverse_field_funder_page_node';
  $handler->display->display_options['fields']['title_2']['label'] = 'Funding scheme';
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_2']['alter']['path'] = 'node/[nid_2]/edit/?destination=call-setup-pages/[nid]';
  $handler->display->display_options['fields']['title_2']['link_to_node'] = FALSE;
  /* Sort criterion: Field: Country (field_country) */
  $handler->display->display_options['sorts']['field_country_iso2']['id'] = 'field_country_iso2';
  $handler->display->display_options['sorts']['field_country_iso2']['table'] = 'field_data_field_country';
  $handler->display->display_options['sorts']['field_country_iso2']['field'] = 'field_country_iso2';
  $handler->display->display_options['sorts']['field_country_iso2']['relationship'] = 'reverse_field_call_id_node';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title_1']['id'] = 'title_1';
  $handler->display->display_options['sorts']['title_1']['table'] = 'node';
  $handler->display->display_options['sorts']['title_1']['field'] = 'title';
  $handler->display->display_options['sorts']['title_1']['relationship'] = 'reverse_field_call_id_node';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_main_page' => 'call_main_page',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_call_id_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'call_funder_page' => 'call_funder_page',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'node';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['relationship'] = 'reverse_field_funder_page_node';
  $handler->display->display_options['filters']['type_2']['value'] = array(
    'funding_scheme' => 'funding_scheme',
  );
  $handler->display->display_options['filters']['type_2']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_3']['id'] = 'type_3';
  $handler->display->display_options['filters']['type_3']['table'] = 'node';
  $handler->display->display_options['filters']['type_3']['field'] = 'type';
  $handler->display->display_options['filters']['type_3']['relationship'] = 'reverse_field_funder_page_node';
  $handler->display->display_options['filters']['type_3']['operator'] = 'empty';
  $handler->display->display_options['filters']['type_3']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'call-setup-pages';
  $export['call_setup_pages'] = $view;

  $view = new view();
  $view->name = 'call_topics';
  $view->description = 'Call topics included in call description';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Call themes and topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Topic level */
  $handler->display->display_options['fields']['field_topic_level']['id'] = 'field_topic_level';
  $handler->display->display_options['fields']['field_topic_level']['table'] = 'field_data_field_topic_level';
  $handler->display->display_options['fields']['field_topic_level']['field'] = 'field_topic_level';
  $handler->display->display_options['fields']['field_topic_level']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Topic weight */
  $handler->display->display_options['fields']['field_topic_weight']['id'] = 'field_topic_weight';
  $handler->display->display_options['fields']['field_topic_weight']['table'] = 'field_data_field_topic_weight';
  $handler->display->display_options['fields']['field_topic_weight']['field'] = 'field_topic_weight';
  $handler->display->display_options['fields']['field_topic_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Topic description */
  $handler->display->display_options['fields']['field_topic_description']['id'] = 'field_topic_description';
  $handler->display->display_options['fields']['field_topic_description']['table'] = 'field_data_field_topic_description';
  $handler->display->display_options['fields']['field_topic_description']['field'] = 'field_topic_description';
  /* Field: Content: Topic parent */
  $handler->display->display_options['fields']['field_topic_parent']['id'] = 'field_topic_parent';
  $handler->display->display_options['fields']['field_topic_parent']['table'] = 'field_data_field_topic_parent';
  $handler->display->display_options['fields']['field_topic_parent']['field'] = 'field_topic_parent';
  $handler->display->display_options['fields']['field_topic_parent']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_topic_parent']['alter']['text'] = '[field_topic_parent-target_id]';
  $handler->display->display_options['fields']['field_topic_parent']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Call */
  $handler->display->display_options['fields']['field_call_id']['id'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['fields']['field_call_id']['field'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id']['label'] = 'Call id';
  $handler->display->display_options['fields']['field_call_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_call_id']['alter']['text'] = '[field_call_id-target_id]';
  $handler->display->display_options['fields']['field_call_id']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Call */
  $handler->display->display_options['fields']['field_call_id_1']['id'] = 'field_call_id_1';
  $handler->display->display_options['fields']['field_call_id_1']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['fields']['field_call_id_1']['field'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id_1']['label'] = 'Call title';
  $handler->display->display_options['fields']['field_call_id_1']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Topic level (field_topic_level) */
  $handler->display->display_options['sorts']['field_topic_level_value']['id'] = 'field_topic_level_value';
  $handler->display->display_options['sorts']['field_topic_level_value']['table'] = 'field_data_field_topic_level';
  $handler->display->display_options['sorts']['field_topic_level_value']['field'] = 'field_topic_level_value';
  /* Sort criterion: Content: Topic weight (field_topic_weight) */
  $handler->display->display_options['sorts']['field_topic_weight_value']['id'] = 'field_topic_weight_value';
  $handler->display->display_options['sorts']['field_topic_weight_value']['table'] = 'field_data_field_topic_weight';
  $handler->display->display_options['sorts']['field_topic_weight_value']['field'] = 'field_topic_weight_value';
  /* Contextual filter: Content: Call (field_call_id) */
  $handler->display->display_options['arguments']['field_call_id_target_id']['id'] = 'field_call_id_target_id';
  $handler->display->display_options['arguments']['field_call_id_target_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['arguments']['field_call_id_target_id']['field'] = 'field_call_id_target_id';
  $handler->display->display_options['arguments']['field_call_id_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_call_id_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_call_id_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_call_id_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_topic' => 'call_topic',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'call-topics-show';
  $export['call_topics'] = $view;

  $view = new view();
  $view->name = 'call_topics_setup';
  $view->description = 'Definition of call topics';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Call topics setup';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3><a href="/node/add/call-topic/!1/0/1/10">Create first theme</a>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Topic level */
  $handler->display->display_options['fields']['field_topic_level']['id'] = 'field_topic_level';
  $handler->display->display_options['fields']['field_topic_level']['table'] = 'field_data_field_topic_level';
  $handler->display->display_options['fields']['field_topic_level']['field'] = 'field_topic_level';
  $handler->display->display_options['fields']['field_topic_level']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Topic weight */
  $handler->display->display_options['fields']['field_topic_weight']['id'] = 'field_topic_weight';
  $handler->display->display_options['fields']['field_topic_weight']['table'] = 'field_data_field_topic_weight';
  $handler->display->display_options['fields']['field_topic_weight']['field'] = 'field_topic_weight';
  $handler->display->display_options['fields']['field_topic_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Topic description */
  $handler->display->display_options['fields']['field_topic_description']['id'] = 'field_topic_description';
  $handler->display->display_options['fields']['field_topic_description']['table'] = 'field_data_field_topic_description';
  $handler->display->display_options['fields']['field_topic_description']['field'] = 'field_topic_description';
  /* Field: Content: Topic parent */
  $handler->display->display_options['fields']['field_topic_parent']['id'] = 'field_topic_parent';
  $handler->display->display_options['fields']['field_topic_parent']['table'] = 'field_data_field_topic_parent';
  $handler->display->display_options['fields']['field_topic_parent']['field'] = 'field_topic_parent';
  $handler->display->display_options['fields']['field_topic_parent']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_topic_parent']['alter']['text'] = '[field_topic_parent-target_id]';
  $handler->display->display_options['fields']['field_topic_parent']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Call */
  $handler->display->display_options['fields']['field_call_id']['id'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['fields']['field_call_id']['field'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id']['label'] = 'Call id';
  $handler->display->display_options['fields']['field_call_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_call_id']['alter']['text'] = '[field_call_id-target_id]';
  $handler->display->display_options['fields']['field_call_id']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Call */
  $handler->display->display_options['fields']['field_call_id_1']['id'] = 'field_call_id_1';
  $handler->display->display_options['fields']['field_call_id_1']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['fields']['field_call_id_1']['field'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id_1']['label'] = 'Call title';
  $handler->display->display_options['fields']['field_call_id_1']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Topic level (field_topic_level) */
  $handler->display->display_options['sorts']['field_topic_level_value']['id'] = 'field_topic_level_value';
  $handler->display->display_options['sorts']['field_topic_level_value']['table'] = 'field_data_field_topic_level';
  $handler->display->display_options['sorts']['field_topic_level_value']['field'] = 'field_topic_level_value';
  /* Sort criterion: Content: Topic weight (field_topic_weight) */
  $handler->display->display_options['sorts']['field_topic_weight_value']['id'] = 'field_topic_weight_value';
  $handler->display->display_options['sorts']['field_topic_weight_value']['table'] = 'field_data_field_topic_weight';
  $handler->display->display_options['sorts']['field_topic_weight_value']['field'] = 'field_topic_weight_value';
  /* Contextual filter: Content: Call (field_call_id) */
  $handler->display->display_options['arguments']['field_call_id_target_id']['id'] = 'field_call_id_target_id';
  $handler->display->display_options['arguments']['field_call_id_target_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['arguments']['field_call_id_target_id']['field'] = 'field_call_id_target_id';
  $handler->display->display_options['arguments']['field_call_id_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_call_id_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_call_id_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_call_id_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'call_topic' => 'call_topic',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'call-topics-setup';
  $export['call_topics_setup'] = $view;

  $view = new view();
  $view->name = 'evaluation_summaries';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Evaluation summaries';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evaluation summaries';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_eval_conf_target_id']['id'] = 'field_eval_conf_target_id';
  $handler->display->display_options['relationships']['field_eval_conf_target_id']['table'] = 'field_data_field_eval_conf';
  $handler->display->display_options['relationships']['field_eval_conf_target_id']['field'] = 'field_eval_conf_target_id';
  /* Relationship: OG membership: Group Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node_group']['id'] = 'og_membership_related_node_group';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node_group']['field'] = 'og_membership_related_node_group';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'og_membership_related_node_group';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Text area */
  $handler->display->display_options['fields']['field_eval_text_area']['id'] = 'field_eval_text_area';
  $handler->display->display_options['fields']['field_eval_text_area']['table'] = 'field_data_field_eval_text_area';
  $handler->display->display_options['fields']['field_eval_text_area']['field'] = 'field_eval_text_area';
  $handler->display->display_options['fields']['field_eval_text_area']['label'] = 'Summary';
  $handler->display->display_options['fields']['field_eval_text_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eval_text_area']['delta_offset'] = '0';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'og_membership_related_node_group';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_eval_conf_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'evaluation' => 'evaluation',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'evaluation-summaries';
  $export['evaluation_summaries'] = $view;

  $view = new view();
  $view->name = 'funding_agency_select';
  $view->description = 'Used for selecting funding bodies from organisations in Call funder page content type';
  $view->tag = 'MKB Call admin';
  $view->base_table = 'node';
  $view->human_name = 'Funding agency select';
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
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'organisation_type' => 'organisation_type',
    'forums' => 0,
    'country' => 0,
    'funding_mode' => 0,
    'tags' => 0,
    'topics' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['name']['value'] = 'Funding agency';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['funding_agency_select'] = $view;

  return $export;
}
