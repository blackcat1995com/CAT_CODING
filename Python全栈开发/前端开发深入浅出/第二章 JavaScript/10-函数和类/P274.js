let buf = "";

const is_prime = (n) => {
	for(let i = 2;  i < n; i++){
    	if(n % i == 0)
        	return false;
    }
    
    return true;
}

process.stdin.on("readable", function(){
    let chunk = process.stdin.read();
    if(chunk) buf += chunk.toString();
});

process.stdin.on("end", function(){

	
    let n = parseInt(buf);
    
    for(let i = 2;  i <= n; i++){
    	if(is_prime(i) && is_prime(n - i)){
        	console.log(`${n} = ${i} + ${n-i}`);
            break;
        }
    }
    // console.log(n); 
});