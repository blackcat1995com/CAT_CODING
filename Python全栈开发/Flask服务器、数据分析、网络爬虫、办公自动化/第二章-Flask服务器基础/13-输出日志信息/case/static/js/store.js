$(function () {
    $('.blog-loading').css({'display':'none'});
    $('.shop-container').css({'display':'block'});
    $('.shop-prop-buy').click(function () {
        var propId = $(this).attr('data-propid');
        buyPropsAjax(propId);
    })
    $('.shop-entergame').click(function () {
        $('.shop-mask').hide();
    });
    $('.store-back').click(function(){
        window.open('/game/index','_self');
    })
});
