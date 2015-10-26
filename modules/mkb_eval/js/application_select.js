function Totals(){
	rows = document.getElementById('application_selection_table').getElementsByTagName("TR");

	hdata = new Array();
	for (var i = 2; i < 4; i++) {
		hcells = rows[i].getElementsByTagName('TH');
		hdata[i-2] = new Array(hcells.length);
	    for (var j = 1; j < hcells.length; j++) {
	    	hdata[i-2][j-1] = 0;
	    }
	}
	
	for (var i = 5; i < rows.length; i++) {
	    rcells = rows[i].getElementsByTagName('TD');

	    checked = false;
    	if(rcells[0].getElementsByTagName('input')[0].checked){
    		checked = true;
    	}
	    for (var j = 5; j < rcells.length-1; j++) {
	    	if(checked){
	    		// requested funding
	    		hdata[0][j-5] = hdata[0][j-5] + parseInt(rcells[j].innerHTML);
	    		// Deficit
	    		hcells_j = j-4;
	    		avaliable = parseInt(document.getElementById('cell_1_' + hcells_j).innerHTML);
	    		hdata[1][j-5] = avaliable-hdata[0][j-5];
	    	}
	    }
	}

	requested = 0;
	deficit = 0;
	for (var i = 2; i < 4; i++) {
		hcells = rows[i].getElementsByTagName('TH');
		// Set header (hcells) with data from hdata 
	    for (var j = 1; j < hcells.length-1; j++) {
	    	// Set requested funding and deficit
	    	cell = hdata[i-2][j-1];
	    	hcells[j].innerHTML = cell;
	    	// Add cell to totals

	    	// Requested
	    	if(i==2){
	    		requested += cell;
	    	}

	    	// Deficit
	    	if(i==3){
		    	if(cell<0){
		    		deficit += cell;
			    	hcells[j].className = "text_red";
		    	}
		    	else{
			    	hcells[j].className = "text_black";	    		
		    	}
	    	}
	    }
	    // Set totals
	    if(i==2){
		    hcells[hcells.length-1].innerHTML = requested;	    	
	    }
	    if(i==3){
	    	avaliable_index = hcells.length-1;
	    	avaliable_total = document.getElementById('cell_1_' + avaliable_index).innerHTML;
	    	deficit_total = parseInt(avaliable_total)-requested;
	    	hcells[hcells.length-1].innerHTML = deficit_total;
	    	if(deficit_total<0){
	    		hcells[hcells.length-1].className = "text_red";
	    	}
	    	else{
	    		hcells[hcells.length-1].className = "text_black";	    		
	    	}

	    }
	}
}
