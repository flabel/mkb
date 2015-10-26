function Create_email(form_id) {
// Open mail clent with selected email addresses
  mail_address_list = '';
  rows = document.getElementsByClassName('views-send-select form-checkbox');
  for (i=0; i<rows.length; i++) {
    checkbox = rows[i]; 
	if (checkbox.checked) {
      td = checkbox.parentNode.parentNode; // move to column top
      mail_column = td.classList.contains('views-field-mail');  // find column with mail address
      while(!mail_column) {
        td = td.nextElementSibling;
        mail_column = td.classList.contains('views-field-mail');
      }
      if (td.childElementCount > 0) mail_address = td.firstElementChild.text;  // there is a mailto link
      else mail_address = td.innerHTML;  // no mailto link
	  mail_address_list += mail_address + '; '
	}
  }
  if (mail_address_list == '') alert('Please select at least one item');  // alert no selection
  else window.open('mailto:' + mail_address_list);  // open mail client
}

