import { GameCanvas } from "/static/js/game_canvas/base.js";
import { Player } from '/static/js/players/base.js';
// import { GameCanvas } from "/static/js/game_canvas/base.js";
// import { CatGameObject } from "/static/js/cat_game_object/base.js";
class KOF{
    constructor(id){
        this.$kof = $("#" + id);  
        // console.log(this.$kof);
        this.game_canvas = new GameCanvas(this);

        this.players = [
            new Player(this, {
                id:0,
                x:200,
                y:0,
                width:120,
                height:200,
                color:'blue'
            }),

            new Player(this, {
                id:1,
                x:900,
                y:0,
                width:120,
                height:200,
                color:'red'
            })
        ];

        console.log(this.players);
    }

}

export{
    KOF
}