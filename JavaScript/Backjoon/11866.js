const fs = require('fs');
//const filename = "JavaScript/Backjoon/input.txt"
//const valueData = fs.readFileSync(filename, "utf8").toString().trim().split("\n");
const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')
var N = 0
var K = 0
const data = valueData.shift().split(" ");
N = parseInt(data[0])
K = parseInt(data[1])


// console.log(N);
// console.log(K);
var list = [];
for(i = 0; i < N; i++){
    list.push(i+1);
}

var answer = []
while(list.length != 0){
    for(i = 0; i < K-1; i++){
        list.push(list.shift())
    }
    answer.push(list.shift());
}
process.stdout.write('<');
while(answer.length != 0){
    if(answer.length == 1){
        process.stdout.write(answer.shift() + ">");      
        break;  
    }
    process.stdout.write(answer.shift() + ", ");    
}