<?php
print '<div class="evaluation_pages">';
$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'No applications fulfill the filter for this page.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);
print '</div>';
?>

