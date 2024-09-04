// arrow functions
// mostly used for small processes
// let function_name = (param1, param2..) => {// note that the arrow is different from cpp wala arrow
// do some work
// }

// actual arrow function but needs to be stored in a let variable function_name which will become a function after storing
// (param1, param2..) => {
// do some work
// }

let arrowSum = (a, b) => {
    console.log(a + b);
};
let arrowMult = (a,b) => {
    console.log(a*b);
}

arrowMult(4,5);
arrowSum(4,5);

// we can also assign normal value to arrow function variable
arrowSum = 5;
console.log(arrowSum);

