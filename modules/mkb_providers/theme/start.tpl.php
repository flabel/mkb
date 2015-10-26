<?php
print '<h1>' . t('Participation in the ICT provider survey') . '</h1>';
print '<p>';
print t('Thank you for responding to our invitation to contribute to the ICT-AGRI survey of providers of ICT to agriculture. This page will lead you through a few necessary steps before you can participate in the survey.');
print '</p>';
print '<p>';
//print '<h2>' . t('How to participate in the survey') . '</h2>';
print '</p>';print t('You need to be logged in and have a company/organisation to represent in the survey.');print '</p>';
print '<h2>' . t('User login') . '</h2>';

// Set flag for checks passed
$user_checks_ok = false;
$survey_checks_ok = false;

// Get user id (if logged in) and check if user has a profile
if (user_is_logged_in()) {
  global $user;
  $uid = $user->uid;
  $profile2 = profile2_load_by_user($user->uid,'main');
  $has_profile = !empty($profile2);
}
else $has_profile = false;

// Confirm the user's choice or organisation
if (user_is_logged_in() && arg(2) == 'confirm') {
  $organisation_id = arg(3);
// Create profile
  if (!$has_profile) {
    $profile = profile_create(array('type' => 'main', 'uid' => $uid));
    $lang = LANGUAGE_NONE;
    $profile->field_my_organisation[$lang][0]['target_id'] = $organisation_id;
    $form_state = array();
    $form_state['values'] = array();
    $form_state['values']['profile_main'] = array();
    $form = array();
    $form['#parents'] = array();
    field_attach_submit('profile2', $profile, $form, $form_state); // attach $profile to profile2 submit
    $profile->bundle = 'main'; // main is the profile type which is created in step 3
    profile2_save($profile); // save profile
    $profile2 = profile2_load_by_user($uid,'main');
    $has_profile = !empty($profile2);
  }
}
  
// Is the user logged in?
  if (!user_is_logged_in()) {
    print '<p>';
    print t('If you are not a user yet, you have to ') . '&nbsp;';
//  print '</p>';
//  print '<p>';
    print '<strong>';
    print l(t('create an account.'), 'user/register/', array('query' => array('destination' => 'provider/start')));
    print '</strong>';
    print '</p>';
    print '<p>' . t('If you already have a user account, then please ') . '&nbsp;';
    print '<strong>';
    print l(t('login.'), 'user/login', array('query' => array('destination' => 'provider/start')));
    print '</strong>';
    print '</p>';
    print '<p>' . t('You may have a user account in the previous version of the ICT-AGRI Meta Knowledge Base. You can activate that account by ')  . '&nbsp;';
    print '<strong>';
    print l(t('requesting a new password'), 'user/password', array('query' => array('destination' => 'provider/start')));
    print '</strong>';
    print '</p>';
  }
if (user_is_logged_in()) {
  $user_data = user_load($uid);
  $first_name = $user_data->field_first_name['und'][0]['value'];
  $last_name = $user_data->field_last_name['und'][0]['value'];
  if (isset($user_data->field_expose_my_data['und'][0]['value'])) $expose_data = $user_data->field_expose_my_data['und'][0]['value'];
  else $expose_data = null;
  print '<p>';
  print t('You are logged in as ') . '&nbsp;'; 
  print '<strong>';
  print $first_name . ' ' . $last_name . '<br>';
  print '</strong>';

// Does the user have a profile?
  if ($has_profile) {
// Is my organisation selected?
    if (!empty($profile2 -> field_my_organisation)) {
// Find and print my organisation
      $my_org_nid = $profile2 -> field_my_organisation['und'][0]['target_id'];
      $my_org = node_load($my_org_nid);
      $my_org_name = $my_org -> field_org_name['und'][0]['value'];
      print '<p><h2>' . t('Company/organisation information') . '</h2>';
	  print t('The company/organisation selected for the survey is ') . '&nbsp;';
      //print '<ul><li>' . $my_org_name . '</li></ul>';  
      print $my_org_name . '<br>';  
	  print t('You can change this by choosing a different "My organisation" in your profile. ');
      print l(t('Edit my profile'), 'profile-main/' . $uid .'/edit/', array('query' => array('destination' => 'provider/start')));
// Is my organisation of type ICT provider?
/*
      $org_types = $my_org -> field_organisation_type['und'];
      $ict_provider = false;
      foreach ($org_types as $org_type) {
        if ($org_type['target_id'] == 49) $ict_provider = true;
      }
      if (!$ict_provider) {
	    print '<p>';
		print '<strong>' . t('Error:') . ' </strong>';
        print (t('In your profile "My organisation" must be an organisation of type "ICT provider". '));
		$my_org_uid = $my_org -> uid;
		if ($my_org_uid == $uid) {
          print l(t('Edit my organisation'), 'node/' . $my_org_nid .'/edit/', array('query' => array('destination' => 'provider/start')));
		}
		else {
          print l(t('Contact the creator of this organisation'), 'user-profile/' . $my_org_uid);
		}
	    print '<p>';
      }
// User checks are OK
      else $user_checks_ok = true;
*/
      $user_checks_ok = true;
	}
	else {
	  print t('You must assign "My organisation" in your profile. ');
      print l(t('Edit my profile'), 'profile-main/' . $uid .'/edit/', array('query' => array('destination' => 'provider/start')));
	}
  }
// User has no profile
  else {
// Has the user created an organisation?
    $user_created_organisation = false;
    $query = db_select('node', 'n');
    $query
      ->fields('n', array('nid','title'))
      ->condition('n.uid', $uid)
      ->condition('n.type', 'organisation');
    $result = $query->execute()->fetchAll();
    if (!empty($result)) {
      $user_created_organisation = true;
      print '<p><strong>' . t('Company/organisation information') . '</strong><br>'; 
	  print t('You have entered the following organisation(s) to the database:') . '<ul>';
      foreach($result as $row) {
	    print '<li><strong>' . $row -> title;
	    print '&nbsp;&nbsp;';
	    print l(t('Confirm'), 'provider/start/confirm/' . $row -> nid);
	    print '</strong></li>';
	  }
	  print '</ul></p>';
	  print '<p>';
	  print t('Please confirm the organisation you want to represent in the survey or ');
      print '<br><strong>';
      print l(t('create new company/organisation or department'), 'node/add/organisation/', array('query' => array('destination' => 'provider/start')));
      print '</strong>';
      print '</p>';
    }

// Is the user's email address in an organisation created by an ICT-AGRI partner?
    $foreign_created_organisation = false;

// No profile and no user or foreign created organisation: User create organisation and profile is then generated  
    if (!$has_profile && !$user_created_organisation && !$foreign_created_organisation) {
      print '<p>';
	  print '<strong>' . t('Company/organisation information') . '</strong><br>'; 
	  print t('You need to put the organisation you want to represent in the survey into the database.');
	  print '<br><strong>' . t('Please choose "ICT provider" as the organisation type.') . '</strong><br>';
	  print t('If your are from a department of a larger organisation, please enter the top level of the organisation in the database first. Later on, you can enter the department of your main organisation in the database. Only the department needs to be of the organisation type "ICT provider".'); 
      print '</p>';
      print '<p>';
      print '<strong>';
      print l(t('Create company/organisation'), 'node/add/organisation/', array('query' => array('destination' => 'provider/start')));
      print '</strong>';
      print '</p>';
	}
  }
}

