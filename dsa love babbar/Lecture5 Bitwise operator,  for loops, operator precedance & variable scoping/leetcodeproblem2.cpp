/*
write a functioin that takes an unsigned integer
and returns the number of '1' bits it has (also known as the 'Hamming weight')
sir had the problem which takes binary number as input and then calculates haming weight 
but our code directly calculates the hamming weight from integer
*/

#include <iostream>

using namespace std;

// function which calculates the haming weight of the number
void giveHammingweight(int num1)
{
    int binaryarr[100];
    int count = 0; // to count the bits in the binary number
    int Hamingweight = 0;

// 1st approach==>
    // // converting the number to binary
    // for (int i = 0; num1 > 0; i++)
    // {
    //     binaryarr[i] = num1 % 2;
    //     num1 /= 2;
    //     count++;
    // }

    // // calculating haming weight
    // for (int i = 0; i < count; i++)
    // {
    //     if (binaryarr[i] == 1)
    //     {
    //         Hamingweight++;
    //     }
    //     else
    //     {
    //     }
    // }


// second approach==>
for (int i = 0; num1 >0 ; i++)
{
    if (num1%2==1)
    {
        Hamingweight++;
    }
    num1 /=2;
}

// printing the haming weight
    cout << "The haming weight of given number is : " << Hamingweight << endl;
}

int main()
{
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    giveHammingweight(num);

    return 0;
}