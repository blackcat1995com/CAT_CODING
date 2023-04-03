class Controller{
    constructor($canvas){
        this.$canvas = $canvas;

        this.pressed_keys = new Set();
        this.start();
    }

    start(){
        // console.log(this);
        let outer = this;
        this.$canvas.keydown(function(e){
            outer.pressed_keys.add(e.key);
            // console.log(e.key);
        });

        this.$canvas.keyup(function(e){
            outer.pressed_keys.delete(e.key);
        });

    }
}

export{
    Controller
}