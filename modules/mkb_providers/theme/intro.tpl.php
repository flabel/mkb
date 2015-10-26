<?php


// dpm($variables);

// Provider's organisation id
$pid = $variables['provider']->nid;
$uuid = $variables['provider']->uuid;

// Welcome to invited ICT provider person
if (user_is_logged_in()) {
  global $user;
  $uid = $user->uid;
  $user_data = user_load($uid);
  $first_name = $user_data->field_first_name['und'][0]['value'];
  $last_name = $user_data->field_last_name['und'][0]['value'];
  if (isset($user_data->field_expose_my_data['und'][0]['value'])) $expose_data = $user_data->field_expose_my_data['und'][0]['value'];
  else $expose_data = null;
  print '<h3>' . t('Dear ') . $first_name . ' ' . $last_name;
}
else print '<h3>' . t('Dear Manager');
print ', ' . $variables['provider']->title . '</h3>';

print '<p>';
print t('Thank you for responding to our invitation to contribute to the ICT-AGRI survey of providers of ICT to agriculture');
print '</p>';
print '<p>';
print t('ICT-AGRI is conducting a survey among providers of ICT to farmers. The purpose is to get an overview of agricultural ICT providers in Europe and the services they provide to farmers. A special focus of the survey is on the current use and interest for interoperability and data sharing. ICT-AGRI will use the information from the survey in the planning of upcoming calls for European projects about improving the use of ICT in agriculture.');
print '</p>';
print '<p>';
print t('By responding to the survey you will automatically be informed about calls for projects. Your may be invited to participate in projects and you can search the ICT-AGRI database for partners for your own projects. The first call, to be announced in August 2014, is in collaboration with SmartAgriFood. This call will give financial and technical support to web developers and SMEs concerning use of Future Internet technologies.');
print '</p>';

print '<p>';
print '<strong>' . t('How to participate in the survey') . '</strong>';
print '</p>';

// User is not logged in
if (!user_is_logged_in()) {
  print '<p>' . t('To participate in the survey, you need to have an account in the ICT-AGRI Meta Knowledge Base. ') . '</p>';
  // Check if there is an account with contact email
  $query = db_select('field_data_field_email', 'org');
  $query->leftJoin('users', 'users', 'users.mail =org.field_email_value');
  $query->leftJoin('field_data_field_first_name', 'fn', 'fn.entity_id=users.uid');
  $query->leftJoin('field_data_field_last_name', 'ln', 'ln.entity_id=users.uid');
  $query
  ->fields('users', array('mail','login'))
  ->fields('fn', array('field_first_name_value'))
  ->fields('ln', array('field_last_name_value'))
  ->condition('org.entity_id', $pid);
  $result = $query->execute()->fetchAll();
  if (!empty($result[0]->mail)) {
  // There is an account associated with the contact email
	print '<p>';
    print t('There is a user account for ');
	print '<strong>' . $result[0] -> field_first_name_value . ' ' . $result[0] -> field_last_name_value . ' </strong>';
	print t('associated with the email address ');
	print '<strong>' . $result[0] -> mail . ' </strong>';
	print '</p>';
	if ($result[0] -> login) {
  // Account used
      print '<p>';
	  print t('The account was last visited ');
	  print date('d-m-y',$result[0] -> login) . '. ';
	  print t('To continue, please ');
      print '<strong>';
      print l(t('login'), 'user/login', array('query' => array('destination' => 'provider/intro/' . $uuid) ) );
      print '</strong>';
	  print '</p>';
	}
	else {
  // Account never used = old MKB  
	  print '<p>';
      print t('This seems to be an account that has been transferred from the previous version of the ICT-AGRI Meta Knowledge Base. Please activate and amend your account by requesting a new password by email: ');
      print '<strong>';
      print l(t('Request new password'), 'user/password', array('query' => array('destination' => 'provider/intro/' . $uuid) ) );
      print '</strong>';
	  print '</p>';
	}
	print '<p>';
	print t('If this user account is not yours, then please create a new account.');
	print '</p>';
  }
// Create new user
  $path_args = explode('/', current_path());
  if (isset($path_args[3]) && $path_args[3] == 'new_account') {
	print '<strong>';
	print t('For security reasons you are requested to verify your e-mail address. Please use the link in the e-mail sent to you, and after setting your password, refresh this page');
	print '</strong>';
  }
  else {
	print '<p>';
	print '<strong>';
	print l(t('Create an account'), 'user/register/', array('query' => array('destination' => 'provider/intro/' . $uuid . '/new_account') ) );
	print '</strong>';
	print '<p>' . t('If you already have a user account, then please ') . '&nbsp;';
	print '<strong>';
	print l(t('login'), 'user/login', array('query' => array('destination' => 'provider/intro/' . $uuid) ) ) . ' ';
	print t('for company ') . $po_node->title;
	print '</strong>';
	print '</p>';
  }
}

