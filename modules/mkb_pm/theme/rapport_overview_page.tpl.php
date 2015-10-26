<?php
print '<div class="evaluation_pages">';
print '<p class="rapport_title">' . $variables['page_title'] . ' (' . $variables['count'] . ')' . '</p>';
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
    'caption' => '<h2>' . $variables['page_description'] . '</h2>',
    );
print theme_table($table);
print '</div>';
?>

