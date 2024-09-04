const fs = require('fs') //common js

console.log(fs)

console.log('starting')
fs.writeFileSync('text.txt', 'hello from nodejs') //create a file and write to it 
// sync method blocks the execution of the further code
console.log('ending')

fs.writeFile('text.txt', 'shivkumar is a good boy', () => {
        console.log('file written')
        fs.readFile("text.txt", (err, data) => {
                console.log(err, data.toString());
        })
})

fs.appendFile('text.txt', '\n shivkumar robo', (err, data) => {
        console.log('file appended')
        console.log(data);
})

console.log('done');