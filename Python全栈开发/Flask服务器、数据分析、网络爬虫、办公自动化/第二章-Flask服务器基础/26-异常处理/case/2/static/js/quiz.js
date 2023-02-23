const TOTAL_LEVEL = 5; //总关卡数
var ques_arr;    // 当前等级的题库（10）
var level = 1;   // 初始化等级
var score = 0;   //初始化分数
var correct_count = 0;   //回答正确的题目数量，用于判断挑战是否成功
var ajax_flag = false;    // AJAX请求锁，防止多次点击重复请求

$(function () {
    //加载动画
    $('.blog-loading').css({'display':'none'});
    $('.kid-container').css({'display':'block'});

    //初始score隐藏
    $('.score').hide();

    //返回按钮的点击事件
    $('.checkpoint-back,.quiz-back').click(function(){
        window.open(BASE_PATH + '/','_self');
    });

    selectionInterface();
    oFrameClick();
    slideCheckPoints();

    //背景音乐
    // $('#bg-music')[0].play();
});

/*
 * @ description 选题界面图形展示
 */
function selectionInterface() {
    showCheckPoints();
    changeCheckBox();
}

/*
 * @ description 答题界面图形展示
 */
function questionInterface() {
    //后台获取题目
    getQuestions(level,function(questions){
        ques_arr = questions;
        randomQuestion();
    });

    showQuestionTab();
}

/*
 * @ description 选择宝箱界面
 */
function showCheckPoints() {
    $('.frame-quiz').removeClass('show').addClass('hide');
    setTimeout(function () {
        $('.frame-quiz').removeClass('hide').css({'display': 'none'});
        $('.frame-checkpoints').css({'display': 'block'}).addClass('show');
    }, 500)
}

/*
 * @ description 左右拉动动画效果
 */
function slideCheckPoints() {
    var index = 0;
    var list = $('.checkpoint-frame .points ul');
    var position = ['0%', '-34%', '-67%', '-100%'];
    $('.checkpoint-frame .pre').click(function () {
        if (index > 0) {
            index--;
            list.animate({left: position[index]});
        }
    });
    $('.checkpoint-frame .next').click(function () {
        if (index < 2) {
            index++;
            list.animate({left: position[index]});
        }
    });
}

/*
 * @ description 更改宝箱图标
 */
function changeCheckBox() {
    for (var i = 1; i <= TOTAL_LEVEL + 1; i++) {
        if (i < level) {
            $('.points ul li:nth-child(' + i + ')').css(
                {'background-image': 'url(/static/images/quiz/box-le' + i + '-open.png)'}
            ).unbind('click');
        } else if (i > level) {
            $('.points ul li:nth-child(' + i + ')').css(
                {'background-image': 'url(/static/images/quiz/box-dull.png)'}
            ).unbind('click');
        } else {
            $('.points ul li:nth-child(' + i + ')').css(
                {'background-image': 'url(/static/images/quiz/box-le' + i + '.png)'}
            ).click(function () {
                questionInterface();
                $('.score').css({'background-image': 'url(/static/images/quiz/score' + level + '.png)'}).show(500);
            });
        }
    }
}

/*
 * @ description 显示答题卡
 */
function showQuestionTab() {
    $('.frame-checkpoints').removeClass('show').addClass('hide');
    setTimeout(function () {
        $('.frame-checkpoints').removeClass('hide').css({'display': 'none'});
        $('.frame-quiz').css({'display': 'block'}).addClass('show');
    }, 500)
}

/*
 * @ description 选项的点击事件
 */
function oFrameClick() {
    $('.oframe').click(function () {
        var select = $(this);
        //校验结果是否正确
        var id = $('.content').data('quesid');
        var option = $(this).data('ans');
        //发起ajax请求时锁定点击，防止重复多次请求
        if (ajax_flag) return;
        ajax_flag = true;
        checkQuestion(id, option, function(result){
            result == 'right' ? correctAnswer(select) : wrongAnswer(select);
            setTimeout(function () {
                randomQuestion();
                //重置AB选项样式
                select.css({'background-image': 'url(/static/images/quiz/option.png)'});
                $('.answer').removeClass('answer-correct').removeClass('answer-incorrect');
                //解除锁定
                ajax_flag = false;
            }, 1500);
        });
    })
}

