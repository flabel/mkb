<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * hook_form_alter : $form_id == 'evaluation_node_form'
 */
function mkb_eval_evaluation_alter(&$form, &$form_state, $form_id){
  // If in 'edit' mode load gid and eval_conf_nid from evaluation
  // Else get gid and eval_conf_nid from arguments
  if(arg(2) == 'edit'){
    $evaluation = node_load(arg(1));
    $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);
    $gid = $evaluation_wrapper->og_group_ref[0]->raw();
    $eval_conf_nid = $evaluation_wrapper->field_eval_conf->raw();
  }
  else{
    $gid = arg(3);
    $eval_conf_nid = arg(4);
  }
	
  // Hide fields
  $form['field_eval_submit']['#access'] = FALSE;

  // User
  $account = $GLOBALS['user'];

  // Questionnaire and score
  if(isset($gid) && isset($eval_conf_nid)){
    // Set title and remove field
    $form['title']['#default_value'] = $account->uid . '_' . $gid . '_' . $eval_conf_nid;
    $form['title']['#access'] = FALSE;
    // Set gid and remove og_group_ref field from form
    $form['og_group_ref'][LANGUAGE_NONE]['#default_value'][0] = $gid;
    $form['og_group_ref']['#access'] = FALSE;
    // Set Evaluation configuration node id and remove field from form
    $form['field_eval_conf'][LANGUAGE_NONE]['#default_value'] = $eval_conf_nid;
    $form['field_eval_conf']['#access'] = FALSE;

    // Set acronym and group id
    $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
    if($project_info_nids){
      $project_info_node = node_load($project_info_nids[0]);
      $acronym = $project_info_node->field_app_acronym[LANGUAGE_NONE][0]['value'];

      $form['acronym'] = array(
          '#markup' => '<p><b>' . $gid . ' ' . $acronym . '</b></p>',
          '#weight' => -50,
          );
    }
    
    // Load evaluation configuration node
    $eval_conf = node_load($eval_conf_nid);
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);

    // Determine evaluation type
    $eval_type_term = $eval_conf_wrapper->field_eval_conf_type->value();

		// -- Markup
		// -Application link
		$field_app_link = $eval_conf_wrapper->field_conf_application_link->value();
		if($field_app_link){
      $app_link = l('View application with Description of work', 'groups/workspace/application_page/' . $gid, array('attributes'=>array('target'=>'blank')));
      $form['application_link'] = array(
          '#markup' => '<p>' . $app_link . '</p>',
          '#weight' => -49,
          ); 			
		}
		// -Summaries
		$summaries_nids = $eval_conf_wrapper->field_conf_eval_summaries->value();
		if(!empty($summaries_nids)){
			$form['summaries_fieldset'] = array(
					'#type' => 'fieldset', 
					'#title' => t('Evaluation summeries'), 
					'#weight' => -48, 
					'#collapsible' => TRUE, 
					'#collapsed' => TRUE,          
					); 			
					
			$summaries = '';
			foreach ($summaries_nids as $summaries_nid) {
				$summary_conf = node_load($summaries_nid);
				// Load evaluations
				$query = new EntityFieldQuery();
				$query->entityCondition('entity_type', 'node')
					->entityCondition('bundle', 'evaluation')
					->propertyCondition('status', NODE_PUBLISHED)
					->fieldCondition('field_eval_conf', 'target_id', $summary_conf->nid, '=')
					->fieldCondition('og_group_ref', 'target_id', $gid, '=');
				$result = $query->execute();



				// Evaluation(s) exist
				if(isset($result['node'])) {
					$summary_nids = array_keys($result['node']);
					$summary_evals = entity_load('node', $summary_nids);


					foreach($summary_evals as $summary_eval){
						if(!isset($first)) $summaries .= '<hr>';
						$first = true;
						$summary_eval_view = node_view($summary_eval);
						$summaries .= drupal_render($summary_eval_view);
						$summaries .= '<hr>';
					}

				}		

			}	

      $form['summaries_fieldset']['summaries'] = array(
          '#markup' => '<p>' . $summaries . '</p>',
          '#weight' => -47,
          ); 			

		}


    // Options
    $options = array();
    foreach ($eval_conf_wrapper->field_conf_options->getIterator() as $delta => $option_wrapper) {
      $options[] = $option_wrapper->value();
    }

    // Questions
    $questions = array();
    foreach ($eval_conf_wrapper->field_conf_questions->getIterator() as $delta => $question_wrapper) {
      $questions[] = $question_wrapper->value();
    }

    // Score checked? Used to add js to form and onchange call in selectboxes
    $score = $eval_conf_wrapper->field_conf_score->value();
		// Determine score minimum and score calcualtion
		$score_min = $eval_conf_wrapper->field_conf_score_minimum->value();
		$score_calc = $eval_conf_wrapper->field_conf_score_calculation->value();
    
    if($score==1){
      $form['#attached']['js'] = array(drupal_get_path('module', 'mkb_eval') . '/js/score.js');
      // Prevent reload when js is called
      $form['#attributes'] = array();
    }
    else{
      unset($form['field_eval_score']);
    }

    // Build table with question and options
    if(!empty($questions) && !empty($options)){
      // Container
      $form['quest'] = array(
      '#tree' => TRUE,
      '#type' => 'container',
      '#prefix' => '<table class="eval_type_tbl"><th colspan="2">Questionnaire</th>',
      '#suffix' => '</table>',
      '#weight' => 1,
      );

      // Questions and answers in table
      $form['quest']['data'] = array();
      for($i = 0; $i < count($questions); $i++){
        $form['quest']['data'][$i]['question'] = array(
            '#markup' => $questions[$i],
            '#prefix' => '<tr><td class="tbl_question">',
            '#suffix' => '</td>',
            );
        $form['quest']['data'][$i]['options'] = array(
            '#type' => 'select',
            '#options' => $options,
            '#default_value' => isset($evaluation->field_eval_answers[LANGUAGE_NONE][$i]['value']) ? $evaluation->field_eval_answers[LANGUAGE_NONE][$i]['value'] : '',
            '#prefix' => '<td class="tbl_options">',
            '#suffix' => '</td></tr>',
            );

        if($score==1){
          $form['quest']['data'][$i]['options']['#attributes'] = array(
                'onchange' => 'calcScore(' . $score_min . ', ' . $score_calc . '); return false',
                );
        }
      }

      // Score meter - Only show if score calculation is mean
      if($score==1 && $score_calc == 1){
        // Create the meter image with labels from evaluation configuration node options
        $full_image = '';
        $labels = '';
        $image_path = drupal_get_path('module', 'mkb_eval') . '/img/';
        for($i = 0; $i < count($options); $i++){
          $image_file_name = 'meter.png';
          if($i==0){
            $image_file_name = 'meter_start.png';
          }
          if($i==count($options)-1){
            $image_file_name = 'meter_end.png';
          }

          $image_options = array(
            'path' => $image_path . $image_file_name,
            'alt' => 'Calulated score',
            'title' => 'Calulated score',
            'width' => '100px',
            'height' => '20px',
            'attributes' => array('class' => '', 'id' => '', 'style' => 'position: relative; top: 0; left:' . $i*100+50 . ';',),
          );
          $full_image .= theme('image', $image_options);
          $option = $options[$i];
          $option_label = (is_numeric($option[0])) ? $option[0] : $options_label;
          $labels .= '<div class="pointer_label">' . $option_label . '</div>';
        }

        // Create the image of the pointer
        if(isset($evaluation->field_eval_score[LANGUAGE_NONE][0]['value'])){
          // Adjust score pointer position according to score minimum
          $default_score_pos = $evaluation->field_eval_score[LANGUAGE_NONE][0]['value'] - $score_min;
          $pointer_pos = 100*$default_score_pos+50;
          $image_options_pointer = array(
            'path' => $image_path . 'pointer.png',
            'alt' => 'Test alt',
            'title' => 'Test title',
            'width' => '2px',
            'height' => '15px',
            'attributes' => array('class' => 'pointer', 'id' => 'pointer', 'style' => 'position: absolute; top: 23px; left: ' . $pointer_pos . 'px;',),
          );
          $full_image .= theme('image', $image_options_pointer);
        }
        else{
          $pointer_pos = 50;
          $image_options_pointer = array(
            'path' => $image_path . 'pointer.png',
            'alt' => 'Test alt',
            'title' => 'Test title',
            'width' => '2px',
            'height' => '15px',
            'attributes' => array('class' => 'pointer', 'id' => 'pointer', 'style' => 'position: absolute; top: 23px; left: ' . $pointer_pos . 'px;',),
          );
          $full_image .= theme('image', $image_options_pointer);

          // Set default score value to score minimum
          $form['field_eval_score'][LANGUAGE_NONE][0]['value']['#default_value'] = $score_min;
        }

        // Container
        $form['score'] = array(
        '#markup' => '',
        '#prefix' => '<table class="score_tbl">',
        '#suffix' => '</table>',
        '#weight' => 2,
        );

        // Meter
        $form['score']['meter'] = array(
          '#markup' => '<div class="meter_wrapper"><div class="pointer_labels">'. $labels . '</div>' .
            '<div class="pointer_meter">' . $full_image .'</div></div>',
          '#prefix' => '<td>',
          '#suffix' => '</td></tr>',
        );
      }
    }
      // Hide answers field (values are set in validation)
    $form['field_eval_answers']['#access'] = FALSE;

    // Recommendation
    $conf_recommendation = $eval_conf_wrapper->field_conf_recommendation->value();
    if($conf_recommendation == 1){
      $eval_recommendation = $evaluation->field_eval_recommendation[LANGUAGE_NONE][0]['value'];
      $form['field_eval_recommendation'][LANGUAGE_NONE]['#default_value'] =
        isset($eval_recommendation) ? $eval_recommendation : 0;
    }
    else{
      $form['field_eval_recommendation']['#access'] = FALSE;
    }

    // Weight will be variable
    $weight = 10;

    // Radio buttons
    foreach ($eval_conf_wrapper->field_conf_radio->getIterator() as $delta => $radio_wrapper) {
      $radio = $radio_wrapper->value();
      $subs = explode('#', $radio);
      $e_name = 'radio_input_' . $delta;
      $options = array(0 => 'No', 1 => 'Yes');
      $form[$e_name] = array(
          '#title' => $subs[0],
          '#type' => 'radios',
          '#description' => isset($subs[1]) ? $subs[1] : '',
          '#options' => $options,
          '#default_value' => isset($evaluation->field_eval_radio[LANGUAGE_NONE][$delta]['value']) ?
            $evaluation->field_eval_radio[LANGUAGE_NONE][$delta]['value'] : 0,
          '#weight' => $weight++,
          );
    }
    $form['field_eval_radio']['#access'] = FALSE;

    // Text areas
    foreach ($eval_conf_wrapper->field_conf_text_areas->getIterator() as $delta => $txtarea_wrapper) {
      $txtarea = $txtarea_wrapper->value();
      $subs = explode('#', $txtarea);
      $e_name = 'text_area_input_' . $delta;
      $form[$e_name] = array(
          '#title' => $subs[0],
          '#type' => 'textarea',
          '#description' => isset($subs[1]) ? $subs[1] : '',
          '#default_value' => isset($evaluation->field_eval_text_area[LANGUAGE_NONE][$delta]['value']) ?
            $evaluation->field_eval_text_area[LANGUAGE_NONE][$delta]['value'] : '',
					'#rows' => 20,
          '#weight' => $weight++,
          );
    }
    $form['field_eval_text_area']['#access'] = FALSE;
  }
  $form['#validate'][] = 'mkb_eval_evaluation_validate';

  // Evaluation submit buttons
  $form['actions']['submit']['#value'] = 'Save as Incomplete';
  $form['actions']['submit_eval'] = array(
      '#access' => TRUE,
      '#type' => 'submit',
      '#value' => 'Save as Complete',
      '#weight' => 6,
      '#submit' => array(
          0 => 'mkb_eval_evaluation_submit',
          1 => 'node_form_submit',
          )
      );
}

