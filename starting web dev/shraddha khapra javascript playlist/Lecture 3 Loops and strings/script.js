// // // // // // // some different loops 
// // // // // // // for-of loop
// // // // // // // helps to apply loop on some special data types like string and arrays
// // // // // // let str = "shivkumar";
// // // // // // for(let i of str){ // auto updation
// // // // // //     console.log(i);
// // // // // // }



// // // // // // // for-in loops 
// // // // // // // can be used for objects and arrays
// // // // // // let students = {
// // // // // //     name : "shivkumar",
// // // // // //     age : 18,
// // // // // //     cgpa : 7,
// // // // // //     isPass : false ,
// // // // // // }

// // // // // // for (let key in students){
// // // // // //     console.log("key = ", key , "value = ", students["key"]);
// // // // // // }

// // // // // // create a game where you create a random nubmer and keep asking the user to guess it until he guesses it right
// // // // // let a =23;
// // // // // let b = prompt("enter your guess");
// // // // // while(a !=b){ // prompt mein number strings ke form mein ate isliye !==  nahi use kar sakte
// // // // //     b = prompt("enter your guess");
// // // // // }
// // // // // console.log("you have entered the correct nubmer")





// // // // // // strings
// // // // // let str = "a";
// // // // // console.log(typeof(str));


// // // // // template literals
// // // // // ${}
// // // // let obj = {
// // // //     item: "pen",
// // // //     price: 10,
// // // // };

// // // // let output = `the cost of ${obj.item} is ${obj.price} rupees`; // string interpolation // note that the sign used is not single quote but the tickle (`) sign
// // // // // the number is printed as string in template literals
// // // // console.log(output);
// // // // // instead of 
// // // // console.log('the cost of' , obj.item, ' is ' ,obj.price ,' rupees');

// // // console.log(`this is a template literal ${1 + 2 + 3}`);
// // // console.log("hi i am shivkumar \n and I am a student.");
// // // console.log("hi i am shivkumar \t and I am a student.");
// // // // \ and t is counted as a single character (for all escape characters)
// // // let str = "hi\nhello";// 8
// // // console.log(str.length);


// // // // string methods 
// // // let str1 = "shivkumar";
// // // // str.toUpperCase() // returns new string 
// // // // strings of javascript are non mutable (i.e. can not be changed)
// // // console.log(str1.toUpperCase());
// // // console.log(str1.toLowerCase());
// // // // str.toLowerCase() // returns new string

// // // // str.trim() // removes white spaces at end and start of string and spaces between words remain intact
// // // let newstr  = "     shivkumar       hello      ";
// // // console.log(newstr.trim()); 


// // // str.slice(start,end?) // returns part of string // but end is not inlcuded
// // let numbers = "0123456";
// // console.log(numbers.slice(1,6)) // 12345
// // console.log(numbers.slice(1)) // 123456 // by default gives whole string after start


// // str1.concat(str2) function // returns new string with str1 + str2
// let str1 = "hello hello ";
// let str2 = "brother";

// console.log(str1.concat(str2));
// console.log(str1 + str2);

// // str.replace(searchVal,newVal); // replaces only 1 st value
// console.log(str1.replace('h','y')); // str1 wont be modified
// console.log(str1);
// console.log(str1.replaceAll("h","y"));
// // str.charAt(0)
// // returns the character at i th index
// console.log(str1.charAt(2));
// str1[0]="k";// strings are immutable in javascript
// console.log(str1);

// practice question 
// prompt the user to enter their full name.generate a username for them based on the input 
// . start username with @ , followed by their full name and ending with the fullname length
// username = "@shradhakhapra13" when name of user shradha khapra

let full_name = prompt("Enter your full name without spaces");
let username = `@${full_name}${full_name.length}`;
let username2 = "@" + full_name + full_name.length;
console.log(username);