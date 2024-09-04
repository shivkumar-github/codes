/*
writing a code which converts binary number to a decimal number
*/

#include <iostream>
#include <cmath>
using namespace std;

void bintodec(int bin_num)
{
    // first we have to extract the digits of the nubmer ( i.e. o's and 1's) and then multiply with 2's power to and add them together to form decimal number
    int digit;
    int i = 0;
    int deci = 0;
    // int index = 1;
    while (bin_num) // as loop needs to be stoped when num=0
    {
        digit = (bin_num % 10); 
        // deci+=(digit*index);  // to increase decimal no by adding powers of two   
        bin_num /= 10; 
        deci += (digit * int(pow(2, i)));
        // index *= 2; //<<---- this statement used to calculate powers of 2 (also can be done by pow()function)
        i++;
    }

    /*we can calculate powers of 2 using two ways 
    1. using a index variable and index *= 2 or using pow() function from cmath library 
       The lines which are commented out are for index wala logic
 */
    cout << "The decimal form of entered binary number is : " << deci << endl;

}

int main()
{
    // here we can not use bitwise operator as used in decimal to binary as the binary representation entered by user will be a decimal number
    int bin_num;
    cout << "Enter the binary representation : " << endl;
    cin >> bin_num;
    bintodec(bin_num);

    return 0;
}