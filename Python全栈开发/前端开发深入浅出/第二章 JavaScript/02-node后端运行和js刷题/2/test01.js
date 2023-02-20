let buf = "";

process.stdin.on("readable", function(){
	let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
	console.log(buf);
    console.log(typeof(buf));
    
    let [a, b, c] = buf.split(" ").map(x => {return parseInt(x)});
    console.log(typeof(a), b, c);
});