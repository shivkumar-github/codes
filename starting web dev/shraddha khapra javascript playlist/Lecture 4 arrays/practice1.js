// create an array to store companies ["bloomberg", "microsoft", "Uber", "Google", "IBM", "Netflix"]
//a. your task is to remove first company from array 
//b. remove uber and add ola in it's place
//c. add amazon at the end

let companies = ["bloomberg", "microsoft", "Uber", "Google", "IBM", "Netflix"];
// a.
companies.shift();
console.log(companies)
// b. 
companies.splice(2,1,"Ola") // replaces element at index 2
console.log(companies);

// c.
companies.push("amazon");
console.log(companies);
