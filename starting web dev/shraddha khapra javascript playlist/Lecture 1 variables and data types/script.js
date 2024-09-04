// // remember javascript has an ASI(auto semicolon insert features) which inserts semicolon after each statment automatically
function add(a, b) {
    return
     a + b;
}

console.log(add(2, 3)); // Output: undefined






// // console.log("helo")
// // x = null; // khali hai
// // console.log(x);
// // y = undefined; // pata nahi kya hai
// // console.log(y);
// // z = true;
// // console.log(z);
// // // javascript is a dynamic typed language unlike cpp i.e. we dont need to define the type of variable
// // name = "Tony stark";
// // console.log(name);



// // variables

// {
//     var a = 23; // a global scope variable // variable can be redeclared and updated
//     // can not redeclare many times a single variable hence using of var is bad practice
// }
// // console.log(a);



// {
//     // let name = "shivkumar";
//     // console.log(name);
// } // variable can not be redeclared but can be updated // a block scope variable

// // const b = 34;// variable can not be redeclared or updtated // a block scope variable

// // let var1;
// // console.log(var1);
// // will give undefined 

// // const var2;
// // will give error if value not assigned to them







// // data types
// // 7 primitive data types (predefined) // non primitive data types-  objects
// // // number string boolean undefined null bigint  symbol
// // let x = null;
// // // console.log(typeof(x));

// // // non primitive data types // arrays and functions
// // // how to define object 
// // const student = { // keys of a const object can be changed 
// //     name : "shivkumar",
// //     marks : 90,
// //     age : 23,
// // }
// // console.log(typeof(student));
// // console.log(student.name);
// // console.log(student.age);
// // console.log(student.marks);
// // console.log(student["age"]);

// // student["age"] = student["age"] + 1;
// // console.log(student.age);





// // HW Q1 create a const object called "product" to store information about a pen on amazon
// const product = {
//     prod_name : "Parker Jotter Standard CT Ball Pen",
//     prod_color : "Black",
//     deal_feature : "deal of the day",
//     price : 270,
//     discount_string : "M.R.P. : Rs. 285 (5% off)",
//     rating : 4,
//     number_of_ratings : 7002,
// }

// console.log(product.prod_name);

// // strings
// // console.log("abcd" + 2); // abcd2
// console.log("abcd" + a); // abcd2



// // lets practice 
// // create a object called profile to show information on profile of a linkdin
// const profile = {
//     account_name : "shivkumar",
//     post : 195,
//     isFollow : true,
//     holder_name : "shivkumar rajmane",
//     followers : 195000,
//     followings : 30,
//     tag  : "passionate coder",
//     bio : "A student pursuing btech in vjti mumbai with curious mind"

// }