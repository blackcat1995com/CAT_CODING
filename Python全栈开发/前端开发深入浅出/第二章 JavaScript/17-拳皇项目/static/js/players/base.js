import { KofGameObject } from "/static/js/kof_game_object/base.js";

class Player extends KofGameObject{
    constructor(root, info){
        super();
        this.root = root;
        this.id = info.id;
        this.x = info.x;
        this.y = info.y;
        this.width = info.width;
        this.height = info.height;
        this.color = info.color;

        this.direction = 1;
        this.vx = 0;    // 初始水平速度
        this.vy = 0;    // 初始垂直速度

        this.speedx = 400;  // 水平速度
        this.speedy = -1000;  // 跳起的初始速度

        this.gravity = 50;

        this.ctx = this.root.game_canvas.ctx;
        this.pressed_keys = this.root.game_canvas.controller.pressed_keys;
        // console.log(this.pressed_keys);
        this.status = 3;  // 0: idle, 1: 向前，2：向后，3：跳跃，4：攻击，5：被打，6：死亡

        this.frame_current_idx = 0;
    }

    start(){
        
    }

    update(){
        // console.log("xxxx");
        this.update_control();
        this.update_move();
        this.render();
    }

    update_control(){
        let w, a, d, z;
        if (this.id === 0) {
            w = this.pressed_keys.has('w');
            a = this.pressed_keys.has('a');
            d = this.pressed_keys.has('d');
            z = this.pressed_keys.has('z');
            // console.log(w, a, d, z, this.status);
        } else {
            w = this.pressed_keys.has('ArrowUp');
            a = this.pressed_keys.has('ArrowLeft');
            d = this.pressed_keys.has('ArrowRight');
            z = this.pressed_keys.has('ArrowDown');
        }

        if (this.status === 0 || this.status === 1) {
            if (z) {
                this.status = 4;
                this.vx = 0;
                this.frame_current_idx = 0;
            } else if (w) {
                if (d) {
                    this.vx = this.speedx;
                } else if (a) {
                    this.vx = -this.speedx;
                } else {
                    this.vx = 0;
                }
                this.vy = this.speedy;
                this.status = 3;
                this.frame_current_idx = 0;
            } else if (d) {
                this.vx = this.speedx;
                this.status = 1;
            } else if (a) {
                this.vx = -this.speedx;
                this.status = 1;
            } else {
                this.vx = 0;
                this.status = 0;
            }
        }
    }

    update_move(){
        this.vy += this.gravity;

        this.x += this.vx * this.timedelta / 1000;
        this.y += this.vy * this.timedelta / 1000;

        // 人物下落不能超过下边界
        if(this.y > 450){   
            this.y = 450;
            this.vy = 0;
            // 下落时，一定是处于跳跃状态，切换为静止状态
            if(this.status === 3) this.status = 0;    
        }

        // 人物移动不能超出边界
        if(this.x < 0) this.x = 0;
        else if(this.x + this.width > this.root.game_canvas.$canvas.width()){
            this.x = this.root.game_canvas.$canvas.width() - this.width;
        }
    }

    render(){
        this.ctx.fillStyle = this.color;
        this.ctx.fillRect(this.x, this.y, this.width, this.height);
    }

}


export{
    Player
}