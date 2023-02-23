$(function(){
  get_score();
});

/**
 * 获取内地票房排行榜
 */
function get_ranking(){
  // 加载banner图片
  ph_photoes = ['ph_zl2.jpg','ph_fczlm4.jpg','ph_lldq.jpg','ph_hhxd.jpg']
  arr = $('.slides').children('li')
  for(var i=0;i<arr.length;i++){
    arr[i].children[0].children[0].setAttribute("src","/static/images/banner/"+ph_photoes[i])
    console.log(arr[i].children[0].children[0].getAttribute("src"))
  }

  ajax_ranking(function(result){
    var data = result;
    var tbody = $('.gross_table').find('tbody');
    tbody.html('');
    var etitle = ['name','type','area','box office','show count','release time'];
    var ctitle = ['电影名','类型','地区','票房','上映场次','上映时间'];
    var dw = ['--','--','--','万元','场','--'];
    var tr = '<tr>';
    for(var i = 0;i<6;i++){
      tr += th_template('/static/images/gross-h'+(i+1)+'.jpg',etitle[i],ctitle[i],dw[i]);
    }
    tr += '</tr>';
    tbody.append(tr);
    //数据
    var ranking = data.map(function(value,index,arr){
      var dic = {};
      dic['name'] = value['name'];
      dic['type'] = value['type'];
      dic['area'] = value['area'];
      dic['boxOffice'] = value['boxOffice'];
      dic['showCount'] = value['showCount'];
      dic['releaseTime'] = value['releaseTime'];
      return dic
    });
    for(var i = 0;i<ranking.length;i++){
      var tr = (i % 2 == 0) ? tr_template_02(ranking[i]) : tr_template_01(ranking[i]);
      tbody.append(tr);
    }
  });
}

/**
 * 获取豆瓣高分电影
 * @param  {int} page 页数
 */
function get_score(){
  // 加载banner图片
  gf_photoes = ['gf_agzz.jpg','gf_dmkj.jpg','gf_xdldmd.jpg','gf_qyqx.jpg']
  arr = $('.slides').children('li')
  for(var i=0;i<arr.length;i++){
    arr[i].children[0].children[0].setAttribute("src","/static/images/banner/"+gf_photoes[i])
  }

  var tbody = $('.gross_table').find('tbody');
  tbody.html('');
  var div = '<div class="page">'+
              '<div id="resultBox"></div>'+
              '<div id="paging">'+
                '<div class="first">首页</div>'+
                '<div class="prev">上一页</div>'+
                '<ul class="list"></ul>'+
                '<div class="go">'+
                    '<input type="text" placeholder="Goto">'+
                    '<button>跳转</button>'+
                '</div>'+
                '<div class="next">下一页</div>'+
                '<div class="last">末页</div>'+
            '</div>';
  tbody.append(div);

  var $oResultBox = $('#resultBox');
  var books = data.books;
  var pages;

  $.get('/pages',function(result){
    pages = result;
    $('#paging').paging({
      nowPage: 1,
      allPages: pages,
      displayPage: 5,
      callBack: function (now) {
        ajax_score(now,function(result){
          $oResultBox.html('');
          for (var i = 0; i < 10; i++) {
            var create_dl = $('<dl></dl>');
            var _html = '<dt>'+
                          '<a href="#"><img height="165" width="115" src=/static/images/movies/'+result[i].poster+'></a>'+
                          '<p><span class="m_title">'+result[i]['name']+'<span class="m_rate">'+result[i]['rate']+'</span></span></p>'+
                        '</dt>';

            create_dl.html(_html).addClass('bounceIn animated');
            $oResultBox.append(create_dl);
          }
        });
      }
    });
  })
}
