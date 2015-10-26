function calcScore(score_min, score_calc){
	var e = document.getElementsByTagName("select");
	var score_sum = 0;
	var score_sum_p1 = 0;
	var i_num = 0;
	for(i=0; i<e.length; i++){
		if(e[i].id.indexOf("edit-quest-data-") !== -1){
			var i_num = i_num + 1;
			var s = document.getElementById(e[i].id);
			var score = s.options[s.selectedIndex].value;

			score_sum = parseInt(score_sum) + parseInt(score);
			score_sum_p1 = parseInt(score_sum_p1) + parseInt(score) + score_min;
		}
	}

	// Score calc: 0 = SUM, 1 = MEAN
	if(score_calc == 0){
        var score = parseInt(score_sum_p1);
        var score_field = document.getElementById("edit-field-eval-score-und-0-value");
        score_field.value = score;
	}
	else{
		score_pos = (parseInt(score_sum)*100/i_num)+50;
		document.getElementById("pointer").style.left = score_pos + "px";
		var score = parseInt(score_sum_p1)/i_num;
		var score_field = document.getElementById("edit-field-eval-score-und-0-value");
		score_field.value = roundToTwo(score);
	}
}

function roundToTwo(num) {    
    return +(Math.round(num + "e+1")  + "e-1");
}
