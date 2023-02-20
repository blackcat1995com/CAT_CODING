let buf = "";

process.stdin.on("readable", function(){
	let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
	let a = buf.split(" ");
    let w = parseInt(a[0]);
    let flag = a[1];
    
    // console.log(w, typeof(w));
    // console.log(flag, typeof(flag));
    
    let res = 0;
    
    if(w <= 1000) res += 8;
    else{
    	res += 8 + Math.floor((w-1000)/500)*4;
        if((w-1000) % 500) res += 4;
        // console.log(res);
    }
    
    if(flag === "y") res += 5;
    console.log(res);
});