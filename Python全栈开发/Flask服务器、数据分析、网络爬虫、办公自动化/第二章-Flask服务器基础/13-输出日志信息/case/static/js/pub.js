var img_count = 0;

function preView(file, element) {
    var add = document.createElement('div');
    add.className = 'pub-add';
    var input = document.createElement('input');
    input.setAttribute('type','file');
    input.setAttribute('onchange',"preView(this,$('.pub-add'))");
    add.appendChild(input);
    if (file.files && file.files[0]) {
        var imageType = /^image\//;
        if (!imageType.test(file.files[0].type)) {
            file.files[0] = null;
            return;
        }
        var reader = new FileReader();
        reader.onload = function (e) {
            $(file).attr('name','filelist');
            element.css({'background-image':"url(" + e.target.result + ")"}).attr('class','pub-img-item');
            img_count ++;
            if(img_count < 5){
                $('.kid-pub-imgslist').append(add);
            }
        }
        reader.readAsDataURL(file.files[0]);
    }
}

$(function(){
    $('.blog-loading').css({'display':'none'});
    $('.kid-container').css({'display':'block'});
})


