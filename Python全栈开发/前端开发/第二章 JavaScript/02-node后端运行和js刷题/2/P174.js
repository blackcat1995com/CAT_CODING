let buf = "";

process.stdin.on("readable", function(){
    let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){
   let n = parseInt(buf);
   let res = 0, i = 1;
   
   while(i <= n){
   		res += i;
        i ++;
   }
   /*
   for(let i = 1;  i <= n; i++)
   		res += i;
   */
        
   console.log(res);
});