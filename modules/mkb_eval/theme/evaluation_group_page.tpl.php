<?php
drupal_add_js('misc/form.js');
drupal_add_js('misc/collapse.js');
print '<div class="evaluation_pages">';

$gid = $variables['group']['gid'];
drupal_set_title($variables['group']['gid'] . ' ' . $variables['group']['acronym']);

$count = count($variables['content']);
foreach ($variables['content'] as $title => $eval_type){
  // Dont show content in collapsible sections if there is only one evaluation type
  if($count==0){
    print '<h3>'. $title . '</h3>';
    foreach ($eval_type[$gid] as $eval){
      print drupal_render($eval['status']);
      print drupal_render($eval['acronym']);
      print drupal_render($eval['type']);
      print drupal_render($eval['realname']);
      if(isset($eval['questionnaire'])) print drupal_render($eval['questionnaire']);
      if(isset($eval['score'])) print drupal_render($eval['score']);
      if(isset($eval['recommendation'])) print drupal_render($eval['recommendation']);
      print drupal_render_children($eval);
      $collapsed_content .= '</br>';
    }
  }
  else{
  $collapsed_content = '';
    foreach ($eval_type[$gid] as $eval){
      $collapsed_content .= drupal_render($eval['status']);
      $collapsed_content .= drupal_render($eval['acronym']);
      $collapsed_content .= drupal_render($eval['type']);
      $collapsed_content .= drupal_render($eval['realname']);
      if(isset($eval['questionnaire'])) $collapsed_content .= drupal_render($eval['questionnaire']);
      if(isset($eval['score'])) $collapsed_content .= drupal_render($eval['score']);
      if(isset($eval['recommendation'])) $collapsed_content .= drupal_render($eval['recommendation']);
      $collapsed_content .= drupal_render_children($eval);
      $collapsed_content .= '</br><hr>';
    }

    $section = array(
      '#attributes' => array(
        'class' => array('collapsible', 'collapsed'),
          ),
      '#title' => $title,
      '#description' => '',
      '#children' => $collapsed_content,
    );
    print theme('fieldset', array('element' => $section));
  }
}
print '</div>';
?>

