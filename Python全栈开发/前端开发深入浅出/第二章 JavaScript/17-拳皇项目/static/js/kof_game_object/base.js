let KOF_GAME_OBJECTS = [];

class KofGameObject{
    constructor(){
        KOF_GAME_OBJECTS.push(this);

        this.timedelta = 0;
        this.has_call_start = false;
    }

    start(){

    }

    update(){

    }

    destroy(){
        for(let i in KOF_GAME_OBJECTS){
            if(KOF_GAME_OBJECTS[i] === this){   // 枚举下标
                KOF_GAME_OBJECTS.splice(i, 1);
                break;
            }
        }
    }
}

let last_timestamp = 0;

let step = (timestamp) => {
        
    for(let obj of KOF_GAME_OBJECTS){
        obj.update();
        obj.timedelta = timestamp - last_timestamp;
        // if(!obj.has_call_start){
        //     obj.start();
        //     obj.has_call_start = true;
        // }
        // else{
        //     obj.timedelta = timestamp - last_timestamp;
        //     obj.update();
        // }
    }
    // console.log(timestamp - last_timestamp);
    last_timestamp = timestamp;
    // 这一部分重复执行
    requestAnimationFrame(step);
}

requestAnimationFrame(step);

export{
    KofGameObject
}