// 1 2 3 4 5 6

// 6
// 6 4 2 1 3 5

const { stdout } = require('process');
const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: stdout
});

let a, b;
// "2 3"
// ['2', '3']
// [2, 3]
let ret;
rl.on('line', line => {
    // [a, b] = line.split(' ').map(x => {
    //     return parseInt(x);
    // })
    ret = line.split(' ');

    rl.close();
});

rl.on('close', () => {
    // console.log(a + b);
    console.log(ret);
});

