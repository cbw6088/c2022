const fs = require('fs');
//const filename = "JavaScript/Backjoon/input.txt"
//const valueData = fs.readFileSync(filename, "utf8").toString().split("\n");
const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

var target = parseInt(valueData);
var cnt = 1;
var addData = 1;
var mulData = 1;
var key = 0;

if(target == 1) console.log('1');
else{
    while(target > key){
        key = addData + (6 * mulData);
        addData = key;
        mulData += 1;
        cnt++;
    }
    console.log(cnt);
}