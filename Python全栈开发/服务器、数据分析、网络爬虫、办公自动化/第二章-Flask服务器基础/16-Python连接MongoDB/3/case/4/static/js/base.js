var BASE_PATH = "http://"+window.location.host;
$('.kid-list-blog').click(function () {
    window.open(BASE_PATH + '/', '_self');
});
$('.kid-list-quiz').click(function () {
    window.open(BASE_PATH + '/quiz', '_self');
});
$('.kid-list-game').click(function () {
    window.open(BASE_PATH + '/game', '_self');
});