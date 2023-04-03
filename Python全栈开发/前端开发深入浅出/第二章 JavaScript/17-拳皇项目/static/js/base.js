import { GameCanvas } from "/static/js/game_canvas/base.js";
import { Player } from '/static/js/players/base.js';

class KOF{
    constructor(id){
        this.$kof = $("#" + id);
        // let obj1 = {'a':1};
        // this.$kof.append(obj1);
        // console.log(this.$kof);
        // console.log("xxx");
        // console.log("KOF:::", this.$kof);
        this.game_canvas = new GameCanvas(this);
        // this.game_canvas.render();

        this.players = [
            new Player(this, {
                id: 0,
                x: 200,
                y: 0,
                width: 120,
                height: 200,
                color: 'blue',
            }),
            new Player(this, {
                id: 1,
                x: 900,
                y: 0,
                width: 120,
                height: 200,
                color: 'red',
            }),
        ];
    }
}

export{
    KOF
}