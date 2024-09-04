const express = require('express')
const app = express()
const port = 3000
const blog = require('./routes/blog');
const shop = require('./routes/shop');

app.use(express.static("public"));
app.use('/blog', blog); // '/blog' se start hone wale sare addresses ko blog handle karega // we can organise in better we using this
app.use('/shop', shop);

app.get('/', (req, res) => {
        console.log("hey its a get request");
        res.send("hello world2!")
})

//GET is used to request data from a specified resource. It should only retrieve data and should have no other effect.
// POST is used to send data to a server to create/update a resource. It submits data to be processed to a specified resource.
app.post('/', (req, res) => {
        console.log("hey its a post request")
        res.send('hello world post');
})

app.put('/', (req, res) => {
        console.log("hey it's a put request")
        res.send('hello world put');
})

// how to serve html file 
app.get('/index', (req, res) => {
        console.log('hey its index html file')
        res.sendFile('templates/index.html', { root: __dirname });
})


// to send a json object 
app.get('/api', (req, res) => {
        res.json({ a: 1, b: 2, c: 3 });
})

// sending instruction to download a file with given path
app.get('/download', (req, res) => {
        res.download('C:\\Users\\shivk\\OneDrive\\Documents\\code with harry backend folder\\tutorial 88 introduction to express js\\public\\show.txt')
})

app.listen(port, () => {
        console.log(`Example app listening on port ${port}`)
})