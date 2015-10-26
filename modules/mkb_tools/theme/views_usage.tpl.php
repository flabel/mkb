<?php
$m_header = $variables['m_header'];
$m_rows = $variables['m_rows'];

print '<div class="mkb_tools">';
$table = array(
    'header' => $m_header,
    'rows' => $m_rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '50%',
        ),
    'sticky' => TRUE,
    'empty' => 'No views in use.',
    'colgroups' => array(),
    'caption' => 'Mapped views: views that are directly linked to menu',
    );
print theme_table($table);
print '<p><i>Hidden: </br>0 = Normal visible menu item </br>1 = Disabled menu item that may be shown on
    admin screens </br>-1 = Menu callback</i></p>';

print '</br>';

$u_header = $variables['u_header'];
$u_rows = $variables['u_rows'];
$table = array(
    'header' => $u_header,
    'rows' => $u_rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '50%',
        ),
    'sticky' => TRUE,
    'empty' => 'No views in use.',
    'colgroups' => array(),
    'caption' => 'Unmapped views: views that are NOT directly linked to menu',
    );
print theme_table($table);

print '</div>';
?>