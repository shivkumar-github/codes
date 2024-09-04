// // in javasrcipt we can also create arrays containing different type of data types
// let marks = [90,92, 93,99,45]; // note that in js we write [] instead of {}
// console.log(marks.length);
// console.log(typeof(marks)); // arrays are objects where key value is present but instead of key we use index in array
// console.log(marks[0]);
// console.log(marks[3]);
// console.log(marks[100]);
// console.log(marks);
// // arrays are mutable in js but strings are not
// // i.e. we can change value at certain index in arrays

// let heroes = ["ironmane", "thor", "hulk", "shaktiman", "spiderman", "antman"]

// for (let hero of heroes) {
//     console.log(hero);
// }

// // for(let i = 0; i < heroes.length;i++){
// //     console.log(heroes[i]);
// // }


// // practice question
// // calculate average of student marks [85,97,44,37,76,60]
// let marks = [85,97,44,37,76,60];
// let sum = 0;
// for (const itr of marks) {
//         sum += itr;
// }
// console.log(`the answer is ${sum/marks.length}`);


// practice question 2 
// array of 5 items prices [250,645,300,900,50] all have 10% off on them. change the array to store the final prices
// let prices = [250, 645, 300, 900, 50];
// for (let itr = 0; itr < prices.length; itr++) {
//     prices[itr] = 0.9 * prices[itr];
//     console.log(prices[itr]);
// }


// arrays in js
// array methods
// there are two types of methods one which change the orignal array and some create new one without changing orignal

// // 1. array.push()
// let food = ["potato", "apple", "litchi", "tomato"];
// food.push("chips", "paneer","pani-puri"); // changes in orignal array and pushes at the end
// console.log(food);



// // array.pop()
// let deleted = food.pop(); // deletes and returns that item // changes are done in orignal array
// console.log(food);
// console.log(deleted);

// // array.toString() // without modifying orignal array converts and store it to a new string
// console.log(food.toString());

// // array1.concat(array2) // concates the two arrays and returns the new array without changing the orignal
// let marvels = ["ironman", "spiderman", "thor", "captainamerica", "drstrange", "black-panther"];
// let DC = ["superman", "batman", "wanderwomen"];
// let indianheros = ["shaktiman", "krish"];

// let heros = marvels.concat(DC,indianheros);
// console.log(heros);


// // array.unshift(elementToAdd) // adds the element at start
// marvels.unshift("deadpool");
// console.log(marvels);

// // array.shift() // deletes from start and returns
// let deleted = marvels.shift();
// console.log(deleted);
// console.log(marvels);

// array.slice(start-index,end-index) // doesn't changes orignal array but returns a new sliced array // ending index not include
// console.log(marvels.slice(1,3));
// console.log(marvels.slice(2));

// array.splice(start-index,delete-count,toAddE1,toAddE2,....) // delete-count tells how many elements to delete (also can be set to 0) from start index and then the new elements you want to add after that index
// it changes the orignal array and can be used to modify, add and delete elements from array
let array = [1,2,101,102,5,6,7];
// array.splice(2,2,101,102);
// console.log(array);

// // element add
// array.splice(2,0,101,102);
// console.log(array);

// // delete
// array.splice(3,1);

// replace 
array.splice(3,1,10); //replaces element at three
console.log(array);

// when no of items are not passed it works as slice but deletes all elements after index from orignal array
// and also return the deleted array

// console.log(array.splice(4));
// console.log(array);