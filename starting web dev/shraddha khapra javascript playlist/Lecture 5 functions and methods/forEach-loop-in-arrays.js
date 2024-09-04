// it is function which has become a method after binding it with array but not strings
/* in javascript we can also take functions as an parameter 
function abc(){
    console.log("hello);
}

function myFunc(abc){
    return abc;
}

A callback is a function passed as an agruement to another function (here abc)
*/

let arr = [1, 2, 3, 4, 5];

// arr.forEach(function printVal(val) { // for each will pass each element of array to the call back function (here printVal) 
//     console.log(val);
// });

// also can be written as (using arrow function)
arr.forEach((val, idx, arr) => {
    console.log(val, idx, arr);
});
// // parameter that can be passed to forEach() function
// val = value of each Element
// idx = index of each Element
// arr = the array itself

// **** HOM(higher order methods) or HOF(higher order methods)
//  the function which take another functions as arguement 