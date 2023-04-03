// 所有的游戏对象
let CAT_GAME_OBJECTS = [];

class CatGameObject{
    constructor(){
        // 把所有新建的游戏对象push到CAT_GAME_OBJECTS列表里面
        // CAT_GAME_OBJECTS存储的是所有游戏对象的指针
        CAT_GAME_OBJECTS.push(this);  

        // 刷新的时间间隔
        // 一秒刷新60次，1000/60=16.7ms 一帧需要16.7ms
        this.timedelta = 0; 
        this.has_call_start = false;
    }

    start(){

    }

    update(){

    }

    destroy(){
        // in 枚举数组下标  of 枚举数组的值
        for(let i in CAT_GAME_OBJECTS){
            if(CAT_GAME_OBJECTS[i] === this){
                CAT_GAME_OBJECTS.splice(i, 1);
                break;
            }
        }
    }
}

let last_timestamp = 0;

let step = (timestamp) => {

    for(let obj of CAT_GAME_OBJECTS){
        if(!obj.has_call_start){    // 每一个对象是否第一次调用
            obj.start();
            obj.has_call_start = true;
        }
        else{
            // if(last_timestamp === 0) obj.timedelta = 16.7;
            // else obj.timedelta = timestamp - last_timestamp;
            obj.timedelta = timestamp - last_timestamp;
            
            // console.log(timestamp, last_timestamp, obj.timedelta);
            obj.update();
        }
    }

    last_timestamp = timestamp;
    requestAnimationFrame(step);
}

requestAnimationFrame(step);

export{
    CatGameObject
}

