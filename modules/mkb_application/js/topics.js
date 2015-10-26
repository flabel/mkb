function checkTopics(cbx){
	var chk = document.getElementsByTagName("input");
	var chk_list = [];
	var x = 0;
	var y = 0;
	var cbx_row;
	for(i=0; i<chk.length; i++){
		if(chk[i].getAttribute("type") == "checkbox" && chk[i].id.indexOf("edit-field-app-topics-und") !== -1){
			var lbl = document.getElementsByTagName("label");	
			for(j=0; j<lbl.length; j++){
				if(lbl[j].htmlFor == chk[i].id){
					if(lbl[j].innerHTML.indexOf("<b>") !== -1){
						//alert("bold");
						if(y==0){
							chk_list[0] = [];
							chk_list[0][0] = chk[i].id;
						}
						else{
							x++;
							chk_list[x] = [];
							chk_list[x][0] = chk[i].id;							
						}
						
						y=0;						
					}
					else{
						//alert("not bold");
						chk_list[x][y] = chk[i].id;
					}
				}
			}
			if(chk[i].id == cbx.id){
				cbx_row = x;
				cbx_col = y;
			}
			y++;			
		}
	}
	
	for(i=0; i<chk_list.length; i++){
		for(j=0; j<chk_list[i].length; j++){
			for(k=0; k<chk.length; k++){
				//Checked checkbox is in this row and is checked
				if(chk[k].id == chk_list[i][j] && cbx_row == i && cbx.checked){
					//Theme checked
					if(cbx_col == 0){
						chk[k].checked = true;
					}
					//Topic checked
					else{
						//Theme in loop
						if(j == 0){
							chk[k].checked = true;
						}
						//Topic in loop
						else{
							//Topic checked
							if(j == cbx_col){
								chk[k].checked = true;
							}
							//Topics not checked
							else{
								//Topic is already checked
								if(chk[k].checked){
									chk[k].checked = true;
								}
								//Topic was not checked
								else{
									chk[k].checked = false;									
								}
							}
						}
					}
				}
				//Checked checkbox is NOT in this row and is checked
				if(chk[k].id == chk_list[i][j] && cbx_row !== i && cbx.checked){
					chk[k].checked = false;
				}
				//Checked checkbox is in this row and is NOT checked
				if(chk[k].id == chk_list[i][j] && cbx_row == i && !cbx.checked){
					//Theme unchecked
					if(cbx_col == 0){
						chk[k].checked = false;
					}
				}
				
			}
		}
		
	}
}