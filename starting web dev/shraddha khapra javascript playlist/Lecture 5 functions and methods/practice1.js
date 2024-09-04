// create a function using the function keyword that takes string as an arguement & returns the number of vowels in the strings
function returnVowel(str) {
    let cnt = 0;
    for (const char of str) {
        if (char === "a" || char === "e" || char === "i" || char === "o" || char === "u" || char === "A" || char === "E" || char === "I" || char === "O" || char === "U")
            cnt++;
    }
    console.log(cnt);
};

returnVowel("theee");


// create an arrow function to perform the same task
let vowels = (str) => {
    for (const char of str) {
        if (char === "a" || char === "e" || char === "i" || char === "o" || char === "u" || char === "A" || char === "E" || char === "I" || char === "O" || char === "U")
        cnt++;
}
};
returnVowel("th7gn");

