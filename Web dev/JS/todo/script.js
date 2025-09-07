const tasksList = [];

document.querySelector('.js-addTask').addEventListener('click', addTask);
document.querySelector('.js-trial').addEventListener('click', displayArray);

function addTask() {
    const inputEl = document.querySelector(".js-inputText");
    const taskText = inputEl.value.trim();

    if (taskText !== "") {
        tasksList.push(taskText);
        displayTask(taskText);
        inputEl.value = "";
    }
}

function displayArray() {
    console.log(tasksList);
}

function displayTask(taskText) {
    const taskContainerEl = document.querySelector('.js-taskContainer');

    const taskEl = document.createElement('div');
    taskEl.classList.add('task-item');

    const textEl = document.createElement('p');
    textEl.textContent = taskText;

    const deleteBtn = document.createElement('button');
    deleteBtn.textContent = 'Delete';
    deleteBtn.classList.add('delete-btn');
    deleteBtn.addEventListener('click', () => {
        taskContainerEl.removeChild(taskEl);
    });

    taskEl.appendChild(textEl);
    taskEl.appendChild(deleteBtn);
    taskContainerEl.appendChild(taskEl);
}
