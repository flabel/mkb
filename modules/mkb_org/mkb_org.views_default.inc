<?php
/**
 * @file
 * mkb_org.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mkb_org_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'organisations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Organisations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organisations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_short_name' => 'field_short_name',
    'title' => 'title',
    'field_parent_organisation' => 'field_parent_organisation',
    'field_organisation_type' => 'field_organisation_type',
    'field_email' => 'field_email',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_short_name' => array(
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
    'field_parent_organisation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organisation_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'country' => 'country',
    'organisation_type' => 'organisation_type',
    'forums' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_iso2']['id'] = 'field_country_iso2';
  $handler->display->display_options['relationships']['field_country_iso2']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_iso2']['field'] = 'field_country_iso2';
  /* Field: Content: Shortname */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['label'] = 'Short name';
  $handler->display->display_options['fields']['field_short_name']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Parent organisation */
  $handler->display->display_options['fields']['field_parent_organisation']['id'] = 'field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['table'] = 'field_data_field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['field'] = 'field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_organisation_type']['type'] = 'taxonomy_term_reference_link';
  $handler->display->display_options['fields']['field_organisation_type']['group_column'] = 'tid';
  $handler->display->display_options['fields']['field_organisation_type']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_organisation_type']['delta_offset'] = '0';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Org_name (field_org_name) */
  $handler->display->display_options['filters']['field_org_name_value']['id'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['filters']['field_org_name_value']['field'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_org_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_org_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator_id'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['identifier'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'organisation_type';
  /* Filter criterion: Countries: Name - list */
  $handler->display->display_options['filters']['name_list']['id'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['table'] = 'countries_country';
  $handler->display->display_options['filters']['name_list']['field'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['relationship'] = 'field_country_iso2';
  $handler->display->display_options['filters']['name_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_list']['expose']['operator_id'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['name_list']['expose']['operator'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['identifier'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['name_list']['configuration'] = '1';
  $handler->display->display_options['filters']['name_list']['filter'] = array(
    'enabled' => '1',
    'continents' => array(),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Org_name */
  $handler->display->display_options['fields']['field_org_name']['id'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['fields']['field_org_name']['field'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_org_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['path'] = 'mapping/[nid]';
  $handler->display->display_options['fields']['field_org_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['preserve_tags'] = '<br> <strong>';
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_organisation_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['path'] = 'organisations';
  $handler->display->display_options['menu']['title'] = 'Organisations';
  $handler->display->display_options['menu']['description'] = 'Any type of Organisation, Institution or company people belong to';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';

    $views['organisations'] = $view;

  $view = new view();
  $view->name = 'project_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Project partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project partners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['id'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['table'] = 'field_data_field_my_organisation';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['field'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_parent_organisation_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Org_name */
  $handler->display->display_options['fields']['field_org_name']['id'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['fields']['field_org_name']['field'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['relationship'] = 'field_my_organisation_target_id';
  $handler->display->display_options['fields']['field_org_name']['label'] = 'Organisation';
  $handler->display->display_options['fields']['field_org_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_org_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['preserve_tags'] = '<br> <strong>';
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_user_country']['id'] = 'field_user_country';
  $handler->display->display_options['fields']['field_user_country']['table'] = 'field_data_field_user_country';
  $handler->display->display_options['fields']['field_user_country']['field'] = 'field_user_country';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'Contact';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['text'] = '[field_first_name] [field_last_name] ';
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['alter']['path'] = 'profile-main/[uid]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Contact';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'contact/[uid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Country (field_user_country) */
  $handler->display->display_options['sorts']['field_user_country_iso2']['id'] = 'field_user_country_iso2';
  $handler->display->display_options['sorts']['field_user_country_iso2']['table'] = 'field_data_field_user_country';
  $handler->display->display_options['sorts']['field_user_country_iso2']['field'] = 'field_user_country_iso2';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'project-partners';
  $handler->display->display_options['menu']['title'] = 'Project partners';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-user-data';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $views['project_partners'] = $view;

  $view = new view();
  $view->name = 'user_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'nid' => 'nid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_org_name' => 'field_org_name',
    'field_social_media' => 'field_social_media',
    'nothing_1' => 'nothing_1',
    'field_cv' => 'field_cv',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_org_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_social_media' => array(
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
    'field_cv' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['id'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['table'] = 'field_data_field_my_organisation';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['field'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_my_organisation_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Org_name */
  $handler->display->display_options['fields']['field_org_name']['id'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['fields']['field_org_name']['field'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['relationship'] = 'field_my_organisation_target_id';
  $handler->display->display_options['fields']['field_org_name']['label'] = '';
  $handler->display->display_options['fields']['field_org_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_org_name']['alter']['preserve_tags'] = '<br> <strong>';
  $handler->display->display_options['fields']['field_org_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Social media */
  $handler->display->display_options['fields']['field_social_media']['id'] = 'field_social_media';
  $handler->display->display_options['fields']['field_social_media']['table'] = 'field_data_field_social_media';
  $handler->display->display_options['fields']['field_social_media']['field'] = 'field_social_media';
  $handler->display->display_options['fields']['field_social_media']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_social_media']['label'] = '';
  $handler->display->display_options['fields']['field_social_media']['alter']['text'] = '[field_social_media] [field_social_media-value] [field_social_media-format]';
  $handler->display->display_options['fields']['field_social_media']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_social_media']['alter']['path'] = '[field_social_media]';
  $handler->display->display_options['fields']['field_social_media']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_social_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_social_media']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['field_social_media']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_social_media']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Contact by mail';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'user/[uid]/contact';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'p';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: CV */
  $handler->display->display_options['fields']['field_cv']['id'] = 'field_cv';
  $handler->display->display_options['fields']['field_cv']['table'] = 'field_data_field_cv';
  $handler->display->display_options['fields']['field_cv']['field'] = 'field_cv';
  $handler->display->display_options['fields']['field_cv']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_cv']['label'] = '';
  $handler->display->display_options['fields']['field_cv']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['field_cv']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_cv']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'user-profile';
  $views['user_profile'] = $view;

  $view = new view();
  $view->name = 'organisations_edit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'organisations edit';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Organisations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_short_name' => 'field_short_name',
    'title' => 'title',
    'field_parent_organisation' => 'field_parent_organisation',
    'field_organisation_type' => 'field_organisation_type',
    'field_email' => 'field_email',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_short_name' => array(
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
    'field_parent_organisation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organisation_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'country' => 'country',
    'organisation_type' => 'organisation_type',
    'forums' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_iso2']['id'] = 'field_country_iso2';
  $handler->display->display_options['relationships']['field_country_iso2']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_iso2']['field'] = 'field_country_iso2';
  /* Field: Content: Shortname */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['label'] = 'Short name';
  $handler->display->display_options['fields']['field_short_name']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Parent organisation */
  $handler->display->display_options['fields']['field_parent_organisation']['id'] = 'field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['table'] = 'field_data_field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['field'] = 'field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_organisation_type']['type'] = 'taxonomy_term_reference_link';
  $handler->display->display_options['fields']['field_organisation_type']['group_column'] = 'tid';
  $handler->display->display_options['fields']['field_organisation_type']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_organisation_type']['delta_offset'] = '0';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Org_name (field_org_name) */
  $handler->display->display_options['filters']['field_org_name_value']['id'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['filters']['field_org_name_value']['field'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_org_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_org_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator_id'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['identifier'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'organisation_type';
  /* Filter criterion: Countries: Name - list */
  $handler->display->display_options['filters']['name_list']['id'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['table'] = 'countries_country';
  $handler->display->display_options['filters']['name_list']['field'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['relationship'] = 'field_country_iso2';
  $handler->display->display_options['filters']['name_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_list']['expose']['operator_id'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['name_list']['expose']['operator'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['identifier'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['name_list']['configuration'] = '1';
  $handler->display->display_options['filters']['name_list']['filter'] = array(
    'enabled' => '1',
    'continents' => array(),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Org_name */
  $handler->display->display_options['fields']['field_org_name']['id'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['fields']['field_org_name']['field'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_org_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_org_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['preserve_tags'] = '<br> <strong>';
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_organisation_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['path'] = 'organisations_edit';
  $handler->display->display_options['menu']['title'] = 'Organisations';
  $handler->display->display_options['menu']['description'] = 'Any type of Organisation, Institution or company people belong to';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $views['organisations_edit'] = $view;

  $view = new view();
  $view->name = 'organisations_my_edit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'organisations my edit';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My organisations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_short_name' => 'field_short_name',
    'title' => 'title',
    'field_parent_organisation' => 'field_parent_organisation',
    'field_organisation_type' => 'field_organisation_type',
    'field_email' => 'field_email',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'field_short_name' => array(
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
    'field_parent_organisation' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organisation_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'country' => 'country',
    'organisation_type' => 'organisation_type',
    'forums' => 0,
    'tags' => 0,
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Country (field_country) */
  $handler->display->display_options['relationships']['field_country_iso2']['id'] = 'field_country_iso2';
  $handler->display->display_options['relationships']['field_country_iso2']['table'] = 'field_data_field_country';
  $handler->display->display_options['relationships']['field_country_iso2']['field'] = 'field_country_iso2';
  /* Field: Content: Shortname */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['label'] = 'Short name';
  $handler->display->display_options['fields']['field_short_name']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Parent organisation */
  $handler->display->display_options['fields']['field_parent_organisation']['id'] = 'field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['table'] = 'field_data_field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['field'] = 'field_parent_organisation';
  $handler->display->display_options['fields']['field_parent_organisation']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['click_sort_column'] = 'tid';
  $handler->display->display_options['fields']['field_organisation_type']['type'] = 'taxonomy_term_reference_link';
  $handler->display->display_options['fields']['field_organisation_type']['group_column'] = 'tid';
  $handler->display->display_options['fields']['field_organisation_type']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_organisation_type']['delta_offset'] = '0';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organisation' => 'organisation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Org_name (field_org_name) */
  $handler->display->display_options['filters']['field_org_name_value']['id'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['filters']['field_org_name_value']['field'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_org_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_org_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator_id'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['identifier'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Taxonomy term: Term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'organisation_type';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: Countries: Name - list */
  $handler->display->display_options['filters']['name_list']['id'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['table'] = 'countries_country';
  $handler->display->display_options['filters']['name_list']['field'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['relationship'] = 'field_country_iso2';
  $handler->display->display_options['filters']['name_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_list']['expose']['operator_id'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['name_list']['expose']['operator'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['identifier'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['name_list']['configuration'] = '1';
  $handler->display->display_options['filters']['name_list']['filter'] = array(
    'enabled' => '1',
    'continents' => array(),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Org_name */
  $handler->display->display_options['fields']['field_org_name']['id'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['fields']['field_org_name']['field'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_org_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_org_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['preserve_tags'] = '<br> <strong>';
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_organisation_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['path'] = 'organisations_my_edit';
  $handler->display->display_options['menu']['title'] = 'Organisations';
  $handler->display->display_options['menu']['description'] = 'Any type of Organisation, Institution or company people belong to';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'ctools_context_1');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $views['organisations_my_edit'] = $view;

  $view = new view();
  $view->name = 'user_profiles';
  $view->description = 'Search and show users';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'user-profiles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'user-profiles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['required'] = TRUE;
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['id'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['table'] = 'field_data_field_my_organisation';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['field'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['relationship'] = 'profile';
  /* Relationship: User: Country (field_user_country) */
  $handler->display->display_options['relationships']['field_user_country_iso2']['id'] = 'field_user_country_iso2';
  $handler->display->display_options['relationships']['field_user_country_iso2']['table'] = 'field_data_field_user_country';
  $handler->display->display_options['relationships']['field_user_country_iso2']['field'] = 'field_user_country_iso2';
  $handler->display->display_options['relationships']['field_user_country_iso2']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user-profile/[uid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_my_organisation_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_user_country']['id'] = 'field_user_country';
  $handler->display->display_options['fields']['field_user_country']['table'] = 'field_data_field_user_country';
  $handler->display->display_options['fields']['field_user_country']['field'] = 'field_user_country';
  $handler->display->display_options['fields']['field_user_country']['element_label_colon'] = FALSE;
  /* Field: Profile: My organisation */
  $handler->display->display_options['fields']['field_my_organisation']['id'] = 'field_my_organisation';
  $handler->display->display_options['fields']['field_my_organisation']['table'] = 'field_data_field_my_organisation';
  $handler->display->display_options['fields']['field_my_organisation']['field'] = 'field_my_organisation';
  $handler->display->display_options['fields']['field_my_organisation']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_my_organisation']['label'] = 'Organisation';
  $handler->display->display_options['fields']['field_my_organisation']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_my_organisation']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_my_organisation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_my_organisation']['settings'] = array(
    'link' => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Last name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['description'] = 'Enter part of the name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Org_name (field_org_name) */
  $handler->display->display_options['filters']['field_org_name_value']['id'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['filters']['field_org_name_value']['field'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['relationship'] = 'field_my_organisation_target_id';
  $handler->display->display_options['filters']['field_org_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_org_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator_id'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['description'] = 'Enter part of organisation name';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['operator'] = 'field_org_name_value_op';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['identifier'] = 'field_org_name_value';
  $handler->display->display_options['filters']['field_org_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Countries: Name - list */
  $handler->display->display_options['filters']['name_list']['id'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['table'] = 'countries_country';
  $handler->display->display_options['filters']['name_list']['field'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['relationship'] = 'field_user_country_iso2';
  $handler->display->display_options['filters']['name_list']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name_list']['expose']['operator_id'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['name_list']['expose']['description'] = 'Select a country';
  $handler->display->display_options['filters']['name_list']['expose']['operator'] = 'name_list_op';
  $handler->display->display_options['filters']['name_list']['expose']['identifier'] = 'name_list';
  $handler->display->display_options['filters']['name_list']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user-profiles';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'User Profiles';
  $handler->display->display_options['menu']['name'] = 'menu-mkb-demo';
  $views['user_profiles'] = $view;

  $view = new view();
  $view->name = 'era_net_partners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ERA-NET partners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ERA-NET partners';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'field_partner_number' => 'field_partner_number',
    'field_short_name' => 'field_short_name',
    'field_org_name' => 'field_org_name',
    'field_country' => 'field_country',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
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
    'field_partner_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_short_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_org_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_country' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_my_organisation_profile2']['id'] = 'reverse_field_my_organisation_profile2';
  $handler->display->display_options['relationships']['reverse_field_my_organisation_profile2']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_my_organisation_profile2']['field'] = 'reverse_field_my_organisation_profile2';
  /* Relationship: Profile: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'profile';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'reverse_field_my_organisation_profile2';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Partner_number */
  $handler->display->display_options['fields']['field_partner_number']['id'] = 'field_partner_number';
  $handler->display->display_options['fields']['field_partner_number']['table'] = 'field_data_field_partner_number';
  $handler->display->display_options['fields']['field_partner_number']['field'] = 'field_partner_number';
  $handler->display->display_options['fields']['field_partner_number']['label'] = '';
  $handler->display->display_options['fields']['field_partner_number']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_partner_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_partner_number']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Short_name */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['label'] = '';
  $handler->display->display_options['fields']['field_short_name']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_short_name']['element_label_colon'] = FALSE;
  /* Field: Content: Org_name */
  $handler->display->display_options['fields']['field_org_name']['id'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['table'] = 'field_data_field_org_name';
  $handler->display->display_options['fields']['field_org_name']['field'] = 'field_org_name';
  $handler->display->display_options['fields']['field_org_name']['label'] = '';
  $handler->display->display_options['fields']['field_org_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_org_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_org_name']['alter']['preserve_tags'] = '<br> <strong>';
  $handler->display->display_options['fields']['field_org_name']['element_label_colon'] = FALSE;
  /* Field: Content: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['label'] = '';
  $handler->display->display_options['fields']['field_country']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'user';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'user-profile/[uid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'user';
  $handler->display->display_options['fields']['rid']['label'] = '';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Partner_number (field_partner_number) */
  $handler->display->display_options['sorts']['field_partner_number_value']['id'] = 'field_partner_number_value';
  $handler->display->display_options['sorts']['field_partner_number_value']['table'] = 'field_data_field_partner_number';
  $handler->display->display_options['sorts']['field_partner_number_value']['field'] = 'field_partner_number_value';
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
    'organisation' => 'organisation',
  );
  /* Filter criterion: Content: Partner_number (field_partner_number) */
  $handler->display->display_options['filters']['field_partner_number_value']['id'] = 'field_partner_number_value';
  $handler->display->display_options['filters']['field_partner_number_value']['table'] = 'field_data_field_partner_number';
  $handler->display->display_options['filters']['field_partner_number_value']['field'] = 'field_partner_number_value';
  $handler->display->display_options['filters']['field_partner_number_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_partner_number_value']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'era-net-partners';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'ERA-NET partners';
  $handler->display->display_options['menu']['name'] = 'menu-about';
  $views['era_net_partners'] = $view;

  $view = new view();
  $view->name = 'send_mail';
  $view->description = 'Send mail to administrators and project members';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Send mail';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Send mail';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'Send mail to the selected persons.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<em>Send e-mail</em> will send the mail from the website.
  <em>Open mail client</em> will open you mail client with the email addresses inserted (close the empty page that is automatically opened).';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['id'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['table'] = 'field_data_field_my_organisation';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['field'] = 'field_my_organisation_target_id';
  $handler->display->display_options['relationships']['field_my_organisation_target_id']['relationship'] = 'profile';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Global: Send e-mail */
  $handler->display->display_options['fields']['views_send']['id'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['table'] = 'views';
  $handler->display->display_options['fields']['views_send']['field'] = 'views_send';
  $handler->display->display_options['fields']['views_send']['label'] = 'Send mail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'user-profile/[uid]';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Content: Short name */
  $handler->display->display_options['fields']['field_short_name']['id'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['table'] = 'field_data_field_short_name';
  $handler->display->display_options['fields']['field_short_name']['field'] = 'field_short_name';
  $handler->display->display_options['fields']['field_short_name']['relationship'] = 'field_my_organisation_target_id';
  $handler->display->display_options['fields']['field_short_name']['label'] = 'Partner';
  /* Field: Field: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  /* Sort criterion: User: First name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    4 => '4',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'send-mail';
  $views['send_mail'] = $view;

  return $views;
}