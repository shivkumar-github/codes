// // // // // an object has some properties and some methods

// // // // // direct way of creating object
// // // // const student = {
// // // //     fullName : "shivkumar rajmane",
// // // //     marks : 94.4,
// // // //     printMarks : function(){
// // // //         console.log("marks = ",  this.marks); // this keyword
// // // //     }
// // // // };

// // // // TOPIC: prototypes
// // // // // js objects have a special by default property called prototypes
// // // // // we can set prototype using __proto__
// // // // //(if object and prtotype have same method objects method will be used)


// // // const employee = {
// // //     calcTax() {
// // //         console.log('tax rate is 10%');
// // //     },
// // // }

// // // const karan = {
// // //     salary : 50000,
// // // };

// // // const karan1 = {
// // //     salary : 50000,
// // // };

// // // const karan2 = {
// // //     calcTax(){
// // //         console.log('tax rate is 20%');// object method has more priority
// // //     },
// // //     salary : 900000,
// // // };

// // // karan.__proto__ = employee;
// // // karan1.__proto__ = employee;
// // // karan2.__proto__ = employee;

// // /* TOPIC: classes in js
// // class is template for objects

// //  class className{
// //     constructor(){ // constructor is typed in this way in js

// //     }
// //     myMethod(){

// //     }
// // }
// // let my Obj = new MyClass();
// // */

// // class ToyotaCar {
// //     constructor(){
// //         console.log('constructor is invoked!');
// //     }
// //     start() {
// //         console.log('start');
// //     }
// //     stop() {
// //         console.log('stop');
// //     }
// //     setBrand(brand){
// //         this.brand = brand;
// //     }
// // }

// // let myCar = new ToyotaCar();
// // let myCar1 = new ToyotaCar();


// /* TOPIC: inheritance
// class parent {

// }

// class child extends parent {

// }

// */

// // TOPIC: super key word
// // super keyword is used to access the constructor and methods and properties inside parent class
// // for ex super(args) // to access parent class constructor
// // super.parentMethod(args) ;
// class human {
//     constructor(){
//         console.log('this is constructor of human');
//     }
//     eat(){
//         console.log('person is eating');
//     }
//     sleep(){
//         console.log('sleeping...');
//     }
//     work(){
//         console.log('doing something');
//     }
// }

// class engineer extends human {// childs method overrides parents method when both have same name
//     constructor(){//Must call super constructor in derived class before accessing 'this' or returning from derived constructor only when constructor is made in derived class
//         super();
//         console.log('this is the constructor of engineer class')
//     }
//     work(){
//         // we can also access the methods in parent class using super keyword
//         super.eat();
//         super.work();
//         super.sleep();
//         console.log('coding...');
//     }
//     solveProblem(){
//         console.log('solving problems');
//     }
// }

// class doctor extends human{
//     work(){
//         console.log('consuting patients');
//     }
// }

// let engObj = new engineer();


// TOPIC: error handling
// try catch (in general when error is encountered execution of code stops but by keeping the statement which may cause error, if we keep them in try the error will still happen but code execution won't stop)
/*
try{
    ...normal code
}
catch(err){
    ...handling error
}
*/
let a = 5;
let b = 10;
console.log("a = ", a);
console.log("b = ", b);
console.log("a + b = ", a + b);
console.log("a + b = ", a + b);
try {
    console.log("a + b = ", a + c);// this might cause error;
}
catch (err) {
    console.log(err);
}
console.log("a + b = ", a + b);
console.log("a + b = ", a + b);
console.log("a + b = ", a + b);
console.log("a + b = ", a + b);
















































































