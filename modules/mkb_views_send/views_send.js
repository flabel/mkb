function Create_email() 
{
 var x = document.getElementById("views-form-send-mail-page");
 email_index = x.elements[0].name.substr(6); alert(email_index);
 email_index = x.elements[12].name.substr(6); alert(email_index);
 email_index = x.elements[13].name.substr(6); alert(email_index);
 
 
 i = 0;
 txt = '';
 while(document.getElementById('edit-views-send-'+i)) 
  {
   if (document.getElementById('edit-views-send-'+i).checked)
    {
	   for (j=0; j<x.length;j++) {
		   if (x.elements[j].name == 'email-' + i) {
			   if (txt.length>0) txt += '; ';
			     txt += x.elements[j].value;
			   
		   }
		   
	   }
    }      
   i++;
  }
 if (txt == '') alert('Please select at least one item');
 else window.open('mailto:' + txt);
}

