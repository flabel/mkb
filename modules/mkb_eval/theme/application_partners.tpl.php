<?php
$topics = $variables['topics'];
$header = $variables['header'];
$rows = $variables['rows'];

print '<div class="evaluation_pages">';
// print '<h2 class="block-title">Application partner overview for stage 2</h2>';
print '</br>';

foreach ($rows as $topic_id => $topic_applications){
  $topic = $topics[$topic_id];

  $table = array(
      'header' => $header,
      'rows' => $topic_applications,
      'attributes' => array(
          'class' => array('table_class'),
          'width' => '50%',
          ),
      'sticky' => FALSE,
      'empty' => 'No applications for this topic.',
      'colgroups' => array(),
      'caption' => $topic->title,
      );
  print theme_table($table);
  print '<br>';
}
print '</div>';
?>

