<?php
print '<div class="evaluation_pages">';
$caption = 'Relations for ' . $variables['acronym_x'];
if(isset($variables['acronym_y'])) $caption .= ' and ' . $variables['acronym_y'];

$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no relations between the two selected proposals.',
    'colgroups' => array(),
    'caption' => $caption,
    );
print theme_table($table);
print '</div>';
?>

