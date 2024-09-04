// Q create a toggle button that changes the screen to dark mode when clicked and & light mode when again clicked

let mode = document.querySelector("#mode");
let isLight = true;
let body = document.querySelector("body");
mode.addEventListener("click", () => {
    if (isLight === true) {
        body.style.backgroundColor = "black";
        body.style.color = "white";
        isLight = false;
    }
    else {
        body.style.backgroundColor = "white";
        body.style.color = "black";
        isLight = true;
    }

});



































































































