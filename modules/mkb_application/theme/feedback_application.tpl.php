<?php
print '<div class="evaluation_pages">';
$gid = $variables['group']['gid'];
drupal_set_title($variables['group']['gid'] . ' ' . $variables['group']['acronym'] . ' - Evaluation results');

if (empty($variables['content'])) print '<strong>No available evaluation</strong>';

foreach ($variables['content'] as $title => $eval_type){
  foreach ($eval_type[$gid] as $eval){
    hide($eval['status']);
    hide($eval['acronym']);
    hide($eval['type']);
	print drupal_render_children($eval);
	print '</br><hr></br>';
  }
}
print '</div>';
?>


