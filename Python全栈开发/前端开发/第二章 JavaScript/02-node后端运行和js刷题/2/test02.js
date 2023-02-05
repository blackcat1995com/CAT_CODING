let buf = "";

process.stdin.on("readable", function(){
    let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
    let [a, b, c] = buf.split(" ").map(x => {return parseInt(x)});
   console.log((a + b) * c); 
});


// P109