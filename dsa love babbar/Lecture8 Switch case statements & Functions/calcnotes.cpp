/*
we have to calculate number of notes required for an amount
100 rupees notes
50 rupees notes
20 rupees notes
1 rupees notes
using switch case somehow

for example for 1330
we need 
13 100 rupees notes 
1 20 rupees notes and 10 1rupees notes
*/

#include <iostream>
using namespace std;

int main()
{
    int amount, n100, n50, n20, n1;
    cout<< "Enter the amount  : " << endl;
    cin >> amount ;
    n100=amount/100;
    cout<< "You will need  " << n100 <<": 100 rupees notes"<< endl;
    switch (n100 * 100 <amount)
    {
    case 1: 
        amount -= n100 * 100 ;
        n50 = amount / 50 ;
        cout<< "You will need " << n50 <<": 50 rupees notes"<< endl;
        break;
     }

    switch (n50 * 50 <amount)
    {
    case 1: 
        amount -= n50 * 50 ;
        n20 = amount / 20 ;
        cout<< "You will need " << n20 <<": 20 rupees notes"<< endl;
        break;
     }

    switch (n20 * 20 <amount)
    {
    case 1: 
        amount -= n20 * 20 ;
        n1 = amount / 1 ;
        cout<< "You will need " << n1 <<": 1 rupees notes"<< endl;
        break;
     }
        return 0;
}