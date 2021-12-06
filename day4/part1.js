const { checkPrime } = require('crypto');

fs = require('fs');

console.log("hello");

function transform(array){
    array.forEach(function(item){
        item.forEach(function(item1){
            for(var i=0; i<=4; i++){
                item1[i] = {"num" : item1[i], "marked" : false}
            }
        })
    })
    return array;
}

function mark(array, num){
    array.forEach(function(item){
        item.forEach(function(item1){
            for(var i = 0; i<=4; i++){
                if(item1[i].num == num){
                    item1[i].marked = true;
                }
            }
        })
    })
    return array;
}
function check(array){
    for(var i = 0; i<=array.length-1; i++){
        //console.log(array[i]);
        for(var j = 0; j<=array[i].length-1; j++){
            var m = 0;
            var count = 0;
            for(var k=0; k<=4; k++){
                if(array[i][j][k].marked == true){
                    m++;
                    count += parseInt(array[i][j][k].num)
                }
            }
            if(m == 5) {
                var cc = 0;
                for(var e = 0; e<=4; e++){
                    for(var b=0; b<=4; b++){
                        if(array[i][e][b].marked == false){
                            cc += parseInt(array[i][e][b].num);
                        }
                    }
                }
                return cc;
            }
        }
    }
    for(var i = 0; i<=array.length-1; i++){
        //console.log(array[i]);
        for(var j = 0; j<=array[i].length-1; j++){
            var m = 0;
            var count = 0;
            for(var k=0; k<=4; k++){
                if(array[i][k][j].marked == true){
                    m++;
                    count += parseInt(array[i][k][j].num)
                }
            }
            if(m == 5){
                var cc = 0;
                for(var c = 0; c<=4; c++){
                    for(var d=0; d<=4; d++){
                        if(array[i][d][c].marked == false){
                            cc += parseInt(array[i][d][c].num);
                        }
                    }
                }
                return cc;
            }
        }
    }
    return false;
}

fs.readFile("input", 'utf8', function(err,data){
    if(!err){
        //console.log(data);
        var splitted = data.split('\n');
        //console.log(splitted);
        numbers = splitted[0];
        var numbers = [];
        let reg = new RegExp(/(\d{2})|(\d{1})/g);
        numbers = splitted[0].match(reg);
        //console.log(numbers);
        var matrix = []
        var array = []
        for(var i = 2; i<= splitted.length-1; i++){
            //console.log(i);
            if(splitted[i] != ''){
                //console.log(splitted[i]);
                matrix.push(splitted[i].match(reg));
            }else{
                array.push(matrix);
                matrix = [];
            }
        }
        console.log(numbers);
        console.log(array);

        array = transform(array);
        //console.log(JSON.stringify(array));

        var res;
        for(var h = 0; h<=numbers.length-1; h++){
            array = mark(array, numbers[h]);
            var yes = check(array);
            res = yes * numbers[h]
            if(yes != false) break;
        }
        console.log("result: " + res);
        //console.log(JSON.stringify(array));
    }
    return console.log(err);
})
