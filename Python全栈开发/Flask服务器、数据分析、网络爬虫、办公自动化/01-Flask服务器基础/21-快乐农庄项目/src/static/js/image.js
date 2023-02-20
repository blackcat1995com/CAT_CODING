/*
*金币图片
*/
var coin = new Image();
coin.src = "/static/image/icon/coin.png";

/*
*种子背景
*/
var seedBg = new Image();
seedBg.src = "/static/image/icon/seed_bg.png";

/*
 * 背景图片
 */
var bg1 = new Image();
bg1.src= "/static/image/background/1.png";
var bg2 = new Image();
bg2.src= "/static/image/background/2.png";
var bg3 = new Image();
bg3.src= "/static/image/background/3.png";
var bg4 = new Image();
bg4.src= "/static/image/background/4.png";

/*
 *菜单：植物、水壶、铲子 
 */
var menu_seed = new Image();
var menu_kettle = new Image();
var menu_collect = new Image();
var menu_shovel = new Image();
menu_seed.src = "/static/image/icon/menu_seed.png"
menu_kettle.src = "/static/image/icon/menu_kettle.png"
menu_collect.src = "/static/image/icon/menu_collect.png"
menu_shovel.src = "/static/image/icon/menu_shovel.png"
var menuImg = [menu_seed,menu_kettle,menu_collect,menu_shovel];


/*
 * 土地
 */
var soil1 = new Image();
soil1.src = "/static/image/soil/1.png";
var soil2 = new Image();
soil2.src = "/static/image/soil/2.png";
var soil3 = new Image();
soil3.src = "/static/image/soil/3.png";
var soil4 = new Image();
soil4.src = "/static/image/soil/4.png";
var soil5 = new Image();
soil5.src = "/static/image/soil/5.png";



/*
 * 草莓
 */
var straw = [];
straw[0] = new Image();
straw[0].src = "/static/image/crops/crop1/cron_start.png";
straw[1] = new Image();
straw[1].src = "/static/image/crops/crop1/1.png";
straw[2] = new Image();
straw[2].src = "/static/image/crops/crop1/2.png";
straw[3] = new Image();
straw[3].src = "/static/image/crops/crop1/3.png";
straw[4] = new Image();
straw[4].src = "/static/image/crops/crop1/4.png";
straw[5] = new Image();
straw[5].src = "/static/image/crops/crop1/5.png";
straw[6] = new Image();
straw[6].src = "/static/image/crops/crop1/cron_end.png";
straw[7] = new Image();
straw[7].src = "/static/image/crops/crop1/seed.png";

/*
 * 玉米
 */
var corn = [];
corn[0] = new Image();
corn[0].src = "/static/image/crops/crop2/cron_start.png";
corn[1] = new Image();
corn[1].src = "/static/image/crops/crop2/1.png";
corn[2] = new Image();
corn[2].src = "/static/image/crops/crop2/2.png";
corn[3] = new Image();
corn[3].src = "/static/image/crops/crop2/3.png";
corn[4] = new Image();
corn[4].src = "/static/image/crops/crop2/4.png";
corn[5] = new Image();
corn[5].src = "/static/image/crops/crop2/5.png";
corn[6] = new Image();
corn[6].src = "/static/image/crops/crop2/cron_end.png";
corn[7] = new Image();
corn[7].src = "/static/image/crops/crop2/seed.png";

/*
 * 土豆
 */
var potato = [];
potato[0] = new Image();
potato[0].src = "/static/image/crops/crop5/cron_start.png";
potato[1] = new Image();
potato[1].src = "/static/image/crops/crop5/1.png";
potato[2] = new Image();
potato[2].src = "/static/image/crops/crop5/2.png";
potato[3] = new Image();
potato[3].src = "/static/image/crops/crop5/3.png";
potato[4] = new Image();
potato[4].src = "/static/image/crops/crop5/4.png";
potato[5] = new Image();
potato[5].src = "/static/image/crops/crop5/5.png";
potato[6] = new Image();
potato[6].src = "/static/image/crops/crop5/cron_end.png";
potato[7] = new Image();
potato[7].src = "/static/image/crops/crop5/seed.png";

/*
 * 西红柿
 */
var tomato = [];
tomato[0] = new Image();
tomato[0].src = "/static/image/crops/crop7/cron_start.png";
tomato[1] = new Image();
tomato[1].src = "/static/image/crops/crop7/1.png";
tomato[2] = new Image();
tomato[2].src = "/static/image/crops/crop7/2.png";
tomato[3] = new Image();
tomato[3].src = "/static/image/crops/crop7/3.png";
tomato[4] = new Image();
tomato[4].src = "/static/image/crops/crop7/4.png";
tomato[5] = new Image();
tomato[5].src = "/static/image/crops/crop7/5.png";
tomato[6] = new Image();
tomato[6].src = "/static/image/crops/crop7/cron_end.png";
tomato[7] = new Image();
tomato[7].src = "/static/image/crops/crop7/seed.png";

/*
 * 西瓜
 */
var watermelon = [];
watermelon[0] = new Image();
watermelon[0].src = "/static/image/crops/crop12/cron_start.png";
watermelon[1] = new Image();
watermelon[1].src = "/static/image/crops/crop12/1.png";
watermelon[2] = new Image();
watermelon[2].src = "/static/image/crops/crop12/2.png";
watermelon[3] = new Image();
watermelon[3].src = "/static/image/crops/crop12/3.png";
watermelon[4] = new Image();
watermelon[4].src = "/static/image/crops/crop12/4.png";
watermelon[5] = new Image();
watermelon[5].src = "/static/image/crops/crop12/5.png";
watermelon[6] = new Image();
watermelon[6].src = "/static/image/crops/crop12/cron_end.png";
watermelon[7] = new Image();
watermelon[7].src = "/static/image/crops/crop12/seed.png";

/*
 * 仙桃
 */
var peach = [];
peach[0] = new Image();
peach[0].src = "/static/image/crops/crop14/cron_start.png";
peach[1] = new Image();
peach[1].src = "/static/image/crops/crop14/1.png";
peach[2] = new Image();
peach[2].src = "/static/image/crops/crop14/2.png";
peach[3] = new Image();
peach[3].src = "/static/image/crops/crop14/3.png";
peach[4] = new Image();
peach[4].src = "/static/image/crops/crop14/4.png";
peach[5] = new Image();
peach[5].src = "/static/image/crops/crop14/5.png";
peach[6] = new Image();
peach[6].src = "/static/image/crops/crop14/cron_end.png";
peach[7] = new Image();
peach[7].src = "/static/image/crops/crop14/seed.png";

var seedFrames = [corn,potato,tomato,watermelon,peach,straw]
var seedNames = ["玉米","土豆","西红柿","西瓜","仙桃","草莓"]
var seedPrices = [10,20,30,50,70,90]