const fs = require('fs');
// const filename = "JavaScript/Backjoon/input.txt"
// const valueData = fs.readFileSync(filename, "utf8").toString().trim().split("\n");
const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

const cnt = parseInt(valueData[0]);

for (let i = 1; i <= cnt; i++) {
    var result = 'YES'
    const stack = []
    for(let j = 0; j < valueData[i].length; j++){
        if(valueData[i][j] == '('){
            stack.push(valueData[i][j]);
        }
        else if(valueData[i][j] == ')'){
            if(!stack.pop()){
                result = 'NO';
                break;
            }
        }
    }
    if(stack.length != 0) result = 'NO';
    console.log(result);
}