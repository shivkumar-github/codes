// Q1 create a h2 heading element with tex "Hello JavaScript". Append "from Apna College students" to this text using JS
let h2 = document.querySelector("h2");
h2.innerText = h2.innerText + "from Apna College students"; 

// Q 2 create 3 divs with common class name - "box" Access them & add some unique text to each of them 
let divs = document.querySelectorAll(".divs");
// divs[0].innerText = "new unique value 1";
// divs[1].innerText = "new unique value 2";
// divs[2].innerText = "new unique value 3"; // aam zindagi

// mentos zindagi // for any number of divs
let index = 1;
for (const div of divs) {
    div.innerText = `new unique value ${index}`;
    index++;
}

