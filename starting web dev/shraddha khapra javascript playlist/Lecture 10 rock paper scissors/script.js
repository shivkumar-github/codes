let userScore = 0;
let userScoreMsg = document.querySelector("#user-score");
let compScore = 0;
let compScoreMsg = document.querySelector("#comp-score");
let choices = document.querySelectorAll(".choice");
let msg = document.querySelector("#msg");

const genCompChoice = () => {
    //rock paper scissor
    const options = ["rock", "paper", "scissors"];
    const randomIdx = Math.floor(Math.random() * 3);// creates a random number between 0(inclusive) to 1(exclusive)
    return options[randomIdx];
};

const drawGame = (compChoice) => {
    msg.style.backgroundColor = "#081b31";
    msg.innerText = `Game was Draw, Play again!`;
};

const showWinner = (userWin, userChoice, compChoice) => {
    if (userWin) {
        msg.style.backgroundColor = "green";
        msg.innerText = `You win! Computer chose ${compChoice}`;
        userScore++;
        userScoreMsg.innerText = userScore;
    }
    else {
        msg.style.backgroundColor = "red";
        msg.innerText = `You lost. Computer chose ${compChoice}`;
        compScore++;
        compScoreMsg.innerText = compScore;
    }
};

const playGame = (userChoice) => {
    // Generate computer choice -> modular programming
    const compChoice = genCompChoice();
    if (userChoice === compChoice) {
        drawGame(compChoice);
    }
    else {
        let userWin = true;
        if (userChoice === "rock") {
            // scissors or paper
            userWin = compChoice === "paper" ? false : true;
        }
        else if (userChoice === "paper") {
            userWin = compChoice === "scissors" ? false : true;
        }
        else {// userChoice = "scissors"
            userWin = compChoice === "rock" ? false : true;
        }
        showWinner(userWin, userChoice, compChoice);
    }
};

choices.forEach((choice) => {
    choice.addEventListener("click", () => {
        const userChoice = choice.getAttribute("id");//uss tag ke id attribute ki value lao
        playGame(userChoice);
    });
});

