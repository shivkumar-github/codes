// Q you are creating a website for your college,Create a class user with 2 properties, name & email. It also has a method called viewData() that allows user to view website data
let privateData = "this is some private data";
class User{
    constructor(name,email){
        this.name = name;
        this.email = email;
    }
    viewData(){
        console.log(this.name);
        console.log(this.email);
    }
}

// Q create a new class called Admin which inherits from user . Add new method called editData to admin that allows it to edit website data
class Admin extends User{
    constructor(name, email){
        super(name, email);
    }
    editData(newData){
        privateData = newData;
    }
}

let student1 = new User("student1", "student1@gmail.com");
let student2 = new User("student1", "student2@gmail.com");
let student3 = new User("student1", "student3@gmail.com");
let teacher1 = new User("teacher1", "teacher1@gmail.com");
let teacher2 = new User("teacher2", "teacher2@gmail.com");

let Admin1 = new  Admin("Admin1", "admin@gmail.com");
Admin1.editData("the private data has been changed by the admin");

console.log(privateData);