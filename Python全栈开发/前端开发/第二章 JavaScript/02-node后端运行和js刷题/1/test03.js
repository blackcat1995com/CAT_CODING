const { stdout } = require('process');
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: stdout
});

let a, b;

rl.on('line', line => {
    [a, b] = line.split(' ').map(x => {
        return parseInt(x);
    })

    rl.close();
});

rl.on('close', () => {
    
    let t = a;
    a = b;
    b = t;
    // console.log(b, a);
    console.log(a, b);
});

