function show_ability(data){
    radarChart.init(document.querySelector("#radar"), {
        data: data,
        config: {
            scale: 1.5,
            showTooltip: true,
            dataFill: {
                fillStyle: "rgba(24, 236, 111, .4)"
            },
            bg: {
                layer: 4,
                evenFillStyle: "#828282",
                oddFillStyle: "#828282",
                evenStrokeStyle: "#ccc",
                oddStrokeStyle: "#ccc"
            },
            dataCircle: {
                r: 15,
                strokeStyle: "transparent",
                fillStyle: "transparent",
                lineWidth: 0.5
            },
            dataLine: {
                strokeStyle: "#18ec6f",
                lineWidth: 2
            },
            font: {
                fontColor: "#eee"
            }
        }
    });
}