// Survey checks
if ($user_checks_ok && !$survey_checks_ok) {
// Is this ICT provider already in the survey?
// Get provider-organisation node id
  $query = db_select('field_data_field_provider_parent', 'pp');
  $query
  ->fields('pp', array('entity_id'))
  ->condition('pp.field_provider_parent_target_id', $my_org_nid);
  $result = $query->execute()->fetchAll();
  if (!empty($result)) $po_id = $result[0] -> entity_id;
  else $po_id = null;
  if ($po_id) {
// Is there already started a survey response for user's my organisation?
    $response_types = get_survey_response_types($po_id);
	if ($response_types) {
	  foreach($response_types as $response) {
		$response_entity_id = $response -> entity_id;
        }			
// Get user id on existing response
      $query = db_select('eck_provider', 'ep');
      $query
        ->fields('ep', array('uid'))
        ->condition('ep.id', $response_entity_id);
      $result = $query->execute()->fetchAll();
      if ($result) {
	    $response_uid = $result[0] -> uid;
// Is this different from the current user?
        if ($response_uid != $uid) {
          $user_data = user_load($response_uid);
          $first_name = $user_data->field_first_name['und'][0]['value'];
          $last_name = $user_data->field_last_name['und'][0]['value'];
		  $responder = $first_name . ' ' . $last_name;
    	  print '<p><strong>' . t('Error: ') . '  </strong> ';
          print $my_org_name . ' ' . t(' has already responded to the survey by ') . $responder . '</p>';
	    }
// All checks OK, user will be lead to his own survey
		else $survey_checks_ok = true;
	  }
// The user on an existing survey could not be found, send message to site administrator
	  else {
        print '<p>';
    	print '<strong>' . t('Error:') . ' </strong>';
	    print t('Please copy the following text and send it in a mail to the site administrator: ');
        print '</p>';
		print '<p><em>' . t('No user could be found for survey response from ') . $po_id . '</em></p>';
        print '<p>';
		print t('We apologize for this inconvenience');
        print '</p>';
	  }
    }
// Provider-organisation node is created but not response to the survey. 
// We make sure that the provider-organisation node author is the current user and user him proceed
	else {  
	  db_update('node') 
        -> fields(array('uid' => $uid, ))
        -> condition('nid', $po_id, '=')
        -> execute();
    $survey_checks_ok = true;
	}
  }
// Provider-organisation node is not created 
// We make create provider-organisation node and user him proceed
  else {
    $po_id = mkb_providers_create_provider_organisation_node($my_org_nid);
    $survey_checks_ok = true;
  }
}

// Provide link til survey
if ($user_checks_ok && $survey_checks_ok) {
  print '<h2>' . t('To the survey') . '</h2>';
  print '<p>' . t('Congratulations, you are now ready to continue with the survey. Click the following link to move to the ') . '&nbsp;';
  print '<strong>';
  print l(t('survey questionnaire'), 'provider/overview/' . $po_id);
  print '</strong>';
  print '</p>';
  print '</p></br><h2>';
  print '<p>' . t('Remarks') . '</h2></p>';
  print '<p>' . t('You can always edit your profile in Home => My profile.') . '</p>';
  print '<p>' . t('The data about your company can be edited in Community => My organisations.') . '</p>';
}
/* 
print '<h3>Missing text strings</h3>';
print t('Contact the creator of this organisation');
        print '<p>';
	  print t('You must assign "My organisation" in your profile. ');        print (t('In your profile "My organisation" must be an organisation of type "ICT provider". '));
        print '<p>';
	  print t('You must assign "My organisation" in your profile. ');
        print '<p>';
      print t('Edit my profile');
      print '<p>' . t('Company/organisation information') . '<br>'; 
        print '<p>';
	  print t('Company/organisation information'); 
        print '<p>';
          print t(' has already responded to the survey by ');
        print '<p>';
	    print t('Please copy the following text and send it in a mail to the site administrator: ');
        print '</p>';
		print t('No user could be found for survey response from ');
        print '<p>';
		print t('We apologize for this inconvenience');

 */