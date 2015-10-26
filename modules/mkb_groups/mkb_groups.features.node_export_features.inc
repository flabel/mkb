<?php
/**
 * @file
 * mkb_groups.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function mkb_groups_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'155\',
      \'uid\' => \'2\',
      \'title\' => \'How to manage your group\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'eded40ba-ad13-4d50-836a-438af80e32c2\',
      \'nid\' => \'155\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1375430707\',
      \'changed\' => \'1375693376\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'5ca69e93-e378-4939-ada2-64a6b40d7305\',
      \'revision_timestamp\' => \'1375693376\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p><strong>Confidentiality</strong></p><p>The contents created within the group and files uploaded to the group are protected against access by users not being members of the group. This is secured by Drupal\'s permission system.&nbsp;</p><p><strong>Group management</strong></p><p>The group is managed from the main Group Page through the Edit group link in the menu. Only members with the administrator role can edit the group (the administrator roles may be assigned to several members). Other members can view the Group Page. If the group is public, non-member users can also view the description in Group Page. In the&nbsp;Group Page, administrators can:</p><ul><li>Edit the description of the group</li><li>Change Public/Private setting</li><li>Upload files</li><li>Add group members (via the User Name of that user, which is provided in the Search users view)</li><li>Manage group members (remove members, change member status and assign roles)</li></ul><p><strong>Search and invite users to the group</strong></p><p>The Search users link in the menu provides a searchable view of all users in the database. To see the<span style=\\"line-height: 1.5em;\\">&nbsp;</span><span style=\\"line-height: 1.5em;\\">details of a user</span><span style=\\"line-height: 1.5em;\\">, click on the user\'s real name. You can use the contact link provided here to invite the user through an email.</span></p><p><strong>Requests for membership (public groups)</strong></p><p>Users can see public groups and request for membership. These requests will appear in the Group Page -&gt; Group -&gt; People section, where an administrator can admit or reject the request. Information about the requesting user can be found by a look up in the Search users view.</p><p>&nbsp;</p>",
            \'summary\' => \'\',
            \'format\' => \'filtered_html\',
            \'safe_value\' => "<p><strong>Confidentiality</strong></p>\\n<p>The contents created within the group and files uploaded to the group are protected against access by users not being members of the group. This is secured by Drupal\'s permission system. </p>\\n<p><strong>Group management</strong></p>\\n<p>The group is managed from the main Group Page through the Edit group link in the menu. Only members with the administrator role can edit the group (the administrator roles may be assigned to several members). Other members can view the Group Page. If the group is public, non-member users can also view the description in Group Page. In the Group Page, administrators can:</p>\\n<ul><li>Edit the description of the group</li>\\n<li>Change Public/Private setting</li>\\n<li>Upload files</li>\\n<li>Add group members (via the User Name of that user, which is provided in the Search users view)</li>\\n<li>Manage group members (remove members, change member status and assign roles)</li>\\n</ul><p><strong>Search and invite users to the group</strong></p>\\n<p>The Search users link in the menu provides a searchable view of all users in the database. To see the<span style=\\"line-height: 1.5em;\\"> </span><span style=\\"line-height: 1.5em;\\">details of a user</span><span style=\\"line-height: 1.5em;\\">, click on the user\'s real name. You can use the contact link provided here to invite the user through an email.</span></p>\\n<p><strong>Requests for membership (public groups)</strong></p>\\n<p>Users can see public groups and request for membership. These requests will appear in the Group Page -&gt; Group -&gt; People section, where an administrator can admit or reject the request. Information about the requesting user can be found by a look up in the Search users view.</p>\\n<p> </p>\\n",
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
      \'last_comment_timestamp\' => \'1375430707\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'2\',
      \'comment_count\' => \'0\',
      \'name\' => \'iver\',
      \'picture\' => \'0\',
      \'data\' => \'a:2:{s:7:"overlay";i:1;s:7:"contact";i:1;}\',
      \'path\' => array(
        \'pid\' => \'1\',
        \'source\' => \'node/155\',
        \'alias\' => \'mkb-group-help\',
        \'language\' => \'und\',
      ),
      \'menu\' => NULL,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'119\',
      \'uid\' => \'2\',
      \'title\' => \'Partnering with User Groups\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'152ef9a3-23af-4507-89c6-45de1ff22423\',
      \'nid\' => \'119\',
      \'type\' => \'page\',
      \'language\' => \'und\',
      \'created\' => \'1371476358\',
      \'changed\' => \'1384783046\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'957d008c-8f14-4707-bd7f-07ca4df36ee7\',
      \'revision_timestamp\' => \'1384783046\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p>A User Group&nbsp;is a&nbsp;closed room where users can communicate in confidence. The primary purpose of User Groups is to provide a facility for partnering in relation to ERA-NET calls, but&nbsp;User Groups may also be used for any other purpose users may have.&nbsp;</p><p>The user who creates a User Group is automatically the Group Coordinator, who has the sole rights to make changes in the group, including adding/deleting group memberships and giving administration rights to&nbsp;other members.</p><p>User Groups can be of two types related to visibility:</p><ul><li>Public:&nbsp;Other users can see the group, read a summary description and apply for membership</li><li>Private: The group is invisible for other users and memberships is by invitation only</li></ul><p>​Public / Private can be reset during the life of the group. In both groups internal communication and memberships are confidential. Files uploaded to the group are secured against unauthorised access.</p><p>To create a new group, use the link in the menu. A form wil open, where you can&nbsp;enter a title, a description, set the visibility, and optionally upload a file. If you opts for a public file, the title and the description will be displayed to other users.&nbsp;</p>\',
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>A User Group is a closed room where users can communicate in confidence. The primary purpose of User Groups is to provide a facility for partnering in relation to ERA-NET calls, but User Groups may also be used for any other purpose users may have. </p>\\n<p>The user who creates a User Group is automatically the Group Coordinator, who has the sole rights to make changes in the group, including adding/deleting group memberships and giving administration rights to other members.</p>\\n<p>User Groups can be of two types related to visibility:</p>\\n<ul><li>Public: Other users can see the group, read a summary description and apply for membership</li>\\n<li>Private: The group is invisible for other users and memberships is by invitation only</li>\\n</ul><p>​Public / Private can be reset during the life of the group. In both groups internal communication and memberships are confidential. Files uploaded to the group are secured against unauthorised access.</p>\\n<p>To create a new group, use the link in the menu. A form wil open, where you can enter a title, a description, set the visibility, and optionally upload a file. If you opts for a public file, the title and the description will be displayed to other users. </p>\\n",
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
      \'last_comment_timestamp\' => \'1371476358\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'2\',
      \'comment_count\' => \'0\',
      \'name\' => \'iver\',
      \'picture\' => \'0\',
      \'data\' => \'a:2:{s:7:"overlay";i:1;s:7:"contact";i:1;}\',
      \'path\' => array(
        \'pid\' => \'2\',
        \'source\' => \'node/119\',
        \'alias\' => \'about-partnering\',
        \'language\' => \'und\',
      ),
      \'menu\' => array(
        \'link_title\' => \'About\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'menu-partnering\',
        \'weight\' => \'-50\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'0\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'About partnering and user groups\',
        \'enabled\' => 1,
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
