/* To check if given number is prime or not */


// //my logic
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




// somebody else's logic

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