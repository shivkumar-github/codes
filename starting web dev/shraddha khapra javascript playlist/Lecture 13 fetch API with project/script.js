/*All power is within you, you can do anything and evrything
TOPIC: fetch API(Application Programming interface)
it uses Request and Response objects 
the fetch method is used to fetch a resource (data)
let promise = fetch (url, [options]) // the fetch method returns the promise // without any options fetch produces get Request
*/
const URL = "https://cat-fact.herokuapp.com/facts";

// const getFacts = async () =>{
//     let response = await fetch(URL);
//     console.log(response.status);
//     let data = await response.json(); // await because .json is also a asynchornous function
//     console.log(data[0].text);
// };

// // doing same with api chaining
// function getFacts(){
//     fetch(URL).then((response) => {
//         return response.json();
//     }).then((data) => {
//         console.log(data);
//     });
// }

// TOPIC: understanding terms
// AJAX Asunchronous JS & XML
// JSON is JavaScript Object Notation or AJAJ
// JSON() method : returns a second promise that revolves with the result of parsing the response body text as JSON.(input JSON and output is js object)

// Informational responses (100 – 199)
// Successful responses (200 – 299)
// Redirection messages (300 – 399)
// Client error responses (400 – 499)
// Server error responses (500 – 599)

































































































