import { Controller } from "/static/js/controller/base.js";
import { CatGameObject } from "/static/js/cat_game_object/base.js";

class GameCanvas extends CatGameObject{
    constructor(root){
        super(); // 子类调用父类构造函数
        this.root = root; // this.root：<div id="kof"></div>
        // KOF类：this.game_canvas = new GameCanvas(this);
        this.$canvas = $('<canvas width="1280" height="720" tabindex="0"></canvas>');
        this.ctx = this.$canvas[0].getContext("2d");
        this.root.$kof.append(this.$canvas);

        this.$canvas.focus();

        this.controller = new Controller(this.$canvas);
    }

    start(){

    }

    update(){
        this.render();
    }

    render(){
        this.ctx.clearRect(0, 0, this.$canvas.width(), this.$canvas.height());
        this.ctx.fillStyle = "black";
        this.ctx.fillRect(0, 0, this.$canvas.width(), this.$canvas.height());
    }
}


export{
    GameCanvas
}