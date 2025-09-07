let score = JSON.parse(localStorage.getItem("score")) || {
    wins: 0,
    losses: 0,
    ties: 0
};

const resultEl = document.getElementById("result");
const scoreEl = document.getElementById("scoreDisplay");
const playerImg = document.getElementById("player-move-img");
const computerImg = document.getElementById("computer-move-img");

updateScoreDisplay();

function playGame(playerMove) {
    const randomNumber = Math.random();
    let computerMove = "";

    if (randomNumber < 1 / 3) {
        computerMove = "Rock";
    } else if (randomNumber < 2 / 3) {
        computerMove = "Paper";
    } else {
        computerMove = "Scissors";
    }

    let result = "";

    if (playerMove === computerMove) {
        result = "Tie.";
        score.ties++;
    } else if (
        (playerMove === "Rock" && computerMove === "Scissors") ||
        (playerMove === "Paper" && computerMove === "Rock") ||
        (playerMove === "Scissors" && computerMove === "Paper")
    ) {
        result = "You win!";
        score.wins++;
    } else {
        result = "You lose.";
        score.losses++;
    }

    localStorage.setItem("score", JSON.stringify(score));
    resultEl.textContent = `You picked ${playerMove}, Computer picked ${computerMove}. ${result}`;
    updateScoreDisplay();

    // Update and show images
    playerImg.src = `Images/${playerMove.toLowerCase()}-emoji.png`;
    playerImg.alt = playerMove;
    playerImg.classList.remove("hidden");

    computerImg.src = `Images/${computerMove.toLowerCase()}-emoji.png`;
    computerImg.alt = computerMove;
    computerImg.classList.remove("hidden");
}

function resetScore() {
    score = { wins: 0, losses: 0, ties: 0 };
    localStorage.setItem("score", JSON.stringify(score));
    resultEl.textContent = "Scores have been reset.";
    updateScoreDisplay();

    // Hide images
    playerImg.classList.add("hidden");
    computerImg.classList.add("hidden");
    playerImg.src = "";
    computerImg.src = "";
}

function updateScoreDisplay() {
    scoreEl.textContent = `Wins: ${score.wins}, Losses: ${score.losses}, Ties: ${score.ties}`;
}
