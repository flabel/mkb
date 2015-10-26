<?php
/**
 * @file
 * mkb_application.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function mkb_application_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'207\',
      \'uid\' => \'1\',
      \'title\' => \'How to apply\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'152ef9a3-23af-4507-89c6-45de1ff22423\',
      \'nid\' => \'207\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1407920733\',
      \'changed\' => \'1407921388\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'642e6311-1725-47b5-97c3-465dea98c871\',
      \'revision_timestamp\' => \'1407921388\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Applications are made within a group. <em>Edit group</em> and choose the open call in <em>Call identifier</em>. After saving you wil get two new links in the menu. Use <em>Edit application</em> to write the application.</p>\\r\\n\\r\\n<p>The group administrator is automatically the project coordinator. Project partners are added by assigning this role to group members in<em> Edit group =&gt; Group =&gt; Add people</em> or <em>Edit group =&gt; Group =&gt; People</em>. A special role is the <em>Project editor</em>, who can be a Project partner or an ordinary Group member, and who has rights to act as the coordinator regarding editing the application.</p>\\r\\n\\r\\n<p>Only one person may have the project coordinator&nbsp;role and this person may not have the project partner role.</p>\\r\\n\\r\\n<p>The Project coordinator must create a <em>Project info page</em> and he/she and all Project partners must create a <em>Partner info page</em> and a <em>Partner budget.</em> The budget form to be filled in is modified according to the conditions of the appropriate Funding agency and has a link to the contact person.</p>\\r\\n\\r\\n<p>The steps in making an application is illustrated below.</p>\\r\\n\\r\\n<p><img alt=\\"\\" src=\\"/sites/all/modules/mkb_application/img/application_workflow.png\\" /></p>\\r\\n\\r\\n<p>&nbsp;</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>Applications are made within a group. <em>Edit group</em> and choose the open call in <em>Call identifier</em>. After saving you wil get two new links in the menu. Use <em>Edit application</em> to write the application.</p>\\n<p>The group administrator is automatically the project coordinator. Project partners are added by assigning this role to group members in<em> Edit group =&gt; Group =&gt; Add people</em> or <em>Edit group =&gt; Group =&gt; People</em>. A special role is the <em>Project editor</em>, who can be a Project partner or an ordinary Group member, and who has rights to act as the coordinator regarding editing the application.</p>\\n<p>Only one person may have the project coordinator role and this person may not have the project partner role.</p>\\n<p>The Project coordinator must create a <em>Project info page</em> and he/she and all Project partners must create a <em>Partner info page</em> and a <em>Partner budget.</em> The budget form to be filled in is modified according to the conditions of the appropriate Funding agency and has a link to the contact person.</p>\\n<p>The steps in making an application is illustrated below.</p>\\n<p><img alt=\\"\\" src=\\"/sites/all/modules/mkb_application/img/application_workflow.png\\" /></p>\\n<p> </p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'cid\' => \'0\',
      \'last_comment_timestamp\' => \'1407920733\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'flabel\',
      \'picture\' => \'0\',
      \'data\' => \'a:1:{s:7:"contact";i:0;}\',
      \'path\' => FALSE,
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
