function toggleSelectAll(cbx){
	var input_lastChar = cbx.id.substr(cbx.id.length - 7);
	var input_checked = cbx.checked;
//	alert(input_checked);
	var chk = document.getElementsByTagName("input");
//	alert(chk.length);
	for(i=0; i<chk.length; i++){
		if(chk[i].getAttribute("type") == "checkbox"){
//			alert(chk[i].id);
//			return;
			var lastChar = chk[i].id.substr(chk[i].id.length - 7);
			if(input_lastChar == lastChar){
				chk[i].checked = input_checked;
//				alert(chk[i].id);
//				return;
			}
		}
	}
	//alert(cbx.id);
	
}