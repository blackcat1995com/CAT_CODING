/**
 * 请求内地票房排行
 * @param  {function} showRanking 展示票房排行数据的方法
 */
function ajax_ranking(showRanking) {
    //发送ajax请求展示票房排行数据
    $.get('/ranking', function (result) {
        showRanking(result);
    });
}

/**
 * 请求豆瓣高分电影
 * @param  {int} page      页数
 * @param  {function} showScore 展示高分电影数据的方法
 */
function ajax_score(page, showScore) {
    //发送ajax请求并传递请求参数page，展示高分电影数据
    $.get('/score?page=' + page, function (result) {
        showScore(result);
    });
}





