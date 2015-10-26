// $Id$

CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation


INTRODUCTION
------------

Current Maintainer: Iver Thysen, Morten Thysen

This module allows for generation of application pdf files. The view 
pdf-all-applications/[call-main nid] lists applications in ESA system.
Select the applications you with to generate pdf files for. The view
will create a pdf file from application page and combine it with pdf
files from:

1. Application-project-info
2. Application-partner-budget

Each generated application pdf will be stored a the application_pdf 
node instance. Finaly the pdf files are zipped and added to call-main-page
for download.

INSTALLATION
------------

This module is a part of the Meta Knowledge Base package. mkb_pdf depends on
mkb_application and mkb_groups which both depends on mkb_call_admin. For this
module to work do the following:

1. Add fpdf to libraries
2. Add fpdi to libraries
3. Add tcpdf to libraries
4. Enable the dependeny modules for mkb_pdf
5. Configure Printer module (admin/config/user-interface/print)
	Note: if configuration page fails. Enable "Token tweaks" and set depth
	to 2.
6. Add the following fields to call-main-page:

Label					Machine name					Field type		Widget
Applications as needed 	field_call_as_needed_app_zip	File			File
Stage 1 applications	field_call_s1_app_zip			File			File
Stage 2 applications	field_call_s2_app_zip			File			File

All 3 fields must have these settings:
Check: Enable Display field
Check: Files displayed by default 
Check: Public files

Allowed file extensions: zip
Number of values: Unlimited
