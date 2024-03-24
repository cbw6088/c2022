const fs = require('fs');
const filename = "JavaScript/Backjoon/input.txt"
const valueData = fs.readFileSync(filename, "utf8").toString().trim().split("\n");
// const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

const cnt = parseInt(valueData[0]);
const stack = []

for (let i = 1; i <= cnt; i++) {
    for(let j = 0; j < valueData[i].length; j++){
        if(valueData[i][j] == '('){
            stack.push(valueData[i][j]);
        }
        else if(valueData[i][j] == ')'){
            if(stack[stack.length - 1] != '('){
                console.log('NO');
                console.log(i);
                break;
            }
            else stack.pop();
        }
    }
    if(stack[stack.length-1] == 0) console.log('YES');
    console.log(stack);
}