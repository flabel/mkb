<?php
/**
 * @file
 * mkb_call_admin.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function mkb_call_admin_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'9\',
      \'uid\' => \'1\',
      \'title\' => \'Call setup introduction\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'e1f9efd6-92a0-4b1e-ba72-f61ee4c2688f\',
      \'nid\' => \'9\',
      \'type\' => \'project_page\',
      \'language\' => \'und\',
      \'created\' => \'1384630824\',
      \'changed\' => \'1384630824\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'41428dd8-47c4-46b9-bf7a-9051484f2057\',
      \'revision_timestamp\' => \'1384630824\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p>The call submission and administration system can be customized to the requirements of each call and to the requirements of each participating funding agency. This page explains the overall principles in the set up of a call.&nbsp;</p><p>The call setup is started by the <strong>call administrator</strong> defining&nbsp;the mode, topics, time schedule and application fields of the call. This is done by creating and editing a <strong><em>Call-main-page</em></strong>; detailed guidelines are in&nbsp;<a href="call_admin_guide">Call setup guide for call administrator</a> and included in the edit page. The call topics must be created in the Call topics vocabulary as described in the <a href="call_topics_guide">Call topics guide</a>.</p><p>Each participating <strong>funding agency</strong> can then register their participation with funding contribution, conditions, contact persons and budget restricitions. This is done by creating and editing a <em><strong>Call-funder-page</strong></em> and one or more <em><strong>Funding-schemes</strong></em>; detailed guidelines are in&nbsp;<a href="call_funder_guide">Call setup guide for funding agencies</a> and included in the edit pages.</p><p><span style="line-height: 1.538em;">The definitions provided by the call administrator and the funding agencies are used to generate the&nbsp;</span><strong style="line-height: 1.538em;">call description</strong><span style="line-height: 1.538em;"> to be published in the website. Publishing is done by placing a link to the call description page in the </span><strong style="line-height: 1.538em;">call menu</strong><span style="line-height: 1.538em;">.</span></p><p>The definitions are furthermore used to generate the <strong>application forms</strong> used by the applicants and to provide information for applicants in the application edit pages.</p><p>The call administrator must be a user with the <em>call administrator</em>&nbsp;role. The funding agency representatives must be users with the <em>project member</em> role.</p>\',
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>The call submission and administration system can be customized to the requirements of each call and to the requirements of each participating funding agency. This page explains the overall principles in the set up of a call. </p>\\n<p>The call setup is started by the <strong>call administrator</strong> defining the mode, topics, time schedule and application fields of the call. This is done by creating and editing a <strong><em>Call-main-page</em></strong>; detailed guidelines are in <a href=\\"call_admin_guide\\">Call setup guide for call administrator</a> and included in the edit page. The call topics must be created in the Call topics vocabulary as described in the <a href=\\"call_topics_guide\\">Call topics guide</a>.</p>\\n<p>Each participating <strong>funding agency</strong> can then register their participation with funding contribution, conditions, contact persons and budget restricitions. This is done by creating and editing a <em><strong>Call-funder-page</strong></em> and one or more <em><strong>Funding-schemes</strong></em>; detailed guidelines are in <a href=\\"call_funder_guide\\">Call setup guide for funding agencies</a> and included in the edit pages.</p>\\n<p><span style=\\"line-height: 1.538em;\\">The definitions provided by the call administrator and the funding agencies are used to generate the </span><strong style=\\"line-height: 1.538em;\\">call description</strong><span style=\\"line-height: 1.538em;\\"> to be published in the website. Publishing is done by placing a link to the call description page in the </span><strong style=\\"line-height: 1.538em;\\">call menu</strong><span style=\\"line-height: 1.538em;\\">.</span></p>\\n<p>The definitions are furthermore used to generate the <strong>application forms</strong> used by the applicants and to provide information for applicants in the application edit pages.</p>\\n<p>The call administrator must be a user with the <em>call administrator</em> role. The funding agency representatives must be users with the <em>project member</em> role.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_attachments\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'last_comment_timestamp\' => \'1384630824\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'iver\',
      \'picture\' => \'0\',
      \'data\' => \'a:7:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"contact";i:1;s:7:"overlay";i:1;}\',
      \'path\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Call setup\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'menu-call-admin\',
        \'weight\' => \'0\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'1\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'Call setup guides and pages\',
        \'enabled\' => 1,
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'10\',
      \'uid\' => \'1\',
      \'title\' => \'Call themes and topics guide\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'ede4edd4-d0cd-4490-8ac9-eb06a3f5a782\',
      \'nid\' => \'10\',
      \'type\' => \'project_page\',
      \'language\' => \'und\',
      \'created\' => \'1384630824\',
      \'changed\' => \'1384630824\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'666a4916-e741-47ad-a783-74a235be9a9b\',
      \'revision_timestamp\' => \'1384630824\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<p>The call themes and topics are created and edited via a link in the <em>Call setup overview. </em></p><p>You can add an unlimited number of themes and an unlimited number of topics within each theme.</p><p><span style="line-height: 1.538em;">Themes and topics may include a description, which is displayed in a pop-up fashion in the call description.</span></p><p><span style="line-height: 1.538em;">If <em>Theme funding</em> is enabled in the <em>Call main page</em>, applicants are only allowed to select one theme and multiple topics within this theme.&nbsp;</span></p><p><span style="line-height: 1.538em;">Otherwise multiple selections of themes and topics is allowed.</span></p><p>&nbsp;</p>\',
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>The call themes and topics are created and edited via a link in the <em>Call setup overview. </em></p>\\n<p>You can add an unlimited number of themes and an unlimited number of topics within each theme.</p>\\n<p><span style=\\"line-height: 1.538em;\\">Themes and topics may include a description, which is displayed in a pop-up fashion in the call description.</span></p>\\n<p><span style=\\"line-height: 1.538em;\\">If <em>Theme funding</em> is enabled in the <em>Call main page</em>, applicants are only allowed to select one theme and multiple topics within this theme. </span></p>\\n<p><span style=\\"line-height: 1.538em;\\">Otherwise multiple selections of themes and topics is allowed.</span></p>\\n<p> </p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_attachments\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'last_comment_timestamp\' => \'1384630824\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'iver\',
      \'picture\' => \'0\',
      \'data\' => \'a:7:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"contact";i:1;s:7:"overlay";i:1;}\',
      \'path\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Call topics guide\',
        \'mlid\' => 0,
        \'plid\' => \'665\',
        \'menu_name\' => \'menu-call-admin\',
        \'weight\' => \'-46\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'0\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'Add call-main-page\',
        \'enabled\' => 1,
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'11\',
      \'uid\' => \'1\',
      \'title\' => \'Call setup guide for funding agencies\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'45ee8bc4-9e25-4b76-ba60-461601e418c7\',
      \'nid\' => \'11\',
      \'type\' => \'project_page\',
      \'language\' => \'und\',
      \'created\' => \'1384630824\',
      \'changed\' => \'1384630824\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'7f3667b5-58bc-406b-8746-09552f438c6d\',
      \'revision_timestamp\' => \'1384630824\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => \'<h2>1 Introduction</h2><p>This page describes how funding agencies can register their participation in a call and provide details concerning their funding contribution, funding conditions, contact persons, call management persons and budget restrictions.&nbsp;</p><p>The registration to the call is done by two types of pages as described below. These pages must be created and edited by a website user representing&nbsp;the funding agency. The call administrator has rights to modify the pages after the have been created.</p><p>The funding agency must be created as an organisation before the pages described here can be created.&nbsp;</p><h2>2 Definition and description of the participation in the call</h2><p>By this page the funding agency is connected to the call with contibuted funding and conditions.</p><p>Create and edit a <em>Call-funder-page </em>(*&nbsp;required fields):</p><ul><li><strong>Title*:</strong> Enter the name or acronym of the funding agency&nbsp;</li><li><strong>Call indentifier*:</strong> Select the&nbsp;appropriate call from the drop down list</li><li><strong>Funding agency*:&nbsp;</strong>Select your agency from the drop down list</li><li><strong>Country specific*:</strong> Check &quot;Yes&quot; if the funding scheme is only for applicants from your country (the default); otherwise check &quot;No&quot;&nbsp;</li><li><strong>Funding*:</strong> Enter your funding contribution (EUR).</li><li><strong>Conditions short:</strong> Enter main conditions intended for the funding overview table in the call text</li><li><strong>Conditions full*:</strong> Enter all conditions intended as information to the applicants</li><li><strong>Contact persons*:</strong> Select contact persons for applicants in the check box (from your organisation, available after first save)</li><li><strong>Call managers*:</strong> Select persons to have access to manage the applications for you agency in the check box (from your organisation, available after first save)</li><li><strong>Evaluators:</strong> Enter user names of persons you give access to read and evaluate applications (use the User profile page to find user names; this is typically done after submission has closed)</li></ul><h2>3 Definition and description of funding schemes</h2><p>By on or more <em>Funding-scheme</em> pages it is defined and described how different types of applicants can apply for funding. The budget form presented to applicants is modified accordingly.</p><p>Create and edit a&nbsp;<em>Funding-scheme</em>&nbsp;page (* required fields):</p><ul><li><strong>Title*:</strong>&nbsp;Provide a title which makes it easy for applicants to recognize the type of organisation this&nbsp;is meant for (e.g., Public Research Organisations, SMEs, etc.)&nbsp;</li><li><strong>Call indentifier*:</strong>&nbsp;Select the appropriate call from the drop down list</li><li><strong>Funding agency*:&nbsp;</strong>Select your agency from the drop down list (by the title in the <em>Call_funder_page</em>)</li><li><strong>Scheme conditions*</strong>: Provide the conditions specific to this scheme (are presented to the&nbsp;applicant with the budget form)</li><li><strong>Budget categories*</strong>: Check the budget categories which can be funded by this scheme (overrides all checks for cost items)</li><li><strong>Cost items*</strong>: Check the cost items within each budget category which can be funded by this scheme</li><li><strong>Requested max*:</strong>&nbsp;The maximum funding as a percentage of total funding, ranging from 1 to 100.</li></ul>\',
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h2>1 Introduction</h2>\\n<p>This page describes how funding agencies can register their participation in a call and provide details concerning their funding contribution, funding conditions, contact persons, call management persons and budget restrictions. </p>\\n<p>The registration to the call is done by two types of pages as described below. These pages must be created and edited by a website user representing the funding agency. The call administrator has rights to modify the pages after the have been created.</p>\\n<p>The funding agency must be created as an organisation before the pages described here can be created. </p>\\n<h2>2 Definition and description of the participation in the call</h2>\\n<p>By this page the funding agency is connected to the call with contibuted funding and conditions.</p>\\n<p>Create and edit a <em>Call-funder-page </em>(* required fields):</p>\\n<ul><li><strong>Title*:</strong> Enter the name or acronym of the funding agency </li>\\n<li><strong>Call indentifier*:</strong> Select the appropriate call from the drop down list</li>\\n<li><strong>Funding agency*: </strong>Select your agency from the drop down list</li>\\n<li><strong>Country specific*:</strong> Check \\"Yes\\" if the funding scheme is only for applicants from your country (the default); otherwise check \\"No\\" </li>\\n<li><strong>Funding*:</strong> Enter your funding contribution (EUR).</li>\\n<li><strong>Conditions short:</strong> Enter main conditions intended for the funding overview table in the call text</li>\\n<li><strong>Conditions full*:</strong> Enter all conditions intended as information to the applicants</li>\\n<li><strong>Contact persons*:</strong> Select contact persons for applicants in the check box (from your organisation, available after first save)</li>\\n<li><strong>Call managers*:</strong> Select persons to have access to manage the applications for you agency in the check box (from your organisation, available after first save)</li>\\n<li><strong>Evaluators:</strong> Enter user names of persons you give access to read and evaluate applications (use the User profile page to find user names; this is typically done after submission has closed)</li>\\n</ul><h2>3 Definition and description of funding schemes</h2>\\n<p>By on or more <em>Funding-scheme</em> pages it is defined and described how different types of applicants can apply for funding. The budget form presented to applicants is modified accordingly.</p>\\n<p>Create and edit a <em>Funding-scheme</em> page (* required fields):</p>\\n<ul><li><strong>Title*:</strong> Provide a title which makes it easy for applicants to recognize the type of organisation this is meant for (e.g., Public Research Organisations, SMEs, etc.) </li>\\n<li><strong>Call indentifier*:</strong> Select the appropriate call from the drop down list</li>\\n<li><strong>Funding agency*: </strong>Select your agency from the drop down list (by the title in the <em>Call_funder_page</em>)</li>\\n<li><strong>Scheme conditions*</strong>: Provide the conditions specific to this scheme (are presented to the applicant with the budget form)</li>\\n<li><strong>Budget categories*</strong>: Check the budget categories which can be funded by this scheme (overrides all checks for cost items)</li>\\n<li><strong>Cost items*</strong>: Check the cost items within each budget category which can be funded by this scheme</li>\\n<li><strong>Requested max*:</strong> The maximum funding as a percentage of total funding, ranging from 1 to 100.</li>\\n</ul>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_attachments\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'last_comment_timestamp\' => \'1384630824\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'iver\',
      \'picture\' => \'0\',
      \'data\' => \'a:7:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"contact";i:1;s:7:"overlay";i:1;}\',
      \'path\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Funding agency guide\',
        \'mlid\' => 0,
        \'plid\' => \'665\',
        \'menu_name\' => \'menu-call-admin\',
        \'weight\' => \'-44\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'0\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'Guide for funding agencies\',
        \'enabled\' => 1,
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'12\',
      \'uid\' => \'1\',
      \'title\' => \'Call setup guide for call administrator\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'42de45ca-c19f-4f18-8916-f2faed4dc2b2\',
      \'nid\' => \'12\',
      \'type\' => \'project_page\',
      \'language\' => \'und\',
      \'created\' => \'1384630824\',
      \'changed\' => \'1384630824\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'a72ed8a4-edcb-47a8-b9a1-42e7b36e0ed4\',
      \'revision_timestamp\' => \'1384630824\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<h2><strong>1 Introduction</strong></h2><p>This guide is intended for setting up a call on a MKB ERA-NET website.</p><h2><strong>2 Definition and description of the call</strong></h2><p>Create a new page of the type <em>call-main-page</em> and fill in the fields as follows:</p><ul><li><strong>Title:</strong> Fill in the title of the new call</li></ul><p><strong>CALL DEFINITIONS</strong></p><ul><li><strong>Body:</strong> Fill in a description of a new call. You may provide a full description or a short description intended for the web and provide the full call description in a pdf. You may consider to edit the summary connected to the body field, if you are not satisfied with the automatically generated summary in teasers.</li><li><span style=\\"background-color: #ffffff;\\"><strong>Call open creating application:</strong> </span>Check this field when the call is open for creating new applications. Uncheck the field when the call is closed creating new applications.<br />ERA-NET partners with the \'project partner\' role can test the submission system even when the call is closed.</li><li><strong>Call open for edit</strong>: Check this field when the call is open for editing existing applications. Uncheck the field when the call is closed for editing existing applications. <br />ERA-NET partners with the \'project partner\' role can test the submission system even when the call is closed.</li><li><strong>Number of stages:</strong> Select \\"1\\" or \\"2\\". A two stage call has a selection of applications between the two stages.</li><li><span style=\\"background-color: #ffffff;\\"><strong>Current stage:</strong> Select the current stage of a 2 stage call. When stage 2 is selected only applications approved for the second stage will be open for submission. </span><br />In a one stage call select stage 1.</li><li><strong>Funding mode:</strong> Select \\"Virtual Common pot\\", \\"Real Common pot\\", \\"Non competetive\\" or \\"Mixed mode\\"</li><li><strong>Topics:</strong> Select taxanomy. You will need to first create a taxanomy with the topics, possibly with sub-topics</li><li><strong>Theme funding:</strong> Select \\" No, funding agencies may only allocate a total funding\\" or \\" Yes, funding agencies may allocate funding per theme\\"</li><li><strong>Call documents</strong>: Upload call documents for download by applicants</li></ul><p><strong>TIME SCHEDULE</strong></p><p>Define the important dates and times for the call. Only filled in dates are displayed. <br />Dates are <strong>only</strong> only used as information for applicants, they are <strong>not</strong> used to open or close submission.</p><ul><li><strong>Date launch:</strong> Select date from pop-up calendar</li><li><strong>Date pre-registration close:</strong> Select date and time from pop-ups (if appropriate)</li><li><strong>Date pre-proposals open:</strong> Select date and time from pop-ups (if 2 stage call)</li><li><strong>Date pre-proposals close:</strong> Select date and time from pop-ups (if 2 stage call)</li><li><strong>Date pre-proposals notification:</strong> Select date from pop-ups (if 2 stage call)</li><li><strong>Date full proposals open:</strong> Select date and time from pop-ups</li><li><strong>Date full proposals close:</strong> Select date and time from pop-ups</li><li><strong>Date full proposals notification:</strong> Select date from pop-ups</li></ul><h2><strong>3 Online application form </strong></h2><p>The application form consists of four parts: A Project information, B Partner information, C Partner budget, and D Description of work (pdf upload).</p><p><strong>3A Project information (filled in by the proposal coordinator)</strong></p><p>The project information form is defined by the <em>content type application-project-info</em>, which has pre-defined fields typically used in applications. These fields can be deactivated below. In addition there are five additional fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-project-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.</p><p>In the edit page you will find check boxes for enabling/disabling the following fields (default setting):</p><ul><li>Title (required)</li><li>Acronym (required)</li><li>Duration (enabled)</li><li>Topics (enabled). The call administrator must define the topics for this call in the taxonomy Call topics. This must be done as a parent term named as the id of this page (see the url when this page is saved) and all topics for the call as children terms.</li><li>Keywords (enabled): Applicants can provide up to five keywords</li><li>Summary (enabled) Expected impact (enabled)</li><li>Expected European added value (enabled)</li><li>Supplementory information (enabled)</li><li>Additional field 1 (disabled)</li><li>Additional field 2 (disabled)</li><li>Additional field 3 (disabled)</li><li>Additional field 4 (disabled)</li><li>Additional field 5 (disabled)</li></ul><h3><strong>3B Partner information (filled in by each partner) </strong></h3><p>Information about the partners\' contact person and organisation is automatically included from the information provided int he user\'s profile. The project information form is defined by the <em>content type application-partner-info</em>, which has pre-defined fields typically used in applications. These fields can be deactivated below. In addition there are five additional fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-partner-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.</p><p>In the edit page you will find check boxes for enabling/disabling the following fields (default setting):</p><ul><li>Title (required)</li><li>Role (enabled)</li><li>Publications (enabled)</li><li>Business plan (enabled)</li><li>Additional field 1 (disabled)</li><li>Additional field 2 (disabled)</li><li>Additional field 3 (disabled)</li><li>Additional field 4 (disabled)</li><li>Additional field 5 (disabled)</li><li>Acronym (required)</li></ul><h3><strong>3C Partner budget (filled in by each partner)</strong></h3><p>The budget can include 1, 2 or 3 project types (e.g., RTD (Research and Technological Dvelopment). Demonstration, and Innovation). The number and definition of type are defined in the main call page. In addition a short description of each project type can be added; these description are presented to applicants in the budget form.</p><p>A further option is whether project partners with in kind budgets are allowed. If so, the call administrator must create a call-funder page and a funding-scheme page in oder to facilitate in kind funding in the call.</p><p>The budget has pre-defined cost items. The funding agencies can disable cost items they cannot fund in their&nbsp; funding-scheme pages.</p><h3><strong>3D Description of work (uploaded by coordinator) </strong></h3><p>DOW upload. A template can be made available in the call documents.</p><h2>4 Call office</h2><p>The contact persons in the Call Office can be selected among website users. Contact forms will be available for applicants.</p>",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<h2><strong>1 Introduction</strong></h2>\\n<p>This guide is intended for setting up a call on a MKB ERA-NET website.</p>\\n<h2><strong>2 Definition and description of the call</strong></h2>\\n<p>Create a new page of the type <em>call-main-page</em> and fill in the fields as follows:</p>\\n<ul><li><strong>Title:</strong> Fill in the title of the new call</li>\\n</ul><p><strong>CALL DEFINITIONS</strong></p>\\n<ul><li><strong>Body:</strong> Fill in a description of a new call. You may provide a full description or a short description intended for the web and provide the full call description in a pdf. You may consider to edit the summary connected to the body field, if you are not satisfied with the automatically generated summary in teasers.</li>\\n<li><span style=\\"background-color: #ffffff;\\"><strong>Call open creating application:</strong> </span>Check this field when the call is open for creating new applications. Uncheck the field when the call is closed creating new applications.<br />ERA-NET partners with the \'project partner\' role can test the submission system even when the call is closed.</li>\\n<li><strong>Call open for edit</strong>: Check this field when the call is open for editing existing applications. Uncheck the field when the call is closed for editing existing applications. <br />ERA-NET partners with the \'project partner\' role can test the submission system even when the call is closed.</li>\\n<li><strong>Number of stages:</strong> Select \\"1\\" or \\"2\\". A two stage call has a selection of applications between the two stages.</li>\\n<li><span style=\\"background-color: #ffffff;\\"><strong>Current stage:</strong> Select the current stage of a 2 stage call. When stage 2 is selected only applications approved for the second stage will be open for submission. </span><br />In a one stage call select stage 1.</li>\\n<li><strong>Funding mode:</strong> Select \\"Virtual Common pot\\", \\"Real Common pot\\", \\"Non competetive\\" or \\"Mixed mode\\"</li>\\n<li><strong>Topics:</strong> Select taxanomy. You will need to first create a taxanomy with the topics, possibly with sub-topics</li>\\n<li><strong>Theme funding:</strong> Select \\" No, funding agencies may only allocate a total funding\\" or \\" Yes, funding agencies may allocate funding per theme\\"</li>\\n<li><strong>Call documents</strong>: Upload call documents for download by applicants</li>\\n</ul><p><strong>TIME SCHEDULE</strong></p>\\n<p>Define the important dates and times for the call. Only filled in dates are displayed. <br />Dates are <strong>only</strong> only used as information for applicants, they are <strong>not</strong> used to open or close submission.</p>\\n<ul><li><strong>Date launch:</strong> Select date from pop-up calendar</li>\\n<li><strong>Date pre-registration close:</strong> Select date and time from pop-ups (if appropriate)</li>\\n<li><strong>Date pre-proposals open:</strong> Select date and time from pop-ups (if 2 stage call)</li>\\n<li><strong>Date pre-proposals close:</strong> Select date and time from pop-ups (if 2 stage call)</li>\\n<li><strong>Date pre-proposals notification:</strong> Select date from pop-ups (if 2 stage call)</li>\\n<li><strong>Date full proposals open:</strong> Select date and time from pop-ups</li>\\n<li><strong>Date full proposals close:</strong> Select date and time from pop-ups</li>\\n<li><strong>Date full proposals notification:</strong> Select date from pop-ups</li>\\n</ul><h2><strong>3 Online application form </strong></h2>\\n<p>The application form consists of four parts: A Project information, B Partner information, C Partner budget, and D Description of work (pdf upload).</p>\\n<p><strong>3A Project information (filled in by the proposal coordinator)</strong></p>\\n<p>The project information form is defined by the <em>content type application-project-info</em>, which has pre-defined fields typically used in applications. These fields can be deactivated below. In addition there are five additional fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-project-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.</p>\\n<p>In the edit page you will find check boxes for enabling/disabling the following fields (default setting):</p>\\n<ul><li>Title (required)</li>\\n<li>Acronym (required)</li>\\n<li>Duration (enabled)</li>\\n<li>Topics (enabled). The call administrator must define the topics for this call in the taxonomy Call topics. This must be done as a parent term named as the id of this page (see the url when this page is saved) and all topics for the call as children terms.</li>\\n<li>Keywords (enabled): Applicants can provide up to five keywords</li>\\n<li>Summary (enabled) Expected impact (enabled)</li>\\n<li>Expected European added value (enabled)</li>\\n<li>Supplementory information (enabled)</li>\\n<li>Additional field 1 (disabled)</li>\\n<li>Additional field 2 (disabled)</li>\\n<li>Additional field 3 (disabled)</li>\\n<li>Additional field 4 (disabled)</li>\\n<li>Additional field 5 (disabled)</li>\\n</ul><h3><strong>3B Partner information (filled in by each partner) </strong></h3>\\n<p>Information about the partners\' contact person and organisation is automatically included from the information provided int he user\'s profile. The project information form is defined by the <em>content type application-partner-info</em>, which has pre-defined fields typically used in applications. These fields can be deactivated below. In addition there are five additional fields, which can be activated below. If additional fields are activated it is necessary to modify the content type with regard to the label of the activated fields. It is safe to modify the application-partner-info content type, as long as machine-name are not altered and fields are not deleted. Please note that changes to to content type will apply to all calls defined in this website.</p>\\n<p>In the edit page you will find check boxes for enabling/disabling the following fields (default setting):</p>\\n<ul><li>Title (required)</li>\\n<li>Role (enabled)</li>\\n<li>Publications (enabled)</li>\\n<li>Business plan (enabled)</li>\\n<li>Additional field 1 (disabled)</li>\\n<li>Additional field 2 (disabled)</li>\\n<li>Additional field 3 (disabled)</li>\\n<li>Additional field 4 (disabled)</li>\\n<li>Additional field 5 (disabled)</li>\\n<li>Acronym (required)</li>\\n</ul><h3><strong>3C Partner budget (filled in by each partner)</strong></h3>\\n<p>The budget can include 1, 2 or 3 project types (e.g., RTD (Research and Technological Dvelopment). Demonstration, and Innovation). The number and definition of type are defined in the main call page. In addition a short description of each project type can be added; these description are presented to applicants in the budget form.</p>\\n<p>A further option is whether project partners with in kind budgets are allowed. If so, the call administrator must create a call-funder page and a funding-scheme page in oder to facilitate in kind funding in the call.</p>\\n<p>The budget has pre-defined cost items. The funding agencies can disable cost items they cannot fund in their  funding-scheme pages.</p>\\n<h3><strong>3D Description of work (uploaded by coordinator) </strong></h3>\\n<p>DOW upload. A template can be made available in the call documents.</p>\\n<h2>4 Call office</h2>\\n<p>The contact persons in the Call Office can be selected among website users. Contact forms will be available for applicants.</p>\\n",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_attachments\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
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
      \'last_comment_timestamp\' => \'1384630824\',
      \'last_comment_name\' => NULL,
      \'last_comment_uid\' => \'1\',
      \'comment_count\' => \'0\',
      \'name\' => \'iver\',
      \'picture\' => \'0\',
      \'data\' => \'a:7:{s:16:"ckeditor_default";s:1:"t";s:20:"ckeditor_show_toggle";s:1:"t";s:14:"ckeditor_width";s:4:"100%";s:13:"ckeditor_lang";s:2:"en";s:18:"ckeditor_auto_lang";s:1:"t";s:7:"contact";i:1;s:7:"overlay";i:1;}\',
      \'path\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Call administrator guide\',
        \'mlid\' => 0,
        \'plid\' => \'665\',
        \'menu_name\' => \'menu-call-admin\',
        \'weight\' => \'-49\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'0\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'Call setup guide for call administrator\',
        \'enabled\' => 1,
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
