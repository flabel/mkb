<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * hook_form_alter : $form_id == 'evaluation_expert_node_form'
 */
function mkb_eval_evaluation_expert_alter(&$form, $form_state, $form_id){
    $account = $GLOBALS['user'];

	// Set and hide title
    $form['title']['#default_value'] = 'Evaluation expert application';
    $form['title']['#access'] = FALSE;

	// Set and hide expert_user field
    //$form['field_expert_usr']['und']['#default_value'] = $account->uid;
    //$form['field_expert_usr']['#access'] = FALSE;
    $form['field_expert_future_contact']['und']['#title'] = $form['field_expert_future_contact']['und']['#description'];

    // Hide Expert selected
    $form['field_expert_selected']['#access'] = FALSE;
}
