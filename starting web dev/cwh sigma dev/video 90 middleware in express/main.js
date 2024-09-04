// Middleware in Express is a function that has access to the request object (req), the response object (res), and the next middleware function in the application’s request-response cycle. These functions can execute any code, make changes to the request and the response objects, end the request-response cycle, and call the next middleware function in the stack.
// we can use middleware for processing which needs to be done on all requests (like checking it's type etc)

const express = require('express')
const app = express()
const port = 3000
const fs = require('fs')
const blog = require('./routes/blog')

app.use('/blog', blog)

// built in middleware
app.use(express.static('public'))

// Middleware m1
app.use((req, res, next) => {
        req.shiv = " this is string added using middleware";
        fs.appendFileSync("logs.txt", `\n ${Date.now()} is a ${req.method} method`)
        console.log(`${Date.now()} is a ${req.method} method`)
        // console.log('m1')
        // if you want to complete the process then send the response and don't call next function
        // res.send('process completed')
        next();
})

app.use((req, res, next) => {
        console.log('m2')
        next();
})

// route handlers
app.get('/', (req, res) => {
        res.send('Hello World!')
})

app.get('/about', (req, res) => {
        res.send('Hello World! about' + req.shiv) 
})

app.get('/contact', (req, res) => {
        res.send('Hello World! contact')
})

app.listen(port, () => {
        console.log(`Example app listening on port ${port}`)
})