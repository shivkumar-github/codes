let engineer = document.querySelector("#engineer");
let doctor = document.querySelector("#doctor");

engineer.style.backgroundColor = "red";
doctor.style.backgroundColor = "blue";

engineer.addEventListener("mouseover", () => {
    alert('berojgar marega(just kidding)');
});

doctor.addEventListener("mouseover", () => {
    alert('kasai');
});