function getAnimal(year){
    if(year<0){
        alert("输入信息有误");
        return false;
    }
    var animals = ['0.png','1.png','2.png','3.png','4.png','5.png','6.png','7.png','8.png','9.png','10.png','11.png'];
    var index = year % 12;
    return animals[index];
}
function changeImg(data){
    imgName = getAnimal(data);
    $(".sign").css("background","url(../static/images/"+imgName+")");
}


function getQueryVariable(variable) {
       var query = window.location.search.substring(1);
       console.log(query);
       var vars = query.split("&");
       console.log(vars);
       for (var i=0;i<vars.length;i++) {
               var pair = vars[i].split("=");
               console.log(pair);
               if(pair[0] == variable){return pair[1];}
       }
       return(false);
}
changeImg(getQueryVariable("year"));
