//注册功能的ajax方法
function register_post(){
	var username = document.getElementsByClassName('ele-username')[0];
	var password = document.getElementsByClassName('ele-password')[0];
	var data = {
		'username' : username.value,
		'password' : password.value
	}

	$.post('/user/register',data,function(result){
    if(result['status'] == 'success'){
      alert(result['msg']);
      window.location.href = "/user/login";
    }else{
      showErrorMessage(result['msg']);
    }
	});
}

/**
   * 错误消息提示
   * @param {String} msg 提示消息
   */
function showErrorMessage(msg){
  var error = document.querySelector('.regist-repass .error-msg');
  error.innerHTML = msg;
}
