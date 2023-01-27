let buf = '';

let n = 0;
process.stdin.on('readable', () => {
	let t = process.stdin.read();
    if(t) buf += t.toString();
    n++;

    if(n === 2)
        process.stdin.emit('end'); 
});

process.stdin.on('end', () => {
	let [a, b] = buf.split(' ').map(x => {
    	return parseInt(x);
    });
    
    console.log(a + b);
});