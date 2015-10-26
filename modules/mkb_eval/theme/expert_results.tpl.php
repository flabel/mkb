<?php
print '<div class="evaluation_pages">';
$table = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '50%',
        ),
    'sticky' => FALSE,
    'empty' => 'Missing expert evaluations.',
    'colgroups' => array(),
    'caption' => 'Click on an application ID link to see all evaluations.',
    );
print theme_table($table);
print '</div>';
?>

