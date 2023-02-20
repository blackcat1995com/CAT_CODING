let buf = "";

process.stdin.on("readable", function(){
	let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
    
    let lines = buf.split("\n");
    
    let n = parseInt(lines[0]);
    
    let cnt = 0, maxv = 0;
    for(let i = 1;  i <= n; i++){
    	let [a, b] = lines[i].split(" ").map(x => {return parseInt(x)});
        // console.log(a, b);
        if(a >= 90 && a <= 140 && b >= 60 && b <= 90) cnt++;
        else{
        	maxv = Math.max(maxv, cnt);
            cnt = 0;
        }
    }
    
    console.log(Math.max(maxv, cnt));
});