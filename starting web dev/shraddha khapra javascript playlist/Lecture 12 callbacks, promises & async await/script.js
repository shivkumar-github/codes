// // // TOPIC: sync in js
// // /*
// // synchronous - each instruction works for the execution of the previous one to complete and then starts its own execution
// // asynchronous - it doesn't restricts the next instruction to wait for completion of previous but allows the execution of next which prevents in delay
// // */
// // console.log('one');
// // console.log('two');

// // setTimeout(() => {
// //     console.log('hello');
// // }, 3000); // run the function after 4000milli seconds
// // console.log('three');
// // console.log('four');

// // TOPIC: callbacks are the function passed to another function as an arguement

// function sum(a, b){
//     console.log(a + b);
// }

// function calculator(a, b, sumCallback){
//     sumCallback(a,b);
// }

// calculator(1,2,sum); // here sum is callback and we can not write paranthesis, must pass name only

// const hello = () =>{
//     console.log("hello");
// };

// setTimeout(hello, 4000);

// TOPIC: callback hell
/*
call back hell: nested callbacks stacked below one another forming a pyramid structure.(pyramid of doom)

this style of programming becomes difficult to understand & manage. f
*/

// nesting 

// function getData(dataId, getNextData) {
//     setTimeout(() => {
//         console.log('data = ', dataId);
//         if (getNextData) {
//             getNextData();
//         }
//     }, 2000);
// }

// getData(123);
// getData(456);
// getData(789);// suppose we want to get first data and then second but this will give all the datas though the previous one is not given

// getData(1, () => {
//     console.log('getting data 2');
//     getData(2 ,() => {
//         console.log('getting data 3');
//         getData(3,()=>{
//             console.log('getting data 4');
//             getData(4,()=>{
//                 console.log('getting data 5');
//                 getData(5);
//             });
//         });
//     });
// });
// // this is pyramid of doom or hell



// TOPIC: Promises
// a solution for callback hell
// let new promise = new Promise((resolve, reject) => {...})

// let promise = new Promise((resolve,reject) =>{ // resolve and reject are callbacks(handlers) provided by js
//     console.log('your promise is successfully resolved');
//     resolve('your promise has been successfully fullfilled'); // if both written the first one will be executed
//     reject('sorry your promise has been rejected');
// });
// // there are three states for a promise resolve , reject , pending
// function getData(dataId,getNextData){
//     return new Promise((resolve,reject) =>{
//         setTimeout(()=>{
//             console.log('dataId',dataId);
//             resolve('succes');
//             if (getNextData) {
//                 getNextData();
//             }
//         },2000);
//     });
// }

// promise.then((res) => {...});
// promise.catch((err) => {...});
// in .then() we pass a fucntion which will be executed only when the promise is fullfilled
// const getPromise = () => {
//     return new Promise((resolve, reject) => {
//         console.log("I am a promise");
//         // resolve("promise fetched successfully");
//         reject('promise rejected');
//     });
// }

// let promise = getPromise();
// promise.then((res) => {
//     console.log('promise fullfulled');
// })

// promise.catch((err) =>{
//     console.log('sorry, your promise has been rejected');
// });

// // TOPIC: promise chainging
// function asyncFunc(){
//     return new Promise((resolve, reject)=> {
//         setTimeout(() => {
//             console.log('some data');
//             resolve("successfully resolved");
//         }, 4000);
//     });
// }

// console.log('fetching data1...')
// let p1 = asyncFunc();
// p1.then((res)=>{
//     console.log(res);
//     console.log('fetching data2...')
//     return asyncFunc();
// }).then((res)=>{
//     console.log(res);
//     console.log('fetching data3...')
//     return asyncFunc();
// }).then((res) => {
//     console.log(res);
//     console.log('your computer has been successfully hacked');//(-_-)
// }); // a bit easier than callback hell


// TOPIC: Async-Await
// async function myFunc(){...}
// async always returns a promise
// await pauses the execution of its surrounding async function(the async function in which it is used) until the promise is settled (so the event loop is freed to carry out other operations) and once a promise is settled then the execution starts again
// await can not be used without async function

// async function hello(){
//     console.log('hello');
// }


// function api() {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             console.log('this is weather data');
//             resolve(200);
//         }, 2000);
//     });
// }

// // await api(); can not write await like this without using async
// async function getWeatherData() {
//     await api();
//     await api();
// }



function getData(dataId){
    return new Promise((resolve, reject)=>{
        setTimeout(() => {
            console.log('data',dataId);
            resolve('success');
        }, 2000);
    })
}

async function getAllData(){
    console.log('getting data1');
    await getData(1);
    console.log('getting data2');
    await getData(2);
    console.log('getting data3');
    await getData(3);
    console.log('getting data4');
    await getData(4);
    console.log('getting data5');
    await getData(5);
    console.log('getting data6');
    await getData(6);
    console.log('getting data7');
    await getData(7);
}

// much much easier to understand



// TOPIC: IIFE is a function that is immidiately called as soon as it is defined
// gen syntax (a normal function)();

// for example 
(async function getAllData(){
    console.log('getting data1');
    await getData(1);
    console.log('getting data2');
    await getData(2);
    console.log('getting data3');
    await getData(3);
    console.log('getting data4');
    await getData(4);
    console.log('getting data5');
    await getData(5);
    console.log('getting data6');
    await getData(6);
    console.log('getting data7');
    await getData(7);
})();// dont need to call the function to execute it ,  it will automatically called when created but it can not be reused , for that we have to create it again


























