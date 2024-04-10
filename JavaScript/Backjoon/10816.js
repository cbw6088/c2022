const fs = require('fs');
const filename = "JavaScript/Backjoon/input.txt"
const valueData = fs.readFileSync(filename, "utf8").toString().trim().split("\n");
// const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

const N = parseInt(valueData[0]);
const M = parseInt(valueData[2]);

var first = [N];
var second = [M];
for(i = 0; i < N; i++) first[i] = 0;
for(i = 0; i < M; i++) second[i] = 0;

first = valueData[1].split(' ');
second = valueData[3].split(' ');

var dict = {};

for(i = 0; i < N; i++){
    if(first[i] in dict) dict[first[i]] += 1;
    else dict[first[i]] = 1;
}

var result = [M];
for(i = 0; i < M; i++){
    if(second[i] in dict) result[i] = dict[second[i]];
    else result[i] = 0;
}

for(i = 0; i < M; i++) process.stdout.write(result[i] + " "); 