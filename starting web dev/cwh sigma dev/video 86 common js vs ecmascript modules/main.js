// CommonJS and ECMAScript (ES) modules are two ways to organize and reuse JavaScript code by breaking it into smaller, manageable pieces called modules.

// common js is synchronous and blocking and is bydefualt in nodejs
// ECMAScript is asynchronous and non-blocking

// ecma script

// // named export
// import { a, b, d } from './mymodule.js';
// console.log(a, b, d); // 1 2 4

// // default export (we can name it whatever we want)
// import harry from './mymodule.js';
// console.log(harry); // { x: 5, y: 7 }

// common js
const a = require('./cjsmodule.js');
console.log(a, __dirname, __filename); // { x: 5, y: 7 }