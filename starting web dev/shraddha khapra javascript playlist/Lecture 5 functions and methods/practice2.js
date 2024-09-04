// for a given array of numbers, print the square of each value using forEach function

function calcSquare(val){
    console.log(val*val);
};

let arr = [1, 2, 3, 4];
// arr.forEach((val) => {
//     console.log(val * val);
// });

arr.forEach(calcSquare);