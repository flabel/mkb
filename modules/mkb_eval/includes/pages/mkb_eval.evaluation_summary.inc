<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_summary_page template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   filter node id.
 * @param $eid
 *   Evaluation configuration node id.
 * @param $tid (optional)
 *   Call topic nid.
 * @return template
 *   The template evaluation_summary_page_template is called with $content.
 */
function evaluation_summary_page_function($cid, $fid, $eid, $tid = NULL){
  // Get filtered groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid, $eid, $tid);

  // Get evaluation configuration
  $eval_conf = node_load($eid);
  $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
  $title = $eval_conf_wrapper->label();
  
  // Get filter
  $filter = node_load($fid);
  $filter_wrapper = entity_metadata_wrapper('node', $filter);
  
  // Build table header from filter and evaluation configuration
  $header = array();
  $filter_contry = $filter_wrapper->field_filter_partner_budget->value();
  if($filter_contry == 1) $header[] = 'Country';
  $eval_conf_rec = $eval_conf_wrapper->field_conf_recommendation->value();
  if($eval_conf_rec == 1) $header[] = 'Recommendation';
  $eval_conf_questions = $eval_conf_wrapper->field_conf_questions->value();
  if(!empty($eval_conf_questions)) $header[] = 'Answers';
  $eval_conf_score = $eval_conf_wrapper->field_conf_score->value();
  if($eval_conf_score == 1) $header[] = 'Score';  
  $eval_conf_comments = $eval_conf_wrapper->field_conf_text_areas->value();
  if(!empty($eval_conf_comments)) $header[] = 'Comment';

  // Get allowed values for evaluation recommendation
  $recommendation_allowed = mkb_eval_get_allowed_values('field_eval_recommendation');
  
  $content = array();
  foreach($groups as $gid => $group){
    // Get application data
    $project_info = $group->applications['application_project_info'];
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
    $content[$gid]['acronym'] = $project_info_wrapper->field_app_acronym->value();
    $content[$gid]['title'] = $project_info_wrapper->label();

    // Get evaluation data
    $evaluations = mkb_eval_get_evaluations($gid, array($eid => $eid));
    $i = 0;
    foreach($evaluations as $nid => $evaluation){
      $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);
        //Title = Evaluation type
        //$content[$gid][$eval_conf->type]['type'] = $eval_conf->title;
      
      //$content[$gid]['tables'][$eval_conf->type]['header'] =  $header;

      // Country      
      if(in_array('Country', $header)){      
        $funder_pages = array_merge(mkb_eval_get_manager_funder_pages($cid, $evaluation->uid),
                             mkb_eval_get_evaluator_funder_pages($cid, $evaluation->uid));
        $content[$gid]['tables'][$eval_conf->type]['rows'][$i]['country'] = mkb_eval_get_funder_page_country(end($funder_pages));
      }
      
      // Recommendation
      if(in_array('Recommendation', $header)){      
        $recommendation_value = $evaluation_wrapper->field_eval_recommendation->value();
        $content[$gid]['tables'][$eval_conf->type]['rows'][$i]['recommendation'] = $recommendation_allowed[$recommendation_value];
      }

      // Answers
      if(in_array('Answers', $header)){            
        $answers = '';
        foreach ($evaluation_wrapper->field_eval_answers->getIterator() as $delta => $eval_answer) {
//          $answers .= ' ' . $eval_answer->value();
// Should be depending on minimum score in evaluation form
          $score = $eval_answer->value() + 1;
          $answers .= ' ' . $score;
        }
        $content[$gid]['tables'][$eval_conf->type]['rows'][$i]['answers'] = $answers;
      }
      
      // Score
      if(in_array('Score', $header)){            
        $score = $evaluation_wrapper->field_eval_score->value();
        $content[$gid]['tables'][$eval_conf->type]['rows'][$i]['score'] = $score;
      }      

      // Comment
      if(in_array('Comment', $header)){                  
        $comments = '';
        $count = $evaluation_wrapper->field_eval_text_area->count();
        if($count == 1){
          $comments = $evaluation_wrapper->field_eval_text_area[0]->value();
        }
        else{
          foreach ($evaluation_wrapper->field_eval_text_area->getIterator() as $delta => $eval_comment) {
            $no = $delta+1;
            $comments .= '<b>#' . $no . '</b></br>' . $eval_comment->value() . '</br>';
          }
        }
        $content[$gid]['tables'][$eval_conf->type]['rows'][$i]['comment'] = isset($comments) ? $comments : '';
      }
      $i++;
    }
  }
  
  // Set topic text
  if(isset($tid)){
    $topic = node_load($tid);
    $variables['topic'] = $topic->title;
  }
  $variables['title'] = $title;  
  $variables['header'] = $header;    
  $variables['content'] = $content;  
  
  return theme('evaluation_summary_page_template', $variables);
}
