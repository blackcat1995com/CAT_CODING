
(function(){window.OB=window.OB||{},window.OB.RiLi=window.OB.RiLi||{},window.OB.RiLi.dateRest=["0101","0102","0103","0218","0219","0220","0221","0222","0223","0224","0404","0405","0406","0501","0502","0503","0620","0621","0622","0903","0904","0905","0926","0927","1001","1002","1003","1004","1005","1006","1007"],window.OB.RiLi.dateWork=["0104","0215","0228","0906","1010"],window.OB.RiLi.dateFestival=["20150101||元旦","20150219||春节","20150405||清明节","20150501||劳动节","20150620||端午节","20150903||抗战纪念日","20150927||中秋节","20151001||国庆节"],window.OB.RiLi.dateAllFestival=["正月初一|v,春节","正月十五|v,元宵节","二月初二|v,龙头节","五月初五|v,端午节","七月初七|v,七夕节","七月十五|v,中元节","八月十五|v,中秋节","九月初九|v,重阳节","十月初一|i,寒衣节","十月十五|i,下元节","腊月初八|i,腊八节","腊月廿三|i,祭灶节","0202|i,世界湿地日,1996","0214|v,西洋情人节","0308|i,国际妇女节,1975","0315|i,国际消费者权益日,1983","0422|i,世界地球日,1990","0501|v,国际劳动节,1889","0512|i,国际护士节,1912","0518|i,国际博物馆日,1977","0605|i,世界环境日,1972","0623|i,国际奥林匹克日,1948","0624|i,世界骨质疏松日,1997","1117|i,世界学生日,1942","1201|i,世界艾滋病日,1988","0101|v,元旦","0312|i,植树节,1979","0504|i,五四青年节,1939","0601|v,儿童节,1950","0701|v,建党节,1941","0801|v,建军节,1933","0903|v,抗战胜利纪念日","0910|v,教师节,1985","1001|v,国庆节,1949","1224|v,平安夜","1225|v,圣诞节","w:0520|v,母亲节,1913","w:0630|v,父亲节","w:1144|v,感恩节(美国)","w:1021|v,感恩节(加拿大)"];var e="https://s.ssl.qhimg.com/!97be6a4c/data/"/*本地老黄历库在lhl文件夹，此处是官网调用的*/;location.protocol=="https:"&&(e="https://s.ssl.qhimg.com/!97be6a4c/data/")/*本地老黄历库在lhl文件夹，此处是官网调用的*/,window.OB.RiLi.hlUrl={2008:e+"hl2008.js",2009:e+"hl2009.js",2010:e+"hl2010.js",2011:e+"hl2011.js",2012:e+"hl2012.js",2013:e+"hl2013.js",2014:e+"hl2014.js",2015:e+"hl2015.js",2016:e+"hl2016.js",2017:e+"hl2017.js",2018:e+"hl2018.js",2019:e+"hl2019.js",2020:e+"hl2020.js"},window.OB.RiLi.dateHuochepiao=["-20141201||20","20141201||30","20141202||36","20141203||42","20141204||48","20141205||54","+20141205||60","c20141221-20141228||red"],window.OB.RiLi.useLunarTicketDay={2015:{"0218":"除夕","0219":"初一","0220":"初二","0221":"初三","0222":"初四","0223":"初五","0224":"初六","0225":"初七"}}})()

_loader.use("jquery",function(){function l(){t.slideDown(),r.slideDown(),i=="1"&&$.ajax({url:v("https://open.onebox.haosou.com/dataApi"),dataType:"jsonp",data:{query:"日历",url:"日历",type:"rili",user_tpl:"ajax/rili/html",selectorPrefix:s,asynLoading:i,src:"onebox",tpl:"1"},timeout:5e3,success:function(t){t&&t.html?(e.find(".mh-rili-widget").html(t.html),n.hide().addClass("mh-err"),i="0"):d()},error:function(){d()}})}function c(t,n){t=t.replace("\u6e05\u660e","\u6e05\u660e\u8282").replace("\u56fd\u9645\u52b3\u52a8\u8282","\u52b3\u52a8\u8282");var r=new RegExp(u);f=f||e.find("#mh-date-y").html(),u&&n==f&&r.test(t)?a=!0:a=!1,o.val(t).trigger("change")}function h(){$.each(o.find("option"),function(e,t){var n=$(this);n.data("desc")&&n.val()&&(u+=n.val()+"|")}),u=u.substring(0,u.length-2)}function p(){n.hide()}function d(){n.addClass("mh-err")}function v(e){return location.protocol=="https:"?"https://open.onebox.haosou.com/api/proxy?__url__="+encodeURIComponent(e):e}jQuery.curCSS=jQuery.css;var e=$("#mohe-rili"),t=$(".mh-rili-wap",e),n=$(".mh-tips",e),r=$(".mh-rili-foot",e),i="0",s="#mohe-rili .mh-rili-widget",o=e.find(".mh-holiday-data"),u="",a=!1,f=e.find("#mh-date-y").html();h(),e.on("click",".mh-op a",function(e){e.preventDefault();var n=$(this).closest(".mh-op");n.hasClass("mh-op-less")?(t.slideUp(),r.slideUp()):l(),n.toggleClass("mh-op-less")}).on("click",".mh-js-reload",function(e){e.preventDefault(),l()}).on("change",".mh-holiday-data",function(){var e=$(this),t=e.val(),n=e.find("option:selected"),i=n.attr("data-desc")||"",s=n.attr("data-gl")||"";if(!a||t=="0"||i===""&&s==="")r.html("");else{var o='<div class="mh-rili-holiday">[holidayDetail][holidaySug]</div>';i&&(i="<p>"+i+"</p>"),s&&(s="<p><span>\u4f11\u5047\u653b\u7565\uff1a</span>"+s+"</p>"),o=o.replace("[holidayDetail]",i).replace("[holidaySug]",s),r.html(o)}}),window.OB=window.OB||{},window.OB.RiLi=window.OB.RiLi||{},window.OB.RiLi.rootSelector="#mohe-rili ",window.OB.RiLi.CallBack={afterInit:p,holiday:c}})


