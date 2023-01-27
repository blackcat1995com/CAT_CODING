let buf = "";

process.stdin.on("readable", function () {
    let chunk = process.stdin.read();
    if (chunk) buf += chunk.toString();
});

let path = [];
let st = [];

let dfs = (u, n) => {
    if (u === n) console.log(path.join(' '));
    else {
        for (let i = 1; i <= n; i++) {
            if (!st[i]) {
                st[i] = true;
                path.push(i);
                dfs(u + 1, n);
                path.pop();
                st[i] = undefined;
            }
        }
    }
}

process.stdin.on('end', function () {
    let n = parseInt(buf);
    dfs(0, n);
});
