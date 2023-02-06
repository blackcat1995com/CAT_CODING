var data1 = [];
var data2 = [];
var geoCoordMap = {};
var map_1 = echarts.init(document.getElementById('map_1'));

$(function() {
	$("#PM10").click(function() {
		data1 = []
		data2 = []
		$.get('/PM10', function(result) {
			for (var i = 0; i < result.length; i++) {
				info = result[i];
				d = {};
				d['name'] = info['city'];
				d['log'] = info['log'];
				d['lat'] = info['lat'];
				data1.push(d);
				f = {};
				f['name'] = info['city'];
				f['value'] = 100;
				f['number'] = info['PM10'];
				data2.push(f)
			}
			map_1_option = init_map_option(data2);
			map_1_option['series'][0]['name'] = 'PM10';
			show_data();
		});
	});
	$("#PM25").click(function() {
		data1 = []
		data2 = []
		$.get('/PM25', function(result) {
			for (var i = 0; i < result.length; i++) {
				info = result[i];
				d = {};
				d['name'] = info['city'];
				d['log'] = info['log'];
				d['lat'] = info['lat'];
				data1.push(d);
				f = {};
				f['name'] = info['city'];
				f['value'] = 100;
				f['number'] = info['PM25']
				data2.push(f)
			}
			map_1_option = init_map_option(data2)
			map_1_option['series'][0]['name'] = 'PM25';
			show_data();
		});
	});
	$("#O3").click(function() {
		data1 = []
		data2 = []
		$.get('/O3', function(result) {
			for (var i = 0; i < result.length; i++) {
				info = result[i];
				d = {};
				d['name'] = info['city'];
				d['log'] = info['log'];
				d['lat'] = info['lat'];
				data1.push(d);
				f = {};
				f['name'] = info['city'];
				f['value'] = 100;
				f['number'] = info['O3']
				data2.push(f)
			}
			map_1_option = init_map_option(data2)
			map_1_option['series'][0]['name'] = 'O3';
			show_data();
		});
	});
});

function aa() {

}

function init_map_option(data2) {
	var map_1_option = {
		title : {
			text : '全国主要城市空气质量',
			subtext : '全国主要城市空气质量',
			left : 'center',
			textStyle : {
				color : '#fff'
			}
		},
		tooltip : {
			trigger : 'item',
			formatter : function(params) {
				console.log(params)
				return params.seriesName + '<br><span style="display:inline-block;margin-right:5px;border-radius:10px;width:10px;height:10px;background-color:#f75749;"></span>' + params.name + ': ' + params.data.number;
			}
		},
		geo : {
			map : 'china',
			label : {
				emphasis : {
					show : false
				}
			},
			roam : false,
			itemStyle : {
				normal : {
					areaColor : '#d1d1d1',
					borderColor : '#111',
				},
				emphasis : {
					areaColor : '#d1d1d1'
				}
			}
		},
		series : [{
			name : 'pm2.5',
			type : 'scatter',
			coordinateSystem : 'geo',
			data : convertData(data2),
			symbolSize : function(val) {
				return val[2] / 10;
			},
			label : {
				normal : {
					formatter : '{b}',
					position : 'right',
					show : false
				},
				emphasis : {
					show : true
				}
			},
			itemStyle : {
				normal : {
					color : '#f75749'
				}
			}
		}]
	};
	return map_1_option;
}

var convertData = function(data) {
	var res = [];
	for (var i = 0; i < data.length; i++) {
		var geoCoord = geoCoordMap[data[i].name];
		if (geoCoord) {
			res.push({
				name : data[i].name,
				value : geoCoord.concat(data[i].value),
				number : data[i]['number']
			});
		}
	}
	return res;
};

function show_data() {
	for (var i = 0; i < data1.length; i++) {
		var citydetail = new Array();
		var name = data1[i].name;
		geoCoordMap[name] = citydetail;
		var lat = parseFloat(data1[i].lat);
		var log = parseFloat(data1[i].log);
		citydetail.push(log);
		citydetail.push(lat);
	}

	map_1_option.series[0].data = convertData(data2.sort(function(a, b) {
		return b.value - a.value;
	}))
	map_1.setOption(map_1_option);
}

map_1_option = init_map_option(data2)
show_data();

