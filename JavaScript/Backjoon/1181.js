const fs = require('fs');
// inputFile = "JavaScript/Backjoon/input.txt"
// var valueData = fs.readFileSync(inputFile, 'utf8').toString().split("\n");

var valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')
valueData.shift()

var words = Array.from(new Set(valueData));

words = words.sort(function compare(a, b) {
    if(a.length == b.length) {
        return a.localeCompare(b);
    }
    return a.length - b.length;
}).join('\n');

console.log(words)