function mkb_eval_evaluation_validate(&$form, &$form_state){
  $values = $form_state['values'];
  $lang = $form_state['values']->language;

  // Set Answers from quest form elements
  $form_state['values']['field_eval_answers'][LANGUAGE_NONE] = array();
  for ($i=0; $i < count($values['quest']['data']); $i++){
    $form_state['values']['field_eval_answers'][LANGUAGE_NONE][$i] = array(
         'value' => $values['quest']['data'][$i]['options'],
        '_weight' => $i,
        );
  }

  // Count number of fields
  $radio_i = 0;
  $text_area_i = 0;
  foreach ($values as $field_name => $field){
    $radio_name = 'radio_input_' . $radio_i;
    $text_area_name = 'text_area_input_' . $text_area_i;
    if($field_name == $radio_name) $radio_i++;
    if($field_name == $text_area_name) $text_area_i++;
  }

  // Set field_eval_radio from custom radio buttons
  $form_state['values']['field_eval_radio'][LANGUAGE_NONE] = array();
  for ($i=0; $i < $radio_i; $i++){
    $e_name = 'radio_input_' . $i;
    $form_state['values']['field_eval_radio'][LANGUAGE_NONE][$i] = array(
         'value' => $values[$e_name],
        '_weight' => $i,
        );
  }

  // Set field_eval_text_area from custom text areas
  $form_state['values']['field_eval_text_area'][LANGUAGE_NONE] = array();
  for ($i=0; $i < $text_area_i; $i++){
    $e_name = 'text_area_input_' . $i;
    $form_state['values']['field_eval_text_area'][LANGUAGE_NONE][$i] = array(
         'value' => $values[$e_name],
        '_weight' => $i,
        );
  }

  // Set evaluation submit as incomplete for other pages
  $form_state['values']['field_eval_submit'][LANGUAGE_NONE][0]['value'] = 0;
}

function mkb_eval_evaluation_submit(&$form, &$form_state){
  // Set evaluation submit as complete for other pages
  $form_state['values']['field_eval_submit'][LANGUAGE_NONE][0]['value'] = 1;
}
