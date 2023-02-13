let list = document.getElementById("list");
let word = document.getElementById("word");

let arr = ["吃饭", "睡觉", "打豆豆"];
for(let i = 0; i < arr.length; i++){
    let temp = document.createElement("li");
    temp.innerHTML = arr[i];
    list.append(temp);
}

word.onblur = function(){
    let value = word.value;

    if(value.trim().length){
        let temp = document.createElement("li");
        temp.innerHTML = value;
        list.append(temp);
    }
    else 
        alert("请输入内容");
}