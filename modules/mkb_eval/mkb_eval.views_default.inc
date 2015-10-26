<?php
/**
 * @file
 * mkb_eval.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mkb_eval_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'call_eval_config';
  $view->description = 'MKB Evaluation module';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Call Evaluation Configurations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Call Evaluation Configurations';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Evaluation type */
  $handler->display->display_options['fields']['field_eval_conf_type']['id'] = 'field_eval_conf_type';
  $handler->display->display_options['fields']['field_eval_conf_type']['table'] = 'field_data_field_eval_conf_type';
  $handler->display->display_options['fields']['field_eval_conf_type']['field'] = 'field_eval_conf_type';
  $handler->display->display_options['fields']['field_eval_conf_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_eval_conf_type']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Shortname */
  $handler->display->display_options['fields']['field_expertise_shortname']['id'] = 'field_expertise_shortname';
  $handler->display->display_options['fields']['field_expertise_shortname']['table'] = 'field_data_field_expertise_shortname';
  $handler->display->display_options['fields']['field_expertise_shortname']['field'] = 'field_expertise_shortname';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: View form */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'View form';
  $handler->display->display_options['fields']['nothing']['label'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/add/evaluation/14840/[nid]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'node/[nid]/edit?destination=call-evaluation-configurations';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'evaluation_conf' => 'evaluation_conf',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'call-evaluation-configurations';
  $export['call_eval_config'] = $view;

  $view = new view();
  $view->name = 'evaluation_configuration_select';
  $view->description = 'Show all Evaluation configuration types with evaluation type Expert';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Evaluation configuration select';
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
  /* Field: Content: Call */
  $handler->display->display_options['fields']['field_call_id']['id'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['fields']['field_call_id']['field'] = 'field_call_id';
  $handler->display->display_options['fields']['field_call_id']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_call_id']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'evaluation_conf' => 'evaluation_conf',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_call_id' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['evaluation_configuration_select'] = $view;

  $view = new view();
  $view->name = 'evaluation_summary';
  $view->description = 'List of all the topics in this call';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Evaluation summary';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evaluation topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Evaluation topics header';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Click on a topic to go to the application selection.';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'Evaluation topics no result';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no topics defined for this call.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_call_id_target_id']['id'] = 'field_call_id_target_id';
  $handler->display->display_options['relationships']['field_call_id_target_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['relationships']['field_call_id_target_id']['field'] = 'field_call_id_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Topics';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'eval/summary/!1/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_call_id_target_id';
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
    'call_topic' => 'call_topic',
  );
  /* Filter criterion: Content: Topic parent (field_topic_parent) */
  $handler->display->display_options['filters']['field_topic_parent_target_id']['id'] = 'field_topic_parent_target_id';
  $handler->display->display_options['filters']['field_topic_parent_target_id']['table'] = 'field_data_field_topic_parent';
  $handler->display->display_options['filters']['field_topic_parent_target_id']['field'] = 'field_topic_parent_target_id';
  $handler->display->display_options['filters']['field_topic_parent_target_id']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'eval_summary';
  $export['evaluation_summary'] = $view;

  $view = new view();
  $view->name = 'evaluation_topics';
  $view->description = 'List of all the topics in this call';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Evaluation topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evaluation topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Evaluation topics header';
  $handler->display->display_options['header']['area_text_custom']['content'] = 'Click on a topic to go to the application selection.';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'Evaluation topics no result';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'There are no topics defined for this call.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_call_id_target_id']['id'] = 'field_call_id_target_id';
  $handler->display->display_options['relationships']['field_call_id_target_id']['table'] = 'field_data_field_call_id';
  $handler->display->display_options['relationships']['field_call_id_target_id']['field'] = 'field_call_id_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Topics';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'eval/application_selection_topic/!1/26888/[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_call_id_target_id';
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
    'call_topic' => 'call_topic',
  );
  /* Filter criterion: Content: Topic parent (field_topic_parent) */
  $handler->display->display_options['filters']['field_topic_parent_target_id']['id'] = 'field_topic_parent_target_id';
  $handler->display->display_options['filters']['field_topic_parent_target_id']['table'] = 'field_data_field_topic_parent';
  $handler->display->display_options['filters']['field_topic_parent_target_id']['field'] = 'field_topic_parent_target_id';
  $handler->display->display_options['filters']['field_topic_parent_target_id']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'eval_topics';
  $export['evaluation_topics'] = $view;

  $view = new view();
  $view->name = 'evaluations';
  $view->description = 'Check of evaluations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Evaluations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Evaluations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    8 => '8',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Content: Text area */
  $handler->display->display_options['fields']['field_eval_text_area']['id'] = 'field_eval_text_area';
  $handler->display->display_options['fields']['field_eval_text_area']['table'] = 'field_data_field_eval_text_area';
  $handler->display->display_options['fields']['field_eval_text_area']['field'] = 'field_eval_text_area';
  $handler->display->display_options['fields']['field_eval_text_area']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['field_eval_text_area']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_eval_text_area']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author uid';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'evaluations';
  $export['evaluations'] = $view;

  $view = new view();
  $view->name = 'expert_application_select';
  $view->description = 'Filter all users that are assigned to an evaluation expert application';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Expert application select';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_expert_user_node']['id'] = 'reverse_field_expert_user_node';
  $handler->display->display_options['relationships']['reverse_field_expert_user_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_expert_user_node']['field'] = 'reverse_field_expert_user_node';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Expert user (field_expert_user) */
  $handler->display->display_options['filters']['field_expert_user_target_id']['id'] = 'field_expert_user_target_id';
  $handler->display->display_options['filters']['field_expert_user_target_id']['table'] = 'field_data_field_expert_user';
  $handler->display->display_options['filters']['field_expert_user_target_id']['field'] = 'field_expert_user_target_id';
  $handler->display->display_options['filters']['field_expert_user_target_id']['relationship'] = 'reverse_field_expert_user_node';
  $handler->display->display_options['filters']['field_expert_user_target_id']['operator'] = 'not empty';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'realname' => 'realname',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['expert_application_select'] = $view;

  $view = new view();
  $view->name = 'expert_applications';
  $view->description = 'Application for expert evaluators defined by Evaluation expert application content type. Can be moved to MKB Call admin';
  $view->tag = 'MKB Evaluation Expert';
  $view->base_table = 'node';
  $view->human_name = 'Expert applications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Expert applications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'xls';
  $handler->display->display_options['header']['area']['content'] = '<a href="/expert-applications/xls">Download til Excel</a>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_eval_conf_id_target_id']['id'] = 'field_eval_conf_id_target_id';
  $handler->display->display_options['relationships']['field_eval_conf_id_target_id']['table'] = 'field_data_field_eval_conf_id';
  $handler->display->display_options['relationships']['field_eval_conf_id_target_id']['field'] = 'field_eval_conf_id_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_expert_usr_target_id']['id'] = 'field_expert_usr_target_id';
  $handler->display->display_options['relationships']['field_expert_usr_target_id']['table'] = 'field_data_field_expert_usr';
  $handler->display->display_options['relationships']['field_expert_usr_target_id']['field'] = 'field_expert_usr_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Expert user */
  $handler->display->display_options['fields']['field_expert_usr']['id'] = 'field_expert_usr';
  $handler->display->display_options['fields']['field_expert_usr']['table'] = 'field_data_field_expert_usr';
  $handler->display->display_options['fields']['field_expert_usr']['field'] = 'field_expert_usr';
  $handler->display->display_options['fields']['field_expert_usr']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_expert_usr']['alter']['text'] = '[field_expert_usr]';
  $handler->display->display_options['fields']['field_expert_usr']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_expert_usr']['alter']['path'] = 'user-profile/[field_expert_usr-target_id]';
  $handler->display->display_options['fields']['field_expert_usr']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Shortname */
  $handler->display->display_options['fields']['field_expertise_shortname']['id'] = 'field_expertise_shortname';
  $handler->display->display_options['fields']['field_expertise_shortname']['table'] = 'field_data_field_expertise_shortname';
  $handler->display->display_options['fields']['field_expertise_shortname']['field'] = 'field_expertise_shortname';
  $handler->display->display_options['fields']['field_expertise_shortname']['relationship'] = 'field_eval_conf_id_target_id';
  $handler->display->display_options['fields']['field_expertise_shortname']['label'] = 'Area';
  /* Field: Content: Expertise */
  $handler->display->display_options['fields']['field_expert_expertise']['id'] = 'field_expert_expertise';
  $handler->display->display_options['fields']['field_expert_expertise']['table'] = 'field_data_field_expert_expertise';
  $handler->display->display_options['fields']['field_expert_expertise']['field'] = 'field_expert_expertise';
  $handler->display->display_options['fields']['field_expert_expertise']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_expert_expertise']['alter']['trim'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Application';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'field_eval_conf_id_target_id';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Expert selected */
  $handler->display->display_options['fields']['field_expert_selected']['id'] = 'field_expert_selected';
  $handler->display->display_options['fields']['field_expert_selected']['table'] = 'field_data_field_expert_selected';
  $handler->display->display_options['fields']['field_expert_selected']['field'] = 'field_expert_selected';
  $handler->display->display_options['fields']['field_expert_selected']['type'] = 'number_unformatted';
  $handler->display->display_options['fields']['field_expert_selected']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_expert_selected']['delta_offset'] = '0';
  /* Sort criterion: Content: Expert selected (field_expert_selected) */
  $handler->display->display_options['sorts']['field_expert_selected_value']['id'] = 'field_expert_selected_value';
  $handler->display->display_options['sorts']['field_expert_selected_value']['table'] = 'field_data_field_expert_selected';
  $handler->display->display_options['sorts']['field_expert_selected_value']['field'] = 'field_expert_selected_value';
  $handler->display->display_options['sorts']['field_expert_selected_value']['order'] = 'DESC';
  /* Sort criterion: Realname: Real name */
  $handler->display->display_options['sorts']['realname']['id'] = 'realname';
  $handler->display->display_options['sorts']['realname']['table'] = 'realname';
  $handler->display->display_options['sorts']['realname']['field'] = 'realname';
  $handler->display->display_options['sorts']['realname']['relationship'] = 'field_expert_usr_target_id';
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
    'eval_expert_application' => 'eval_expert_application',
  );
  /* Filter criterion: Content: Shortname (field_expertise_shortname) */
  $handler->display->display_options['filters']['field_expertise_shortname_value']['id'] = 'field_expertise_shortname_value';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['table'] = 'field_data_field_expertise_shortname';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['field'] = 'field_expertise_shortname_value';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['relationship'] = 'field_eval_conf_id_target_id';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['operator_id'] = 'field_expertise_shortname_value_op';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['label'] = 'Filter by expertise area';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['description'] = 'Enter first letter(s)';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['operator'] = 'field_expertise_shortname_value_op';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['identifier'] = 'field_expertise_shortname_value';
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_expertise_shortname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    8 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['merge_rows'] = TRUE;
  $handler->display->display_options['field_config'] = array(
    'nid' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'field_expert_usr' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'nothing' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'comment_count' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'name' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['field_config'] = array(
    'nid' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'field_expert_usr' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'field_expertise_shortname' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'field_expert_expertise' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'nothing' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
    'field_expert_selected' => array(
      'merge_option' => 'merge_unique',
      'separator' => '</br>',
    ),
  );
  $handler->display->display_options['path'] = 'expert-applications';
  $export['expert_applications'] = $view;

  return $export;
}
