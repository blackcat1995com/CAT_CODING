let buf = "";

process.stdin.on("readable", function(){
    let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
  
  	let a = buf.split("\n").map(x => {return parseInt(x);});
    
    let n = a[0];
    
    let sum = 0;
    
    for(let i = 1; i <= n; i++)
    	sum += a[i];
        
    console.log(sum + ' ' + (sum/n).toFixed(5));
});