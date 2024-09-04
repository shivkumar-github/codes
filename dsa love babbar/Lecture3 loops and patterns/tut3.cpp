/*
loops and patterns
*/

/*determining whether the entered character is upper case lower case or a number*/
// #include<iostream>
// using namespace std;

// int main(){
// char input;
// cout<< "Enter the character : " << endl;
// cin >> input ;
// int char_num=input;
// if (char_num>=97 && char_num<=122)
// {
//     cout<< "The entered character is lower case. " << endl;
// }

// else if (char_num>=65 && char_num<=90)
// {
//     cout<< "The entered character is upper case. " << endl;
// }

// else if (char_num>=48 && char_num<=57)
// {
//     cout<< "The entered character is a number. " << endl;
// }

// else {
//     cout<< "Please enter a valid character !!" << endl;
// }
// return 0;
// }




// /* To check if given number is prime or not */
// my logic
// #include <iostream>
// using namespace std;

// int main()
// {
//     int num;
//     cout << "Enter the number : " << endl;
//     cin >> num;
//     bool c;
//     if (num==2)
//     {
//         cout<< "The number is prime." << endl;
//     }
    
//     for (int i = 2; i < num; i++)
//     {
//         if (num % i == 0)
//         {
//             cout << "The number is not prime. " << endl;
//             exit(0);
//         }

//         else
//         {
//             c = 1;
//         }
//     }

//     if (c == 1)
//     {
//         cout << "The number is prime. " << endl;
//     }
//     return 0;
// }


// something else's logic

#include<iostream>
using namespace std;

int main(){
int num;
cout<< "Enter the number : " << endl;
cin >> num ;

bool isprime=1;

if (num<=1)
{
    cout<< "The number is not prime. " << endl;
    exit(0);
}

for (int i = 2  ;  ( i * i ) <= num  ; i++)
{
    if (num%i==0)
    {
       isprime=0;
       break;
    }
    
}

if (isprime==1)
{
    cout<< "The number is prime. " << endl;
}
else if(isprime==0){
    cout<< "The number is not prime." << endl;
}

return 0;
}