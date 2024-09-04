let boxes = document.querySelectorAll(".box"); //TODO: how boxes became array
let resetBtn = document.querySelector("#reset-btn");
let newGameBtn = document.querySelector("#new-btn");
let msgContainer = document.querySelector(".msg-container");
let msg = document.querySelector("#msg");

let turnO = true; // player X and player O

// 2d array
let winPatterns = [
    [0, 1, 2],
    [0, 3, 6],
    [0, 4, 8],
    [1, 4, 7],
    [2, 5, 8],
    [2, 4, 6],
    [3, 4, 5],
    [6, 7, 8],
];

const resetGame = () => {
    turnO = true;
    enableBoxes();
    msgContainer.classList.add("hide");
};

const disableBoxes = () => {
    for (let box of boxes) {
        box.disabled = true;
    }
}

const enableBoxes = () => {
    for (let box of boxes) {
        box.disabled = false;
        box.innerText = "";
    }
}

const showWinner = (winner) => {
    msg.innerText = `Congratulations, Winner is ${winner}`;
    msgContainer.classList.remove("hide");
    disableBoxes();
}
// innerText vs. value: The innerText property is primarily used to get or set the text content of an element, such as a <div> or a <span>. On the other hand, the value property is specifically designed for input elements like <input> and <textarea> to retrieve the user-entered value.
const checkWinner = () => { // TODO: why we use arrow function instead of normal funciton
    for (let pattern of winPatterns) {
        let pos1Val = boxes[pattern[0]].innerText;
        let pos2Val = boxes[pattern[1]].innerText;
        let pos3Val = boxes[pattern[2]].innerText;
        if (pos1Val != "" && pos2Val != "" && pos3Val != "") {
            if (pos1Val === pos2Val && pos2Val === pos3Val) {
                console.log('winner');
                showWinner(pos1Val);
            }
        }
    }
};

boxes.forEach((box) => { // TODO: what is for each
    box.addEventListener("click", () => {
        if (turnO) { // player O
            box.innerText = "O";
            turnO = false;
        }
        else { // player X
            box.innerText = "X";
            turnO = true;
        }
        box.disabled = true; //disabled property when set to true disables that element
        checkWinner();
    });
});

newGameBtn.addEventListener("click", resetGame);
resetBtn.addEventListener("click", resetGame);






















































