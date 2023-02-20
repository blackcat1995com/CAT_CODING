let buf = "";

process.stdin.on("readable", function(){
	let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
	let lines = buf.split("\n");
    let [x1, y1] = lines[0].split(" ").map(x => { return parseInt(x); });
    let [x2, y2] = lines[1].split(" ").map(x => { return parseInt(x); });
    
    let res = Math.sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    console.log(res.toFixed(3));
});