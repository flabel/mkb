<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_summary_page template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Evaluation filter nid.
 * @return template
 *   The template application_partners_template is called with $content.
 */
function mkb_eval_application_partners($cid, $fid){
  $variables = array();
  $header = array(
      array('data'=>'ID', 'width'=>'5%'),
      array('data'=>'Application', 'width'=>'15%'),
      array('data'=>'Partner contact', 'width'=>'20%'),
      array('data'=>'Partner organisation', 'width'=>'60%'),
      );
  $rows = array();

  // Get all topics
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'call_topic')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_topic_level', 'value', 1, '=')
    ->fieldOrderBy('field_topic_weight', 'value', 'ASC');

  $result = $query->execute();

  $topics = array();
  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);
    $nodes = node_load_multiple($nids);

    foreach ($nodes as $node) {
      $topics[$node->nid] = $node;
      $rows[$node->nid] = array();
    }
  }

  // Get groups selected for stage 2
  $groups = mkb_eval_get_filtered_groups($cid, $fid);
  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;

    $project_info = node_load($applications['application_project_info']);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);

    // Topic
    $project_info_topic = $project_info_wrapper->field_app_topics[0]->value();

    // Partners
    $partner_info_nids = $applications['application_partner_info'];
    $first_partner = TRUE;
    foreach ($partner_info_nids as $partner_info_nid){
      $partner_info_node = node_load($partner_info_nid);
      // Partner realname
      $partner_user = user_load($partner_info_node->uid);

      // Partner organisation
      $profile2 = profile2_load_by_user($partner_user, 'main');
      $organisation = '';
      if($profile2){
        $profile2_wrapper = entity_metadata_wrapper('profile2', $profile2);
        $organisation_node = $profile2_wrapper->field_my_organisation->value();
        $organisation = $organisation_node->title;
      }

      // First Partner will have the application id and acronym. Rest will be empty
      $id = '';
      $acronym = '';
      if($first_partner){
        $id = $gid;
        $acronym = $project_info_wrapper->field_app_acronym->value();
        $first_partner = FALSE;
      }

      $rows[$project_info_topic->nid][] = array(
          'id' => array('data'=>$id, 'width'=>'5%'),
          'title' => array('data'=>$acronym, 'width'=>'15%'),
          'partner' => array('data'=>$partner_user->realname, 'width'=>'20%'),
          'organisation' => array('data'=>$organisation, 'width'=>'60%'),
          );
    }
  }

  $variables['topics'] = $topics;
  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('application_partners', $variables);
}


