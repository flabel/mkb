<?php
drupal_add_js('misc/form.js');
drupal_add_js('misc/collapse.js');

$rows = $variables['rows'];

print '<div class="evaluation_pages">';

// By topic
if(!empty($rows)){
  if($variables['topic']){
    $topics = mkb_eval_get_all_topics();
    $title = '';
    foreach ($rows as $topic_id => $topic){
      $row_topic = $topics[$topic_id];
      print '<p><b><i>' . $row_topic->title . '</i></b></p>';
      foreach ($topic as $eval_type_name => $eval_types){
        $title = $eval_type_name;
        foreach ($eval_types as $gid => $applications){

          foreach ($applications as $eval_nid => $eval){
            $content = '';
            $content .= drupal_render($eval['acronym']);
            $content .= drupal_render($eval['type']);
            $content .= drupal_render($eval['realname']);
            if(isset($eval['questionnaire'])) $content .= drupal_render($eval['questionnaire']);
            if(isset($eval['score'])) $content .= drupal_render($eval['score']);
            $content .= drupal_render_children($eval);

            $section = array(
              '#attributes' => array(
                'class' => array('eval_section'),
                  ),
              '#title' => '',
              '#description' => '',
              '#children' => $content,
            );
            print theme('fieldset', array('element' => $section));
          }
        }
      }
    }
    drupal_set_title($title . ' evaluations');
  }
  // No topic
  else{
    $eval_types = array_keys($rows);
    $eval_type = $eval_types[0];
    drupal_set_title($eval_type . ' evaluations');

    foreach ($rows[$eval_type] as $gid => $applications){
      foreach ($applications as $eval_nid => $eval){
        $content = '';
        $content .= drupal_render($eval['acronym']);
        $content .= drupal_render($eval['type']);
        $content .= drupal_render($eval['realname']);
        if(isset($eval['questionnaire'])) $content .= drupal_render($eval['questionnaire']);
        if(isset($eval['score'])) $content .= drupal_render($eval['score']);
        $content .= drupal_render_children($eval);

        $section = array(
          '#attributes' => array(
            'class' => array('eval_section'),
              ),
          '#title' => '',
          '#description' => '',
          '#children' => $content,
        );
        print theme('fieldset', array('element' => $section));
      }
    }
  }
}
else{
  drupal_set_title('Evaluation review');
  print '<p>There no evaluation of this type yet!</p>';
}
print '</div>';
?>

