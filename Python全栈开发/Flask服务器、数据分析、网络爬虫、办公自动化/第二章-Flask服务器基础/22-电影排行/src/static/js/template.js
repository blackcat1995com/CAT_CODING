function th_template(bg,etitle,ctitle,dw){
  var template = 
                '<th>'+
                  '<div style="width:165px;height:166px;background: url(' + bg + ');display: inline-block;position: relative;top:-5px;">'+
                    '<span style="display:inline-block;height:35px;line-height: 35px;color:white;">'+ etitle +'</span>'+
                    '<h3 style="margin-top: 15px;height:50px;line-height: 50px;font-size:24px;font-weight: bold;color:white;">'+ctitle+'</h3>'+
                    '<span style="display: inline-block;margin-top:20px;color:white;height:30px;font-size: 20px;line-height: 30px;">'+dw+'</span>'+
                  '</div>'+
                '</th>';
  return template;
}

function time_template(date){
  var template = 
                '<th width="175" class="DateTime">'+
                  '<h2 style="height: 23px;"></h2>'+
                  '<h1>'+date+'</h1>'+
                '</th>';
  return template;
}

function tr_template_01(data){
  var template = '<tr>';
  var keys = Object.keys(data)
  for(var i = 0;i < keys.length;i++){
    switch(i){
      case 0 : template += '<td align="left" class="gray-bg">'+data[keys[i]]+'</td>'; break;
      case 1 : template += '<td class="bgcolor2">'+data[keys[i]]+'</td>'; break;
      case 2 : template += '<td class="bgcolor3">'+data[keys[i]]+'</td>'; break;
      case 3 : template += '<td class="bgcolor4">'+data[keys[i]]+'</td>'; break;
      case 4 : template += '<td class="bgcolor5">'+data[keys[i]]+'</td>'; break;
      case 5 : template += '<td class="bgcolor6">'+data[keys[i]]+'</td>'; break;
    }
  }
  template += '</tr>';
  return template;
}

function tr_template_02(data){
  var template = '<tr>';
  var keys = Object.keys(data)
  for(var i = 0;i < keys.length;i++){
    switch(i){
      case 0 : template += '<td align="left" class="graybg2">'+data[keys[i]]+'</td>'; break;
      case 1 : template += '<td class="bgc2">'+data[keys[i]]+'</td>'; break;
      case 2 : template += '<td class="bgc3">'+data[keys[i]]+'</td>'; break;
      case 3 : template += '<td class="bgc4">'+data[keys[i]]+'</td>'; break;
      case 4 : template += '<td class="bgc5">'+data[keys[i]]+'</td>'; break;
      case 5 : template += '<td class="bgc6">'+data[keys[i]]+'</td>'; break;
    }
  }
  template += '</tr>';
  return template;
}

function tr_template_03(data1,data2){
  var template = '<tr>';
  var keys1 = Object.keys(data1);
  var keys2 = Object.keys(data2);
  for(var i = 0;i < keys1.length;i++){
    switch(i){
      case 0 : template += '<td align="left" class="gray-bg">'+data1[keys1[i]]+'</td>'; break;
      case 1 : template += '<td class="bgcolor2">'+data1[keys1[i]]+'</td>'; break;
      case 2 : template += '<td class="bgcolor3">'+data1[keys1[i]]+'</td>'; break;
      case 3 : template += '<td class="bgcolor4">'+data1[keys1[i]]+'</td>'; break;
      case 4 : template += '<td class="bgcolor5">'+data1[keys1[i]]+'</td>'; break;
      case 5 : template += '<td class="bgcolor6">'+data1[keys1[i]]+'</td>'; break;
    }
  }
  for(var i = 0;i < keys2.length;i++){
    switch(i){
      case 0 : template += '<td align="left" class="gray-bg">'+data2[keys2[i]]+'</td>'; break;
      case 1 : template += '<td class="bgcolor2">'+data2[keys2[i]]+'</td>'; break;
      case 2 : template += '<td class="bgcolor3">'+data2[keys2[i]]+'</td>'; break;
      case 3 : template += '<td class="bgcolor4">'+data2[keys2[i]]+'</td>'; break;
      case 4 : template += '<td class="bgcolor5">'+data2[keys2[i]]+'</td>'; break;
      case 5 : template += '<td class="bgcolor6">'+data2[keys2[i]]+'</td>'; break;
    }
  }
  template += '</tr>';
  return template;
}

function tr_template_04(data1,data2){
  var template = '<tr>';
  var keys1 = Object.keys(data1);
  var keys2 = Object.keys(data2);
  for(var i = 0;i < keys1.length;i++){
    switch(i){
      case 0 : template += '<td align="left" class="graybg2">'+data1[keys1[i]]+'</td>'; break;
      case 1 : template += '<td class="bgc2">'+data1[keys1[i]]+'</td>'; break;
      case 2 : template += '<td class="bgc3">'+data1[keys1[i]]+'</td>'; break;
      case 3 : template += '<td class="bgc4">'+data1[keys1[i]]+'</td>'; break;
      case 4 : template += '<td class="bgc5">'+data1[keys1[i]]+'</td>'; break;
      case 5 : template += '<td class="bgc6">'+data1[keys1[i]]+'</td>'; break;
    }
  }
  for(var i = 0;i < keys2.length;i++){
    switch(i){
      case 0 : template += '<td align="left" class="graybg2">'+data2[keys2[i]]+'</td>'; break;
      case 1 : template += '<td class="bgc2">'+data2[keys2[i]]+'</td>'; break;
      case 2 : template += '<td class="bgc3">'+data2[keys2[i]]+'</td>'; break;
      case 3 : template += '<td class="bgc4">'+data2[keys2[i]]+'</td>'; break;
      case 4 : template += '<td class="bgc5">'+data2[keys2[i]]+'</td>'; break;
      case 5 : template += '<td class="bgc6">'+data2[keys2[i]]+'</td>'; break;
    }
  }
  template += '</tr>';
  return template;
}
