const fs = require('fs');
const filename = "JavaScript/Backjoon/input.txt"
const valueData = fs.readFileSync(filename, "utf8").toString().trim().split("\n");
//const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

const cnt = parseInt(valueData[0]);

var arr = [cnt];
var idx = 0;

for(let i = 1; i <= cnt; i++){
    arr[idx] = parseInt(valueData[i]);
    //console.log(arr[idx]);
    if(arr[idx] == 0){
        arr[--idx] = 0;
    }
    else idx++;
}

var result = 0;
for(let i = 0; i < idx; i++){
    result += arr[i];
}

console.log(result);

