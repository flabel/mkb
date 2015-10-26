<?php
/**
 * @file
 * mkb_pdf.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mkb_pdf_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pdf_all_applications_in_call';
  $view->description = 'PDF generation of all applications in a call';
  $view->tag = 'MKB PDF';
  $view->base_table = 'node';
  $view->human_name = 'PDF All applications in call';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PDF All applications in call';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_group_application_node']['id'] = 'reverse_field_group_application_node';
  $handler->display->display_options['relationships']['reverse_field_group_application_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_group_application_node']['field'] = 'reverse_field_group_application_node';
  /* Relationship: OG membership: OG membership from Node group */
  $handler->display->display_options['relationships']['og_membership_rel_group']['id'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['table'] = 'node';
  $handler->display->display_options['relationships']['og_membership_rel_group']['field'] = 'og_membership_rel_group';
  $handler->display->display_options['relationships']['og_membership_rel_group']['relationship'] = 'reverse_field_group_application_node';
  /* Relationship: OG membership: Node from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_node']['id'] = 'og_membership_related_node';
  $handler->display->display_options['relationships']['og_membership_related_node']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_node']['field'] = 'og_membership_related_node';
  $handler->display->display_options['relationships']['og_membership_related_node']['relationship'] = 'og_membership_rel_group';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'reverse_field_group_application_node';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'PDF generation';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_create_newsletter' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::mkb_pdf_all_call_applications_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::mimemail_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::mkb_providers_survey_mail_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'subject' => '',
        'body' => array(
          'value' => '',
          'format' => 'plain_text',
        ),
      ),
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_group_application_node';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  /* Field: Content: Acronym */
  $handler->display->display_options['fields']['field_app_acronym']['id'] = 'field_app_acronym';
  $handler->display->display_options['fields']['field_app_acronym']['table'] = 'field_data_field_app_acronym';
  $handler->display->display_options['fields']['field_app_acronym']['field'] = 'field_app_acronym';
  $handler->display->display_options['fields']['field_app_acronym']['relationship'] = 'og_membership_related_node';
  $handler->display->display_options['fields']['field_app_acronym']['label'] = 'Application';
  $handler->display->display_options['fields']['field_app_acronym']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'og_membership_related_node';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'reverse_field_group_application_node';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_group_application_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'group' => 'group',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'og_membership_related_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'application_project_info' => 'application_project_info',
  );
  /* Filter criterion: Content: app_selected_1 (field_app_selected_1) */
  $handler->display->display_options['filters']['field_app_selected_1_value']['id'] = 'field_app_selected_1_value';
  $handler->display->display_options['filters']['field_app_selected_1_value']['table'] = 'field_data_field_app_selected_1';
  $handler->display->display_options['filters']['field_app_selected_1_value']['field'] = 'field_app_selected_1_value';
  $handler->display->display_options['filters']['field_app_selected_1_value']['relationship'] = 'og_membership_related_node';
  $handler->display->display_options['filters']['field_app_selected_1_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_app_selected_1_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['operator_id'] = 'field_app_selected_1_value_op';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['label'] = 'Submitted - Stage 1';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['operator'] = 'field_app_selected_1_value_op';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['identifier'] = 'field_app_selected_1_value';
  $handler->display->display_options['filters']['field_app_selected_1_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: app_selected_2 (field_app_selected_2) */
  $handler->display->display_options['filters']['field_app_selected_2_value']['id'] = 'field_app_selected_2_value';
  $handler->display->display_options['filters']['field_app_selected_2_value']['table'] = 'field_data_field_app_selected_2';
  $handler->display->display_options['filters']['field_app_selected_2_value']['field'] = 'field_app_selected_2_value';
  $handler->display->display_options['filters']['field_app_selected_2_value']['relationship'] = 'og_membership_related_node';
  $handler->display->display_options['filters']['field_app_selected_2_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_app_selected_2_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_app_selected_2_value']['expose']['operator_id'] = 'field_app_selected_2_value_op';
  $handler->display->display_options['filters']['field_app_selected_2_value']['expose']['label'] = 'Submitted - Stage 2';
  $handler->display->display_options['filters']['field_app_selected_2_value']['expose']['operator'] = 'field_app_selected_2_value_op';
  $handler->display->display_options['filters']['field_app_selected_2_value']['expose']['identifier'] = 'field_app_selected_2_value';
  $handler->display->display_options['filters']['field_app_selected_2_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'pdf-all-applications/%';
  $export['pdf_all_applications_in_call'] = $view;

  return $export;
}
