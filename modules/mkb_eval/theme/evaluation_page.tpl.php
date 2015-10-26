<?php
// Excel
//$excel = array(
  //'filename' => $variables['page_title'],
  //'header' => $variables['header'],
  //'rows' => $variables['content'],
//);
//mkb_basic_export_csv($excel);
print '<div class="evaluation_pages">';
// Page
print '<h2>' . $variables['page_title'] . ' (' . $variables['count'] . ')' . '</h2>';
$table = array(
    'header' => $variables['header'],
    'rows' => $variables['content'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'No applications fulfill the filter for this page.',
    'colgroups' => array(),
    'caption' => $variables['page_description'],
    );
print theme_table($table);
print '</div>';
?>

