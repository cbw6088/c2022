const fs = require('fs');
//let filename = "JavaScript/Backjoon/input.txt"
//let valueData = fs.readFileSync(filename, "utf8").toString().split("\n");
const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

const arrayLength = parseInt(valueData[0]);
const numbers = valueData[1].split(" ").map(Number);

const maxValue = Math.max(...numbers);

// console.log(numbers);
// console.log(maxValue);

let answer = 0;
for(i = 0; i < arrayLength; i++){
    answer += numbers[i] / maxValue * 100;
}

console.log(answer/arrayLength);