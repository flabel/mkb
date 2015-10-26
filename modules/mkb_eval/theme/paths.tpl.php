<?php
print '<div class="evaluation_pages">';
drupal_set_title('Paths in evaluation module');
$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no paths in the evaluation module. The module is not working properly.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);

print '</div>';
?>

