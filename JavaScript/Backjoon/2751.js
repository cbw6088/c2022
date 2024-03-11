const fs = require('fs');
//const filename = "JavaScript/Backjoon/input.txt"
//const valueData = fs.readFileSync(filename, "utf8").toString().split("\n");
const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

const arrayLength = parseInt(valueData[0]);
valueData.shift();
let answer = [];
answer = valueData.sort((a,b) => a-b);
console.log(answer.join('\n'));
