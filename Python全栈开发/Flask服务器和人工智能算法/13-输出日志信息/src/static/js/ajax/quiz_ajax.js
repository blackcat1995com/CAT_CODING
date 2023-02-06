/*
 * @description 获取当前关卡的题目
 * @param level {String} : 获取题库的等级
 * @param callback {function} : 回调函数,用于题目的展示
 */
function getQuestions(level,showQuestion) {
    $.get("/quiz/question?level=" + level, function (result) {
        if (result['code'] == 0) {
            showQuestion(result['data']);
        }
    });
}

/*
 * @description 检查答案是否正确
 * @param id {String} : 题目id
 * @param option {String} : 用户选项
 * @param showResult {function} : 回调函数，用于显示题目正确或是错误
 */
function checkQuestion(id, answer, showResult) {
    var url = '/quiz/check?quiz_id=' + id + '&answer=' + answer;
    $.get(url, function (result) {
        if (result['code'] == 0) {
            showResult(result['data']);
        }
    })
}

/**
 * 增加金币
 * @param {int} coins   需要增加金币的数量，与分数有关
 * @param {function} showTab 展示金币弹窗
 */
function addCoins(coins,showTab){
    $.get('/quiz/addCoins?coins=' + coins,function(result){
        if(result['code'] == 0){
            showTab();
        }
    });
}









