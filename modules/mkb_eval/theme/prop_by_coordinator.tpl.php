<?php
print '<div class="evaluation_pages">';
drupal_set_title('Proposals by Coordinator country');
$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no project-info coordinators for this call.',
    'colgroups' => array(),
    'caption' => $variables['description'],
    );
print theme_table($table);

print '</div>';
?>

