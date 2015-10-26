<?php
/**
 * @file
 * mkb_call_admin.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mkb_call_admin_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_partner|node|call_main_page|default';
  $field_group->group_name = 'group_app_partner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application partner info',
    'weight' => '3',
    'children' => array(
      0 => 'field_call_business_plan',
      1 => 'field_call_par_acronym',
      2 => 'field_call_par_add_field_1',
      3 => 'field_call_par_add_field_2',
      4 => 'field_call_par_add_field_3',
      5 => 'field_call_par_add_field_4',
      6 => 'field_call_par_add_field_5',
      7 => 'field_call_publications',
      8 => 'field_call_role',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Application partner info',
      'instance_settings' => array(
        'classes' => ' group-app-partner field-group-fieldset',
        'description' => '<em>Partner information to be filled in by each proposal partner. The pre-defined fields typically used in applications can be deactivated below. In addition there are five fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-partner-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.</em>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_app_partner|node|call_main_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_partner|node|call_main_page|form';
  $field_group->group_name = 'group_app_partner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application partner info',
    'weight' => '4',
    'children' => array(
      0 => 'field_call_business_plan',
      1 => 'field_call_par_acronym',
      2 => 'field_call_par_add_field_1',
      3 => 'field_call_par_add_field_2',
      4 => 'field_call_par_add_field_3',
      5 => 'field_call_par_add_field_4',
      6 => 'field_call_par_add_field_5',
      7 => 'field_call_publications',
      8 => 'field_call_role',
      9 => 'field_call_par_sme',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Application partner info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-app-partner field-group-fieldset',
        'description' => 'Partner information to be filled in by each proposal partner. The pre-defined fields typically used in applications can be deactivated below. In addition there are five fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-project-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.<br><br>Activate or deactive fields in Application-partner-info',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_app_partner|node|call_main_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_project|node|call_main_page|default';
  $field_group->group_name = 'group_app_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application project info',
    'weight' => '2',
    'children' => array(
      0 => 'field_call_app_acronym',
      1 => 'field_call_app_add_field_1',
      2 => 'field_call_app_add_field_2',
      3 => 'field_call_app_add_field_3',
      4 => 'field_call_app_add_field_4',
      5 => 'field_call_app_add_field_5',
      6 => 'field_call_duration',
      7 => 'field_call_expected',
      8 => 'field_call_keywords',
      9 => 'field_call_summary',
      10 => 'field_call_supplementory',
      11 => 'field_call_topics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Application project info',
      'instance_settings' => array(
        'classes' => ' group-app-project field-group-fieldset',
        'description' => '<em>Project information to be filled in by the proposal coordinator. The pre-defined fields typically used in applications can be deactivated below. In addition there are five fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-project-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website</em>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_app_project|node|call_main_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_app_project|node|call_main_page|form';
  $field_group->group_name = 'group_app_project';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application project info',
    'weight' => '3',
    'children' => array(
      0 => 'field_call_app_acronym',
      1 => 'field_call_app_add_field_1',
      2 => 'field_call_app_add_field_2',
      3 => 'field_call_app_add_field_3',
      4 => 'field_call_app_add_field_4',
      5 => 'field_call_app_add_field_5',
      6 => 'field_call_duration',
      7 => 'field_call_expected',
      8 => 'field_call_keywords',
      9 => 'field_call_summary',
      10 => 'field_call_supplementory',
      11 => 'field_call_topics',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Application project info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-app-project field-group-fieldset',
        'description' => 'Project information to be filled in by the proposal coordinator. The pre-defined fields typically used in applications can be deactivated below. In addition there are five fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-project-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.<br><br>
Activate or deactive fields for this call',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_app_project|node|call_main_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_budget|node|call_main_page|default';
  $field_group->group_name = 'group_budget';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application budget',
    'weight' => '21',
    'children' => array(
      0 => 'field_budget_cat_descrip',
      1 => 'field_budget_categories',
      2 => 'field_budget_in_kind',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Application budget',
      'instance_settings' => array(
        'classes' => ' group-budget field-group-fieldset',
        'description' => '<em>The budget can include 1, 2 or 3 project types (e.g., RTD (Research and Technological Dvelopment). Demonstration, and Innovation). The number and definition of type are defined in the main call page. In addition a short description of each project type can be added; these description are presented to applicants in the budget form. A further option is whether project partners with in kind budgets are allowed. If so, the call administrator must create a call-funder page and a funding-scheme page in oder to facilitate in kind funding in the call.
<br>
The budget has pre-defined cost items. The funding agencies can disable cost items they cannot fund in their  funding-scheme pages.</em>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_budget|node|call_main_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_budget|node|call_main_page|form';
  $field_group->group_name = 'group_budget';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application budget',
    'weight' => '5',
    'children' => array(
      0 => 'field_budget_cat_descrip',
      1 => 'field_budget_categories',
      2 => 'field_budget_in_kind',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Application budget',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-budget field-group-fieldset',
        'description' => 'The budget can include 1, 2 or 3 project types (e.g., RTD (Research and Technological Dvelopment). Demonstration, and Innovation). The number and definition of type are defined in the main call page. In addition a short description of each project type can be added; these description are presented to applicants in the budget form.
<br><br>
A further option is whether project partners with in kind budgets are allowed. If so, the call administrator must create a call-funder page and a funding-scheme page in oder to facilitate in kind funding in the call.
<br><br>
The budget has pre-defined cost items. The funding agencies can disable cost items they cannot fund in their  funding-scheme pages.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_budget|node|call_main_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_call_definitions|node|call_main_page|default';
  $field_group->group_name = 'group_call_definitions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call definitions',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_call_documents',
      2 => 'field_call_open',
      3 => 'field_call_open_edit',
      4 => 'field_current_stage',
      5 => 'field_funding_mode',
      6 => 'field_stages',
      7 => 'field_theme_funding',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-call-definitions field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_call_definitions|node|call_main_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_call_definitions|node|call_main_page|form';
  $field_group->group_name = 'group_call_definitions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call definitions',
    'weight' => '1',
    'children' => array(
      0 => 'body',
      1 => 'field_call_documents',
      2 => 'field_call_open',
      3 => 'field_call_open_edit',
      4 => 'field_current_stage',
      5 => 'field_funding_mode',
      6 => 'field_stages',
      7 => 'field_theme_funding',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-call-definitions field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_call_definitions|node|call_main_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_call_office|node|call_main_page|default';
  $field_group->group_name = 'group_call_office';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call office',
    'weight' => '22',
    'children' => array(
      0 => 'field_contact_persons',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Call office',
      'instance_settings' => array(
        'classes' => ' group-call-office field-group-fieldset',
        'description' => '<em>The contact persons in the Call Office can be selected among website users. Contact forms will be available for applicants.</em>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_call_office|node|call_main_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_call_office|node|call_main_page|form';
  $field_group->group_name = 'group_call_office';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Call office',
    'weight' => '6',
    'children' => array(
      0 => 'field_contact_persons',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Call office',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-call-office field-group-fieldset',
        'description' => 'The contact persons in the Call Office can be selected among website users. Contact forms will be available for applicants.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_call_office|node|call_main_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_time_schedule|node|call_main_page|default';
  $field_group->group_name = 'group_time_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Time schedule',
    'weight' => '1',
    'children' => array(
      0 => 'field_date_full_proposals_close',
      1 => 'field_date_full_proposals_notifi',
      2 => 'field_date_full_proposals_open',
      3 => 'field_date_launch',
      4 => 'field_date_pre_preposals_close',
      5 => 'field_date_pre_preposals_notific',
      6 => 'field_date_pre_preposals_open',
      7 => 'field_date_pre_registration_clos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Time schedule',
      'instance_settings' => array(
        'classes' => ' group-time-schedule field-group-fieldset',
        'description' => '<em>Define the important dates and times for the call</em>',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_time_schedule|node|call_main_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_time_schedule|node|call_main_page|form';
  $field_group->group_name = 'group_time_schedule';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'call_main_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Time schedule',
    'weight' => '2',
    'children' => array(
      0 => 'field_date_full_proposals_close',
      1 => 'field_date_full_proposals_notifi',
      2 => 'field_date_full_proposals_open',
      3 => 'field_date_launch',
      4 => 'field_date_pre_preposals_close',
      5 => 'field_date_pre_preposals_notific',
      6 => 'field_date_pre_preposals_open',
      7 => 'field_date_pre_registration_clos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Time schedule',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-time-schedule field-group-fieldset',
        'description' => 'Define the important dates and times for the call. Only filled in dates are displayed. <br>Dates are <strong>only</strong>  only used as information for applicants, they are <strong>not</strong> used to open or close submission.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_time_schedule|node|call_main_page|form'] = $field_group;

  return $export;
}
