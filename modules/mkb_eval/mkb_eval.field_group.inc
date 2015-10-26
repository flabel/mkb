<?php
/**
 * @file
 * mkb_eval.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function mkb_eval_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conf_expertise|node|evaluation_conf|form';
  $field_group->group_name = 'group_conf_expertise';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_conf';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expertise',
    'weight' => '5',
    'children' => array(
      0 => 'field_expertise_name',
      1 => 'field_expertise_shortname',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-conf-expertise field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_conf_expertise|node|evaluation_conf|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conf_markup|node|evaluation_conf|form';
  $field_group->group_name = 'group_conf_markup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_conf';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Markup',
    'weight' => '22',
    'children' => array(
      0 => 'field_conf_eval_summaries',
      1 => 'field_conf_application_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-conf-markup field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_conf_markup|node|evaluation_conf|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eval_fields|node|evaluation_conf|form';
  $field_group->group_name = 'group_eval_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_conf';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Evaluation fields',
    'weight' => '6',
    'children' => array(
      0 => 'field_conf_options',
      1 => 'field_conf_questions',
      2 => 'field_conf_radio',
      3 => 'field_conf_recommendation',
      4 => 'field_conf_score',
      5 => 'field_conf_text_areas',
      6 => 'field_conf_score_minimum',
      7 => 'field_conf_score_calculation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eval-fields field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eval_fields|node|evaluation_conf|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_eligibility|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_eligibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Eligibility check',
    'weight' => '3',
    'children' => array(
      0 => 'field_filter_eligibility_en',
      1 => 'field_filter_eligibility',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-eligibility field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_eligibility|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_expert_assigned|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_expert_assigned';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expert assigned',
    'weight' => '7',
    'children' => array(
      0 => 'field_filter_expert_assigned',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-expert-assigned field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_expert_assigned|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_formality|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_formality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Formality check',
    'weight' => '2',
    'children' => array(
      0 => 'field_filter_formality_en',
      1 => 'field_filter_formality',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-formality field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_formality|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_partner_budget|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_partner_budget';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Funding agency in partner budget',
    'weight' => '5',
    'children' => array(
      0 => 'field_filter_partner_budget',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-partner-budget field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_partner_budget|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_quality|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_quality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quality check',
    'weight' => '4',
    'children' => array(
      0 => 'field_filter_quality_en',
      1 => 'field_filter_quality',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-quality field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_quality|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_select_1|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_select_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selected 1',
    'weight' => '6',
    'children' => array(
      0 => 'field_filter_select_1_en',
      1 => 'field_filter_select_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-select-1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_select_1|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_select_2|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_select_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selected 2',
    'weight' => '9',
    'children' => array(
      0 => 'field_filter_select_2_en',
      1 => 'field_filter_select_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-select-2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_select_2|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_submit_1|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_submit_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Submitted 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_filter_submit_1_en',
      1 => 'field_filter_submit_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-submit-1 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_submit_1|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_submit_2|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_submit_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Submitted 2',
    'weight' => '8',
    'children' => array(
      0 => 'field_filter_submit_2_en',
      1 => 'field_filter_submit_2',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-submit-2 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_submit_2|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_f_topic|node|evaluation_filter|form';
  $field_group->group_name = 'group_f_topic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'By topic',
    'weight' => '11',
    'children' => array(
      0 => 'field_filter_topic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-f-topic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_f_topic|node|evaluation_filter|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_eligibility|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_eligibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Eligibility check',
    'weight' => '2',
    'children' => array(
      0 => 'field_filter_eligibility',
      1 => 'field_filter_eligibility_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-eligibility field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_eligibility|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_expert_assigned|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_expert_assigned';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expert assigned',
    'weight' => '6',
    'children' => array(
      0 => 'field_filter_expert_assigned',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-expert-assigned field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_expert_assigned|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_formality|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_formality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Formality check',
    'weight' => '1',
    'children' => array(
      0 => 'field_filter_formality',
      1 => 'field_filter_formality_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-formality field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_formality|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_partner_budget|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_partner_budget';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Funding agency in partner budget',
    'weight' => '4',
    'children' => array(
      0 => 'field_filter_partner_budget',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-partner-budget field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_partner_budget|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_quality|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_quality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Quality check',
    'weight' => '3',
    'children' => array(
      0 => 'field_filter_quality',
      1 => 'field_filter_quality_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-quality field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_quality|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_selected_1|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_selected_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selected 1',
    'weight' => '5',
    'children' => array(
      0 => 'field_filter_select_1',
      1 => 'field_filter_select_1_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-selected-1 field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_selected_1|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_selected_2|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_selected_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Selected 2',
    'weight' => '8',
    'children' => array(
      0 => 'field_filter_select_2',
      1 => 'field_filter_select_2_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-selected-2 field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_selected_2|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_submit_1|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_submit_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Submit 1',
    'weight' => '0',
    'children' => array(
      0 => 'field_filter_submit_1',
      1 => 'field_filter_submit_1_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-submit-1 field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_submit_1|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_submitted_2|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_submitted_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Submitted 2',
    'weight' => '7',
    'children' => array(
      0 => 'field_filter_submit_2',
      1 => 'field_filter_submit_2_en',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-submitted-2 field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_submitted_2|node|evaluation_filter|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fv_topic|node|evaluation_filter|default';
  $field_group->group_name = 'group_fv_topic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'evaluation_filter';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'By topic',
    'weight' => '9',
    'children' => array(
      0 => 'field_filter_topic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fv-topic field-group-fieldset',
      ),
    ),
  );
  $export['group_fv_topic|node|evaluation_filter|default'] = $field_group;

  return $export;
}
