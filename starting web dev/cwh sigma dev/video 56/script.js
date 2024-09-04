console.log("hello this is console")
let i = 10;
do {
    console.log(i--);
} while (i >= 0);

function sum(a, b, c = 2) {
    console.log(a, b, c)
    return a + b + c;
}

function name(name) {
    console.log("hey " + name + " how are you?")
}

name("shivkumar");

console.log("the sum of these numbers is ", sum(8, 9, 10));

const func = (num) => {
    console.log("i am arrow function of " , num);
}

func(90);

