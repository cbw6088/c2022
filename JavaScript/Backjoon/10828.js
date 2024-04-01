// const fs = require('fs');
// //const filename = "JavaScript/Backjoon/input.txt"
// //const valueData = fs.readFileSync(filename, "utf8").toString().trim().split("\n");
// const valueData = fs.readFileSync('/dev/stdin','utf-8').toString().trim().split('\n')

// const cnt = parseInt(valueData[0]);
// const stack = [];

// for (let i = 1; i <= cnt; i++) {
//     const parts = valueData[i].split(' ');
//     if (parts[0] === 'push') {
//         const num = valueData[i].split(' ')[1];
//         stack.push(num);
//     }
//     else if(parts[0] == 'pop'){
//         if(stack.length === 0) console.log('-1');
//         else console.log(stack.pop());
//     }
//     else if(parts[0] == 'top'){
//         if(stack.length === 0) console.log('-1');
//         else console.log(stack[stack.length-1]);
//     }
//     else if(parts[0] == 'empty'){
//         if(stack.length == 0) console.log('1');
//         else console.log('0');
//     }
//     else if(parts[0] == 'size'){
//         console.log(stack.length);
//     }
// }

  