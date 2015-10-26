<?php

/**
 * @file
 * Template to display organisation contacts
 *
 * - $variables: Array with necessary data
 */
dpm($variables);
print '<h1>' . t('Organisation contacts') . '</h1>';
print '<ul>';
$old_level = 0;
foreach ($variables['contacts'] as $org) {
  $exposed = $org['data'] -> field_exposed_value;
  if ($exposed == null || $exposed == 1) {
    $this_level = $org['level'];
    if ($this_level > $old_level) print '<ul>';
    if ($this_level < $old_level) print '</ul>';
    print '<li>';
	if ($org['data'] -> nid == $variables['offset_nid']) print '<strong>';
    print $org['data'] -> title;
	if ($org['data'] -> nid == $variables['offset_nid']) print '</strong>';
    $email = $org['data'] -> field_email_value;
    if (!empty($email)) print ' - ' . l($email,'mailto:' . $email);
    if (!empty($org['users'])) {
      foreach ($org['users'] as $user) {
	    if ($user -> field_expose_my_data_value != 0) {
          print ' - ';
          $name = $user -> field_first_name_value . ' ' . $user -> field_last_name_value;
          $uid = $user -> uid;
	      print l($name, 'user-profile/' . $uid);
	    }
   	  }
    }
    print '</li>';
    $old_level = $this_level;  
  }
}
print '</ul>';
?>
