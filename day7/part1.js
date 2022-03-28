var fs = require('fs');
var array = fs.readFileSync('input').toString().split(",");

console.log(array);
console.log("Length: " + array.length);

let max = 0
for(let i =0; i<=array.length-1; i++){
    if(parseInt(array[i]) > max){
        max = array[i]
    }
}
console.log("MAX: " + max);

var allCosts = [];

for(let u = 0; u<=max; u++){
    var score = 0;
    for(let i = 0; i<=array.length-1; i++){
        score += Math.abs((parseInt(array[i]) - u));
    }
    allCosts[u] = score;
    console.log("total fuel for pos: " + u + " is " + score);
}

console.log(allCosts);

var min = allCosts[0];
for(let g = 1; g<=allCosts.length-1; g++){
    if(parseInt(allCosts[g]) < min){
        min = allCosts[g]
    }
}

console.log("THE RESULT: " + min);