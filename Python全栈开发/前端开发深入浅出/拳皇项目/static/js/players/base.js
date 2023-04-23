import { CatGameObject } from '/static/js/cat_game_object/base.js';

class Player extends CatGameObject{
    constructor(root, info){
        super();
        this.root = root;
        this.id = info.id;
        this.x = info.x;
        this.y = info.y;
        this.width = info.width;
        this.height = info.height;
        this.color = info.color;

        this.vx = 0;
        this.vy = 0;

        this.speedx = 400;
        this.speedy = -1000;

        this.gravity = 50;

        this.ctx = this.root.game_canvas.ctx;

        this.pressed_keys = this.root.game_canvas.controller.pressed_keys;

        // 0:静止 1:前进 2:后退 3:跳跃 4:攻击 5:被打 6:死亡
        this.status = 3;

        this.frame_current_idx = 0;
    }

    start(){

    }

    update(){
        this.update_control();
        this.update_move();

        this.render();
    }

    update_control(){
        let w, a, d, z;

        if(this.id === 0){
            w = this.pressed_keys.has_key('w');
            a = this.pressed_keys.has_key('a');
            d = this.pressed_keys.has_key('d');
            z = this.pressed_keys.has_key('z');
        }
        else{
            w = this.pressed_keys.has_key('ArrowUp');
            a = this.pressed_keys.has_key('ArrowLeft');
            d = this.pressed_keys.has_key('ArrowRight');
            z = this.pressed_keys.has_key('ArrowDown');
        }

        if(this.status === 0 || this.status === 1){
            
        }
    }

    update_move(){
        this.vy += this.gravity;

        this.x += this.vx * this.timedelta / 1000;
        this.y += this.vy * this.timedelta / 1000;

        if(this.y > 450){
            this.y = 450;
            this.vy = 0;

            if(this.status === 3) this.status = 0;
        }

        if(this.x < 0) this.x = 0;
        else if(this.x + this.width > this.root.game_canvas.$canvas.width()){
            this.x = this.root.game_canvas.$canvas.width() - this.width;
        }
    }

    render(){
        this.ctx.fillStyle = this.color;
        this.ctx.fillRect(this.x, this.y, this.width, this.height);
        // console.log("render");
        // this.ctx.fillStyle = "red";
        // this.ctx.fillRect(0, 0, 100, 100);
    }
}

export{
    Player
}