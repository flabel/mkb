<?php
/**
 * @file
 * mkb_eval.custom_filters.inc
 */

/**
 * Define filters.
 *
 * @return $filters
 *   filters for evaluation_page template.
 */
function mkb_eval_get_custom_filters(){
    $filters = array(
        0 => array(
            'submitted' => TRUE,
            'approved_in_formality' => FALSE,
            'approved_in_eligible' => FALSE,
            'funding_agency_in_partner_budget' => FALSE,
            'selected_1' => FALSE,
            'experts_assigned' => FALSE,
            ),
        1 => array(
            'submitted' => TRUE,
            'approved_in_formality' => FALSE,
            'approved_in_eligible' => FALSE,
            'funding_agency_in_partner_budget' => FALSE,
            'selected_1' => FALSE,
            'experts_assigned' => FALSE,
            ),
        2 => array(
            'submitted' => TRUE,
            'approved_in_formality' => FALSE,
            'approved_in_eligible' => FALSE,
            'funding_agency_in_partner_budget' => TRUE,
            'experts_assigned' => FALSE,
            'selected_1' => FALSE,
            'experts_assigned' => FALSE,
            ),
        3 => array(
            'submitted' => TRUE,
            'approved_in_formality' => TRUE,
            'approved_in_eligible' => FALSE,
            'funding_agency_in_partner_budget' => FALSE,
            'selected_1' => FALSE,
            'experts_assigned' => FALSE,
            ),
        5 => array(
            'submitted' => TRUE,
            'approved_in_formality' => TRUE,
            'approved_in_eligible' => TRUE,
            'funding_agency_in_partner_budget' => TRUE,
            'selected_1' => FALSE,
            'experts_assigned' => FALSE,
            ),
        6 => array(
            'submitted' => TRUE,
            'approved_in_formality' => FALSE,
            'approved_in_eligible' => FALSE,
            'funding_agency_in_partner_budget' => FALSE,
            'selected_1' => FALSE,
            'experts_assigned' => TRUE,
            ),
        7 => array(
            'submitted' => FALSE,
            'approved_in_formality' => FALSE,
            'approved_in_eligible' => FALSE,
            'funding_agency_in_partner_budget' => FALSE,
            'selected_1' => TRUE,
            'experts_assigned' => FALSE,
            ),
    );
    return $filters;
}
