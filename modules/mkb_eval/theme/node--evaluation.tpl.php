<?php
$content = $variables['content'];
print drupal_render($content['acronym']);
print drupal_render($content['type']);
print drupal_render($content['realname']);
print '</br>';
if(isset($content['questionnaire'])) print $content['questionnaire'];
if(isset($content['score'])) print drupal_render($content['score']);

// Remove elements that are custom printed above
unset($content['acronym']);
unset($content['type']);
unset($content['questionnaire']);
unset($content['score']);
// Print the rest of the content
print drupal_render_children($content);
?>





