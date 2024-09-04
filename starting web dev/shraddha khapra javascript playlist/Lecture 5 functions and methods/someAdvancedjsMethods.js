// // array.map() similar to forEach but returns a new array
// // syntax arr.map(callbackFnx(value,index,array))
// /*
// let newArr = arr.map((val) => {
//     return val*2;
// })
// */

// let nums = [67,52,39];

// // printing all the values 
// nums.map((val) => {
//     console.log(val);
// });

// let newArr = nums.map((val) => {
//     return val;
// });

// newArr.map((value) => {
//     console.log(value);
// });

// array.filter() method =>> createes a new array with elements that satisfies the filter or condition in filter
// let arr = [1,2,3,4,5,6,7];

// // even elements
// let evenArr = arr.filter((value)=> {
//     return value %2 ===0; // jo jo elements ye condition satisfy karte hai unko new array mein pass karo
// });

// console.log(evenArr);

// array.reduce() method =>>> it performs some operations & reduces the array to a single value and returns that single values
//  fir example for calculating sum of elements of array 
const array = [1, 2, 3, 4, 5];

const sumWithInitial = array.reduce((res, curr) => {//initially res = 2(arr[1]) & curr = 1(arr[0])
    return res + curr;//this value will be stored into res and then again passed for next repetation
});

console.log(sumWithInitial);
// expected output 15

const largest = array.reduce((prev, curr) => {
    if (prev > curr)
        return prev;
    return curr;
})

console.log(largest);










// practice problem
// Q1 filter out the marks of the students that scored 90+
let marks = [34, 67, 87, 90, 91, 93];

let newArr = marks.filter((val) => {
    return val > 90;
});

console.log(newArr);


// Q2 take nmumber n from user , create an array containing elements from 1 to n  and then use reduce method to 
// calculate sum of all numbers in array
// to calculate product of all numbers in array 

let n = prompt("enter number ");

let nums = [];
for (let i = 1; i <= n; i++) {
    nums.push(i);
}

const sum = nums.reduce((prev, curr) => {
    return prev + curr;
});

const product = nums.reduce((prev, curr) => {
    return prev * curr;
});

alert("sum = " + sum);
alert("product = " + product); // alert takes only one argument and that is message which is to be shownhence we can not give , like in console
// alert stops the working of the webpage for the period it pop ups