$(function () {
    $('.blog-loading').css({'display':'none'});
    $('.kid-container').css({'display':'block'});

    //图片旋转展示
    var flag = true;
    var $list = $('.imgs-list li');
    var configs = [
        {'left': '80px', 'width': '700px', 'height': '450px', 'top': '0px', 'z-index': '3', 'opacity': '1'}
    ];
    if ($list.length > 1) {
        configs.push({
            'left': '10px',
            'width': '550px',
            'height': '390px',
            'top': '30px',
            'z-index': '2',
            'opacity': '0.6'
        });
    }
    if ($list.length > 2) {
        for (var i = 0; i < ($list.length - 3); i++) {
            configs.push({
                'left': '300px',
                'width': '550px',
                'height': '390px',
                'top': '30px',
                'z-index': '1',
                'opacity': '0'
            })
        }
        configs.push({
            'left': '300px',
            'width': '550px',
            'height': '390px',
            'top': '30px',
            'z-index': '1',
            'opacity': '0.6'
        });
    }
    var list = document.querySelectorAll('.imgs-list li');
    for (var i = 0; i < $list.length; i++) {
        $list.eq(i).css(configs[i])
        flag = true;
        $list.eq(i).find('div').animate({'width': configs[i]['width'], 'height': configs[i]['height']}, 300);
    }

    //图片适配
    var imgList = $('.imgs-list img');
    for (var i = 0; i < imgList.length; i++) {
        var path = imgList.eq(i).attr('src');
        var img = new Image();
        img.src = path;
        adaptive(img, imgList.eq(i));
    }


    $('.imgs-next').click(function () {
        if (flag) {
            flag = false;
            configs.unshift(configs.pop());
            assign();
        }
    });

    $('.imgs-pre').click(function () {
        if (flag) {
            flag = false;
            configs.push(configs.shift())
            assign();
        }
    });

    $('.kid-info-message img').click(function () {
        $('.kid-info-textarea').toggle({'display': 'block'});
    });

    function adaptive(img, obj) {
        img.onload = function () {
            if (img.width > img.height) {
                obj.css({'width': '100%'});
            } else {
                obj.css({'height': '100%'});
            }
        }
    }

    function assign() {
        for (var i = 0; i < $list.length; i++) {
            $list.eq(i).animate(configs[i], 300, function () {
                flag = true;
            });
            $list.eq(i).find('div').animate({'width': configs[i]['width'], 'height': configs[i]['height']}, 300);
        }
    }
});

