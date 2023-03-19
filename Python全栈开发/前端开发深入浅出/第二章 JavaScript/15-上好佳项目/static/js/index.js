function change_banner(current_selected_idx){
    $banner_imglist.eq(current_selected_idx).fadeIn(500).siblings().fadeOut(100);
    $banner_dotlist.eq(current_selected_idx).css({'backgroundColor':'white'}).siblings().css({'backgroundColor':''});
}

let $banner_imglist = $(".banner-imglist>img");
let $banner_dotlist = $(".banner-dotlist li");

let banner_imgs_cnt = $(".banner-imglist").children().length;
console.log(banner_imgs_cnt);

let current_selected_idx = 0;

// 初始化显示 下标为0 的图片和圆点
change_banner(current_selected_idx);

// 核心：改变 current_selected_idx 0、1、2、3、0、1、2、3
// let timer = null;
function startTimer(){
    $banner_imglist.timer = setInterval(function(){
        current_selected_idx = (current_selected_idx + 1) % banner_imgs_cnt;
        change_banner(current_selected_idx);
    }, 3600);
}

function main(){

    startTimer();

    $banner_imglist.mouseover(function(){   // 鼠标悬停在轮播图 停止轮播
        clearInterval($banner_imglist.timer);
    });

    $banner_imglist.mouseleave(function(){  // 鼠标离开轮播图 重新开始轮播
        startTimer();
    });

    // 点击圆点切换 轮播图
    $banner_dotlist.click(function(){
        let $idx = $(this).index();
        // console.log($idx);
        change_banner($idx);
    });

    // 前后翻页
    $(".banner-pre").click(function(){
        current_selected_idx -= 1;
        if(current_selected_idx < 0) current_selected_idx = banner_imgs_cnt - 1;
        change_banner(current_selected_idx);
    });

    $(".banner-next").click(function(){
        current_selected_idx += 1;
        // '2' == 2 true
        // '2' === 2 fasle
        if(current_selected_idx === banner_imgs_cnt) current_selected_idx = 0;
        change_banner(current_selected_idx);
    });
}

export{
    main
}