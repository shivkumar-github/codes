// Q1 create a new button element. Give it a text "click me", backgrount color of red & text color of white
// insert the button as first element inside the body tag


// creating the button
let newBtn = document.createElement("button");
newBtn.innerText = "click me";
newBtn.style.backgroundColor = "red";
newBtn.style.color = "white";

// insrting the button 
document.querySelector("body").prepend(newBtn);


// Q 2
let para = document.querySelector("p");

// new method
// class list contains the list of values in class attribute
// adding the class
para.classList.add("newClass");
// removing the class
// para.classList.remove("newClass"); // removes that class