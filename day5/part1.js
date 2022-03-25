fs = require('fs');

console.log("hello");

fs.readFile("input", 'utf8', function(err,data){
    if(!err){
        console.log(data);
        var splitted = data.split('\n')
        console.log(splitted);
        let reg = new RegExp(/(\d{3})|(\d{2})|(\d{1})/g);
        var array = []
        splitted.forEach(element => {
            //console.log(element.match(reg));
            array.push(element.match(reg))
        });
        console.log(array);
        
        var matrix = []
        for (var i = 0; i < 1000; i++) {
            var vv = new Array(1000).fill(0)
            matrix.push(vv);
        }          
        
        console.log(matrix);
        array.forEach(elem => {
            if(elem[0] == elem [2]){
                console.log("x are equal");
                console.log(elem);
                if(elem[1] < elem[3]){
                    for(var i=elem[1]; i<=elem[3]; i++){
                        matrix[elem[0]][i]++
                        //console.log(matrix[i][elem[0]]);
                        console.log("case ("+i+","+elem[0]+ ") is filled");
                    }
                }else{
                    for(var i=elem[1]; i>=elem[3]; i--){
                        matrix[elem[0]][i]++
                        //console.log(matrix[i][elem[0]]);
                        console.log("case ("+i+","+elem[0]+ ") is filled");
                    }
                }
            }else{
                if(elem[1] == elem[3]){
                    console.log("y are equal");
                    console.log(elem);
                    if(elem[0] < elem[2]){
                        for(var i=elem[0]; i<=elem[2]; i++){
                            matrix[i][elem[1]]++
                            //console.log(matrix[elem[0]][i]);
                            console.log("case ("+i+","+elem[1]+ ") is filled");
                        }
                    }else{
                        for(var i=elem[0]; i>=elem[2]; i--){
                            matrix[i][elem[1]]++
                            console.log("case ("+i+","+elem[1]+ ") is filled");
                        }
                    }
                }
            }
        })
        //console.log(matrix)
        var count = 0;
        matrix.forEach(elem => {
            for(var t = 0; t< 1000; t++){
                if(elem[t] > 1){
                    count++
                }
            }
        })

        console.log("RESULT: " + count);
    }else{
        return console.log(err);
    }
})