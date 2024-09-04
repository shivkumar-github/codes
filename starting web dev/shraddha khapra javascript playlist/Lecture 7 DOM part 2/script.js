// // biiger TOPIC: dom manipulation
// // //TOPIC: attributes
// // // getAttribute(attr) // to get the attribute value
// // let div = document.querySelector("div");
// // console.log(div)
// // let id = div.getAttribute("id");
// // console.log(id);
// // let name = div.getAttribute("name");
// // console.log(name);

// // let para = document.querySelector("p");
// // console.log(para.getAttribute("class"));

// // // setAttribute(attr, value) // to set the attribute value
// // console.log(para.setAttribute("class", "new_class_name"));


// let div = document.querySelector("div");
// // div.style will show inline style
// div.style.backgroundColor = "red";
// // in css bacckground-color => in js backgroundColor i.e when hyphen gets replaced by capital letter
// div.style.fontSize = "26px";
// div.textContent = "hello!";

// TOPIC: inserting elements
// to steps 1. create 
let newBtn = document.createElement("button");
newBtn.innerText = "click me!";

// step 2 :  add(first we have to decide with which element(also called node) as a reference we want to add the new element (here the reference element is div))
// 4 methods
//1st node.
let div = document.querySelector("div");
// div.append(newBtn); // at last but inside div

// 2nd ->> node.prepend(element_to_add) ->> add at start but inside the node
// div.prepend(newBtn);
// 3rd ->> node.after(element_to_add) ->> add at end but outside the node
// div.after(newBtn);
// 4th ->> node.before(element_to_add) ->> add at start but outside the node
div.before(newBtn);

// delete the element
// node.remove()
let para = document.querySelector(".para");
// para.remove();


// TODO: homework read about appendChild() and removeChild() on mdn documentation



























