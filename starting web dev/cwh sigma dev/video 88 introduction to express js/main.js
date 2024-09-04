// Express is a web application framework for Node.js, designed for building web applications and APIs.
// Express is like a helper for building websites or web applications using Node.js. 
// Express is like a special set of LEGO pieces that helps you build these things faster and easier rather than building them from scratch everytime

const express = require('express')
const app = express()
const port = 3000

app.use(express.static('public')) // make the folder named public as static folder(folder which can be accessed by the user)


app.get('/', (req, res) => {
        res.send('hello world!')
})

app.get('/blog/intro-to-python', (req, res) => {
        res.send('hello python!')
})

app.get('/blog/intro-to-js', (req, res) => {
        res.send('hello js!')
})

// In the context of web development and the provided code snippet, a "slug" refers to the part of a URL which identifies a particular page on a website in a form readable by both users and search engines. It's the part of the URL that explains the page's content.

// req is an object representing the HTTP request to the server
// app.get('/blog/:slug/:second', (req, res) => {
//         console.log(req);
//         // res.send(`hello ${req.params.slug} and ${req.params.second}`) 
//         console.log(req.params); // will print - { slug: 'intro-to-python', second: 'heoo'  }
//         console.log(req.query) // will print - { name: 'john' }
//         // for url - http://localhost:3000/blog/intro-to-python/heoo?name=john
// })

app.listen(port, () => {
        console.log(`Example app listening on port ${port}`);
})
 