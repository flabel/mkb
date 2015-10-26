<?php
print drupal_render($content['field_call_id']);
print drupal_render($content['field_funding_agency']);
print drupal_render($content['field_country_specific']);

if (isset($content['field_fp_theme_funding']['#title'])) print "<label>" . $content['field_fp_theme_funding']['#title'] . "</label>";
print "<table class='table_trimmed_no_b'>";
for($i=0;$i<count($variables['field_fp_theme_funding']); $i++){
  print "<tr>";
    print "<td>" . $variables['topic_labels'][0][$i]->title . " (1000 €):" . "</td>";
    print "<td>" . $variables['field_fp_theme_funding'][$i]['value'] . "</td>";
  print "</tr>";
}
print "</table>";

print "<b>" . $content['field_funding']['#title'] . " (1000 €):" . "</b>";
print "<p>" . $variables['field_funding'][0]['value'] . "</p>";


print drupal_render($content['field_conditions_short']);
print drupal_render($content['field_conditions_full']);
print drupal_render($content['field_contact_persons']);
print drupal_render($content['field_call_managers']);
print drupal_render($content['field_evaluators']);

hide($content['field_funding']);
hide($content['field_fp_theme_funding']);
print drupal_render_children($content);
?>





