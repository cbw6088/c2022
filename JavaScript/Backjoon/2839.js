const fs = require('fs');
//const filename = "JavaScript/Backjoon/input.txt"
//const valueData = fs.readFileSync(filename, "utf8").toString().split("\n");
const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')


const MAXSIZE = 1000000000;
var n = valueData;
let dp = new Array(5001).fill(MAXSIZE);

function dynamic(n){
    if(n < 0) return MAXSIZE;
    if(dp[n] != MAXSIZE) return dp[n];
    else{
        dp[n] = Math.min(dynamic(n-5), dynamic(n-3)) + 1;
        return dp[n];
    }
}
dp[3] = 1, dp[5] = 1;
var result = dynamic(n);
if(result >= MAXSIZE) console.log(-1);
else console.log(result);