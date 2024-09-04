const notesContainer = document.querySelector('.notes-container');
const addNoteButton = document.querySelector('.add-note-button');
let notes = document.querySelectorAll('.input-box');// should we use querySelectorAll or getElementByClassName?

function getNotes() {
    notesContainer.innerHTML = localStorage.getItem('notes');
}

getNotes();

function saveNotes() {
    localStorage.setItem('notes', notesContainer.innerHTML);
}

    addNoteButton.addEventListener('click', () => {
        let inputBox = document.createElement("p");
        inputBox.contentEditable = true;
        let img = document.createElement('img');
        inputBox.className = 'input-box';
        img.src = 'delete.png';
        notesContainer.appendChild(inputBox).appendChild(img);
    });
notesContainer.addEventListener('click', (e) => {
    if (e.target.tagName === 'IMG') {
        e.target.parentElement.remove();
    }
    else if (e.target.tagName === 'P') {
        notes = document.querySelectorAll('.input-box');
        notes.forEach((note) => {
            note.onkeydown = function () {
                saveNotes();
            }
        });
    }
});

document.addEventListener("keydown", event => {
    if (event.key === 'Enter') {
        document.execCommand("insertlinebreak");
    }
}
);