_loader.remove && _loader.remove("rili-widget");
_loader.add("rili-widget", "/static/js/wnl.js");//上述JS文件们已让我压缩成wnl.js
_loader.use("jquery, rili-widget", function(){

  var RiLi = window.OB.RiLi;

  var gMsg = RiLi.msg_config,
    dispatcher = RiLi.Dispatcher,
    mediator = RiLi.mediator;

  var root = window.OB.RiLi.rootSelector || '';

  var timeData = new RiLi.AppData('api.hao.360.cn:rili'),
    gap = timeData.get('timeOffset'),
    dt = new Date(new Date() - (gap || 0));

  RiLi.action = "default";

  var $detail = $(root+'.mh-almanac .mh-almanac-main');
  $detail.dayDetail(dt);

  RiLi.today = dt;

  var $wbc = $(root+'.mh-calendar'); 

  mediator.subscribe(gMsg.type.actionfestival , function (d){
    var holi = RiLi.dateFestival,
      val = d.val ? decodeURIComponent(d.val) : "",
      holiHash = {},
      el,
      node = {};

    for (var i = 0 ; i < holi.length ; ++i){
      el = holi[i];
      el = $.trim(el).split("||");
      if (el.length == 2){
        node = {};
        node.year = el[0].substr(0 , 4);
        node.month = el[0].substr(4 , 2);
        node.day = el[0].substr(6 , 2);
        holiHash[el[1]] = node;
      }
    };

    RiLi.action = "festival";
    
    if (holiHash[val]){
      node.year = holiHash[val].year;
      node.month = holiHash[val].month;
      node.day = holiHash[val].day;

      RiLi.needDay = new Date(parseInt(node.year , 10) , parseInt(node.month ,10) - 1 , node.day);
      $wbc.webCalendar({
        time : new Date(parseInt(node.year , 10) , parseInt(node.month ,10) - 1 , node.day),
        onselect: function(d, l){
          $detail.dayDetail('init', d , l);
        }
      }); 
    }
    else{
      RiLi.action = "default";
    }
  }); 

  mediator.subscribe(gMsg.type.actionquery , function (d){
    var strDate;

    if (!d.year || d.year > 2100 || d.year < 1901){
      RiLi.action = "default";
      return 0;
    }
    
    d.month = parseInt(d.month , 10);

    if (d.month &&  (d.month > 12 || d.month < 1)){
      RiLi.action = "default";
      return 0;
    }

    if (!d.month){
      d.month = 1 ;
    }
    
    d.day = parseInt(d.day , 10);

    if (!d.day){
      d.day = 1;
    } 

    RiLi.action = "query";      
    RiLi.needDay = new Date(parseInt(d.year , 10) , parseInt(d.month ,10) - 1 , d.day);

    $wbc.webCalendar({
      time : new Date(parseInt(d.year , 10) , parseInt(d.month ,10) - 1 , d.day),
      onselect: function(d, l){
        $detail.dayDetail('init', d , l);
      }
    }); 
  });

  mediator.subscribe(gMsg.type.actiongoupiao, function (d){
    RiLi.action = "goupiao";
    $wbc.webCalendar({
      time : dt,
      onselect: function(d, l){
        $detail.dayDetail('init', d , l);
      }
    }); 
     
  });

  mediator.subscribe(gMsg.type.actiondefault , function (d){
    RiLi.needDay = dt;
    $wbc.webCalendar({
      time : dt,
      onselect: function(d, l){
        $detail.dayDetail('init', d , l);
      }
    }); 
  });    

  dispatcher.dispatch();

  mediator.subscribe(gMsg.type.dch , function (d){
    // if (RiLi.needDay){
    //  $wbc.webCalendar("initTime" , RiLi.needDay);
    // }
    // else{
    //  $wbc.webCalendar("initTime" , RiLi.today);
    // }
    $wbc.webCalendar("initTime" , RiLi.needDay||RiLi.today);
  });   
  
  mediator.publish(gMsg.type.dch ,  dt);

  var nowDate = (new Date()).getTime() ;

  /* 时间矫正 */
  RiLi.TimeSVC.getTime(function(d){
    var trueTime = d.getTime();
    var timeData = new RiLi.AppData('api.hao.360.cn:rili') , isFirst = true;

    if(Math.abs(nowDate - trueTime) > 300000){
      timeData.set('timeOffset', nowDate - trueTime);
    }
    else {
      timeData.remove('timeOffset');
    }

    if (typeof gap == undefined || !isFirst){
      RiLi.today = d;
      mediator.publish(gMsg.type.dch , d);
    }

    isFirst = false;
  });

  //日历初始完后的回调
  if(typeof RiLi.CallBack.afterInit === "function"){
    RiLi.CallBack.afterInit();
  }

});