/*
 * @description 随机一个题目
 */
function randomQuestion() {
    var length = ques_arr.length;
    if (length <= 0) {
        correct_count > TOTAL_LEVEL + 1 ? passThrough() : failure();
    } else {
        var random = parseInt(Math.random() * length);
        $('.content').data('quesid', ques_arr[random]['_id']);
        $('.content>p').html(ques_arr[random].question);
        $('.oframe-1>p').html("A." + ques_arr[random].option_a);
        $('.oframe-2>p').html("B." + ques_arr[random].option_b);
        ques_arr.splice(random, 1);
    }
}

/*
 * @description 挑战成功
 */
function passThrough() {
    correct_count = 0;  // 重置正确题目数量
    //开启遮罩和通关动画
    $('.mask').show();
    $('.pass-through').addClass('pass-success');
    $('#success-music')[0].play();
    //等级增加
    if (level <= TOTAL_LEVEL) {
        level++;
    }
    //判断是否通关最后一关
    if (level < TOTAL_LEVEL + 1) {
        setTimeout(function () {
            //显示选择界面
            selectionInterface();
            //是否向右滚动
            if (level > 2 && level < TOTAL_LEVEL) {
                $('.checkpoint-frame .next').trigger('click');
            }
            //隐藏通关动画
            $('.pass-through').removeClass('pass-success').removeClass('pass-failure');
            //隐藏分数和遮罩
            $('.score').hide(500);
            $('.mask').hide();
            $('.gameover').hide();
        }, 1000);
    } else {
        gameOver();
    }
}

/*
 * @ description 挑战失败
 */
function failure() {
    $('.mask').show();
    $('.pass-through').addClass('pass-failure');
    $('#failure-music')[0].play();
    gameOver();
}


/*
 * @ description 回答正确
 */
function correctAnswer(select) {
    var length = ques_arr.length;
    preLoadImg('/static/images/quiz/correct.png', function () {
        select.css({'background-image': 'url(/static/images/quiz/correct.png)'});
        $('.answer').addClass('answer-correct');
        score += 5 * level;
        correct_count++;
        $('.score p').html(score);
        $('#correct-music')[0].play();
    })
}

/*
 * @ description 回答错误
 */
function wrongAnswer(select) {
    preLoadImg('/static/images/quiz/incorrect.png', function () {
        select.css({'background-image': 'url(/static/images/quiz/incorrect.png)'});
        $('.answer').addClass('answer-incorrect');
        $('#error-music')[0].play();
    })
}

/*
 * @ description 游戏结束
 */
function gameOver(){
    var coins = parseInt(score/5);
    addCoins(coins,function(){
        setTimeout(function(){
            $('.gameover').css({'display': 'block'}).addClass('show');
            $('.score-number').html(parseInt(score/5));
            $('.quiz-replay').click(reload);
            $('.back-index').click(function(){
                window.open('/','_self');
            })
        },300)
    })
}

/*
 * @ description 页面重置
 */
function reload() {
    level = 1;  //重置等级
    score = 0;  //重置分数
    slideCheckPoints();   //重新绑定事件
    changeCheckBox();  //重置箱子
    //列表拉回最左侧
    $('.checkpoint-frame .points ul').css({'left': '0%'});
    //重置页面显示分数
    $('.score p').html(score);
    selectionInterface();
    //隐藏通关动画
    $('.pass-through').removeClass('pass-success').removeClass('pass-failure');
    //隐藏分数和遮罩
    $('.score').hide(500);
    $('.mask').hide();
    $('.gameover').hide();
}

/*
 * @ description 工具方法 图片预加载 防止第一次加载图片闪烁
 */
function preLoadImg(url, callback) {
    var img = new Image();
    img.onload = function () {
        img.onload = null;
        callback(img);
    }
    img.src = url;
}


