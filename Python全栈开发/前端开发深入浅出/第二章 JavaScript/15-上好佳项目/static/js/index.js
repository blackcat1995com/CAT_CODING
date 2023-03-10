function change_banner(current_selected_idx){
    $(".banner-imglist img").eq(current_selected_idx).fadeIn(500).siblings().fadeOut(100);
    $(".banner-dotlist li").eq(current_selected_idx).css({'backgroundColor':'white'}).siblings().css({'backgroundColor':''});
}

let current_selected_idx = 0;
let banner_timer = null;

let all_imgs_cnt = $(".banner-imglist").children().length;
// console.log(all_imgs_cnt);

$(".banner-imglist").offset({top: 60});

// 初始化设置第一张图片和第一个小圆点（实心白色）
change_banner(current_selected_idx);

function startTimer(){
    banner_timer = setInterval(function(){
        current_selected_idx = (current_selected_idx + 1) % all_imgs_cnt;
        change_banner(current_selected_idx);
    }, 3600);
}

function main(){
    startTimer();

    $(".banner-imglist").mouseover(function(){
        clearInterval(banner_timer);
        // alert("mouseover");
    });

    $(".banner-imglist").mouseleave(function(){
        startTimer();
    });

    $(".banner-dotlist li").click(function(){
        let idx = $(this).index();
        change_banner(idx);
    });

    $(".banner-pre").click(function(){
        current_selected_idx -= 1;
        if(current_selected_idx === -1)
            current_selected_idx = all_imgs_cnt - 1;
        change_banner(current_selected_idx);
    });

    $(".banner-next").click(function(){
        current_selected_idx += 1;
        if(current_selected_idx === all_imgs_cnt)
            current_selected_idx = 0;
        change_banner(current_selected_idx);
    });
}

export{
    main
}