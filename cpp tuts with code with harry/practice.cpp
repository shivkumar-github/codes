// //

// #include<iostream>
// #include<fstream>
// #include<cstring>
// using namespace std;

// int main()
// {
// // an decimal number is double by default
// //suppose there is a variable named f which is  float
// //float f=12.3f or float f=12.3F are written to declare it explicitly
// // and to declare it as long double we write l or L instead of f or F
// // cout << 88.9f << endl; //the 88.9 will be treated as float
// // syntax to declare y as reference variable of x is
// // int &y=x; //we can say that & is just opposite to that of pointer
// // 
// if there is variable x of type float  or double etc then we can convert it in int explicitly by int(x) or by (int)x
// // <manip> is a library that has functions which can manipulate input and output
// // any variable can be declared as constant by writing word const before the data type in

// //declaring a switch case
// // int a;
// // switch (a)
// // {
// // case 1:
// //     /* code */
// //     break;

// // default:
// //     break;
// // }
// // for string functions string header file is included
// // if s is a string then s.length
// // string str1="str1";
// // cout << str1 << endl;
// // char str2[]="str2";
// // cout <<str2;
// // long double x;
// // double y;
// // long int z;
// // cout << "long double " <<sizeof(x) << endl; //12
// // cout << "double " << sizeof(y) << endl; //8
// // cout << "long int " << sizeof(z) << endl;  //4

// char array1[1000];
// char array2[1000];
// char array3[1000];
// char array4[1000];
// ofstream output_from_code;
// output_from_code.open("sample60.txt");
// cout<< "Enter the first line : " << endl;
// cin.get(array1,1000);
// cin.ignore();
// cout<< "Enter the second line : " << endl;
// cin.get(array2,1000);
// output_from_code<<array1;
// output_from_code<<array2;
// output_from_code.close();

// ifstream input_to_code;
// input_to_code.open("sample60.txt");
// // input_to_code.get(array3,1000);
// // //input_to_code.get(array4,1000);

// // // cout<< "this is array 3" << endl;
// // cout<< array3 << endl; // prints the all lines of file in one line  
// // // cout<< "this is array 4" << endl;
// // // cout<< array4 << endl; // array4 is empty  as whole content is taken by array3 using get function

// // to get line by line as written in file we use endof() file function
// for (int i = 0; input_to_code.eof()==0; i++)
// {
//     input_to_code.getline(array3,1000);
//     cout<< array3 << endl; 
// }

// input_to_code.close();
// return 0;
// }

// /*
// // switch case doubt
// */

// #include<iostream>
// using namespace std;

// int main(){
// int age;
// cout<< "Enter your age : " << endl;
// cin >> age ;

// switch (age)
// {
// case (>=18): // error as switch case can not handle ranges 
//     cout<< "your are an adult . " << endl;
//     break;

// default: 
// cout<< "you are not an adult . " << endl;
//     break;
// }
// return 0;
// }

/*
setw() doubt
*/

// #include<iostream>
// #include<iomanip>
// using namespace std;

// int main(){
// int a=100;
// cout<<  setw(4) << a <<endl;
// return 0;
// }

// syntax to call constructor implicitely
// class_name Object_name = Constructor_name(arguements if any);


//    int printfib(int n){
//     if(n<=2){
//        return (n-1); 
//     }
//     else{
//      return printfib(n-1) + printfib(n-2);
//     }
//    }



// // ********************* EST practice
// #include <iomanip>//it has the functioins which can manipulate input output in cpp
// // setw() is used before the variable
// #include<iostream>
// using namespace std;
// int main(){
//     int a=3;
//     int* b=&a;
//     int** c=&b; // c is pointer to pointer
//     // call by reference swap(int &a, int &b) this is using reference variables
//     // now using ppointers swap(int* a, int* b)
// cout<< printfib(4) << endl;
//     return 0;
// }