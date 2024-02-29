const fs = require('fs');
filename = "JavaScript/Backjoon/input.txt"
const data = fs.readFileSync(filename, "utf8").toString().split(" ");
//const data = fs.readFileSync(0, "utf8").toString().split(" ");
const a = parseInt(data[0]);
const b = parseInt(data[1]);
if(a > b) console.log('>')
else if(a == b) console.log('==')
else if(a < b) console.log('<') 