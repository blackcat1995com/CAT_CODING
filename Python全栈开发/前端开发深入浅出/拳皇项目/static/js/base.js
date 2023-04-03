import { GameCanvas } from "/static/js/game_canvas/base.js";
// import { GameCanvas } from "/static/js/game_canvas/base.js";
// import { CatGameObject } from "/static/js/cat_game_object/base.js";
class KOF{
    constructor(id){
        this.$kof = $("#" + id);  
        // console.log(this.$kof);
        // this.game_canvas = new GameCanvas(this);
    }
}

export{
    KOF
}