// User is logged in
if (user_is_logged_in()) {

// Get provider-organisation node id
  $query = db_select('field_data_field_provider_parent', 'pp');
  $query
  ->fields('pp', array('entity_id'))
  ->condition('pp.field_provider_parent_target_id', $pid);
  $result = $query->execute()->fetchAll();
  if (!empty($result)) $po_id = $result[0] -> entity_id;
  else $po_id = null;

// Create provider organisation if missing
  if (!isset($po_id)) {
    $po_id = mkb_providers_create_provider_organisation_node($pid);
  } 
  
// Make user author of the provider-organisation node if he is not already
  if (isset($po_id)) {
    $po_node = node_load($po_id);
    if ($po_node->uid != $uid) {
	  db_update('node') 
        -> fields(array('uid' => $uid, ))
        -> condition('nid', $po_id, '=')
        -> execute();
    }
  }
  
  if ($expose_data != 1) {
// Change expose_my_data setting 
    print '<p>' . t('Your account is set to NOT expose your data to website visitors. You will therefore miss the opportunity to be contacted for participation in calls and other business propositions. You can easily change this setting. Your email address is never exposed; contacts are made by email, which you can choose not to reply. ' . '</p>');
    print '<p><strong>';
    print l(t('Change exposure setting'), 'user/' . $uid . '/edit/', array('query' => array('destination' => 'provider/intro/' . $uuid) ) );
    print '</strong></p>';

// Goto survey without expose data
    print '<p>' . t('You may fill in the survey questionnaire without exposing your data. Your response to the survey will then only be used in anonymous statistics of the survey.' . '</p>');
    print '<p><strong>';
    print l(t('Go to survey questionnaire'), 'provider/overview/' . $po_id);
    print '</strong></p>';
  }
  else {

// Make user author of the provider node if he is not already
    if ($variables['provider']->uid != $uid) {
	  db_update('node') 
        -> fields(array('uid' => $uid, ))
        -> condition('nid', $pid, '=')
        -> execute();
  
// Set exposed to 1 in organisation
  	  db_update('field_data_field_exposed') 
        -> fields(array('field_exposed_value' => '1', ))
        -> condition('entity_id', $pid, '=')
        -> execute();
    }
  
// Create profile if he does not already have one  
    $profile2 = profile2_load_by_user($user->uid,'main');
    if (empty($profile2)) {
      $profile = profile_create(array('type' => 'main', 'uid' => $uid));
      $lang = LANGUAGE_NONE;
      $profile->field_my_organisation[$lang][0]['target_id'] = $pid;
      $form_state = array();
      $form_state['values'] = array();
      $form_state['values']['profile_main'] = array();
      $form = array();
      $form['#parents'] = array();
      field_attach_submit('profile2', $profile, $form, $form_state); // attach $profile to profile2 submit
      $profile->bundle = 'main'; // main is the profile type which is created in step 3
      profile2_save($profile); // save profile
//	  dpm($profile);
    }
    
    print '<p>' . t('You have a profile in your account. You can edit your profile in Home => My profile.') . '</p>';
    print '<p>' . t('ICT-AGRI has entered data about your company. You can edit these data in Community => My organisations.') . '</p>';
    print '<p>' . t('Please move on to the ');
    print '<strong>';
    print l(t('survey questionnaire'), 'provider/overview/' . $po_id);
    print '</strong>';
    print t(' for company ') . '<strong>' .  $po_node->title . '</strong>';
    print '</p>';
  }
}
?>
