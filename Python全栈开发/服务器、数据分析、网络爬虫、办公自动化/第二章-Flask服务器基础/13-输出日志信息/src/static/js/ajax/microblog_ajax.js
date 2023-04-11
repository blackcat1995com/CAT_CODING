function loading_more(showMicroblog){
    var page = $.cookie('page') ? $.cookie('page') : 2;  //从第二页开始
    var page = $.cookie('page');
    if(!page){
      page = 2;
    }
    $.get('/microblog/load?page=' + page, function (result) {
        showMicroblog(result);
        if(result['data'].length > 0){
            page += 1;
            $.cookie('page', page);
        }
    });
}

function head_update(img){
    head_image = img.src.split('/');
    head_image = head_image[head_image.length - 1];
    $.get('/user/update?head=' + head_image,function(result){
        if(result['code'] == 0){
            window.location.reload();
        }
    })
}
