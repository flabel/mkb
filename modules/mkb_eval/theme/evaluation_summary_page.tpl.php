<?php
drupal_set_title($variables['title'] . ' summaries');
print '<div class="evaluation_pages">';

print '<h2>' . $variables['topic'] . '</h2>';
foreach ($variables['content'] as $gid => $group){
  $caption = '<div class="application">' . $gid . ' ' . $group['acronym'] . '</br>' .$group['title'] . '</div>';
  if(isset($group['tables'])){
    $set_caption = true;
    foreach ($group['tables'] as $type => $table){
      // Build rows
      $arr_rows = array();
      $i = 0;
      foreach ($table['rows'] as $row){
        // Create each row
        $row_data = array();
        $j = 0;
        foreach ($row as $field){
          // Create each field
          $field_to_add = array(
              'data' => $field,
              );

          if($header[$j] == 'Country'){
            $field_to_add['class'] = 'width_30';
          }
          elseif($header[$j] == 'Recommendation'){
            $field_to_add['class'] = 'width_30';
          }
          elseif($header[$j] == 'Answers'){
            $field_to_add['class'] = 'width_60';
          }
          elseif($header[$j] == 'Score'){
            $field_to_add['class'] = 'width_10';
          }                    
          elseif($header[$j] == 'Comment'){
            $field_to_add['class'] = 'comment';
          } 
          
          // Add each field to rows
          $row_data[$j] = $field_to_add;
          $j++;
        }
        $arr_rows[$i] = array('data' => $row_data, 'class' => array());
        $i++;
      }

      $table_print = array(
          'header' => $variables['header'],
          'rows' => $arr_rows,
          'attributes' => array(
              'class' => array('table_auto_width'),
              ),
          'sticky' => FALSE,
          'empty' => 'No evaluations of this type.',
          'colgroups' => array(),
          'caption' => '',
          );
      if ($set_caption) {
  	    $table_print['caption'] = $caption;
        $set_caption = false;
      }
	  print theme_table($table_print);
    }
    print '</br>';
  }
}
print '</div>';
?>

