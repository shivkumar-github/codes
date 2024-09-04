// /* TOPIC: Events in js
// the change in the state of an object is known as an Events
// events are fired to notify code of interesting changes that may affect code execution 
// following are some types of events
// mouse events (click, double click, etc)
// keyboard events (keypress, keyup, keydown)
// form events(submit etc)
// print event & many more
// for more events visit events mdm web docs
// */

// let btn1 = document.querySelector("#btn1");

// btn1.onclick = (e) => { // TOPIC: event object is a special type of object that has the details about the event & all event handlers have access to the event object
//     console.log('btn1 was clicked');
//     let a = 25;
//     a++;
//     console.log(a);//26
//     console.log(e);
//     // mostly used two event properties are 
//     console.log(e.type);
//     console.log(e.target);
// } // event written in js gets more priority as script tag is written at last
// // don't write function for an event two times (second will overwrite first)

// let div = document.querySelector("div");
// div.onmouseover = (e) => {
//     console.log('you are inside div');
//     console.log(e);
//     // mostly used two event properties are 
//     console.log(e.type);
//     console.log(e.target);
// }


/* TOPIC: Event Listners ->> better way to handle events than js & inline event handling */
// we can also add mutliple event listners to multiple object and also it doesn't overrides inline event handlers i.e both the eventlistners and inline event handler will be executed will be executed
let btn1 = document.querySelector("#btn1");
btn1.addEventListener("click",() => {
    console.log('btn1 was clicked handler1');
});
btn1.addEventListener("click",() => {
    console.log('btn1 was clicked handler2');
});

const handler3 = () => {
    console.log('btn1 was clicked handler3');
};
btn1.addEventListener("click",handler3);
btn1.addEventListener("click",() => {
    console.log('btn1 was clicked handler4');
});


// btn1.removeEventListener(() => {
    // console.log('btn1 was clicked handler3');
// }); // it won't be removed to remove an event listner you have to give same reference for that we can store the event listner in a variable

btn1.removeEventListener("click",handler3); // we have to mention event 

































