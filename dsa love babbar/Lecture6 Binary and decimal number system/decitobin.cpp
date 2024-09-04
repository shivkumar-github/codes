/*
writing a program which converts binary number to decimal number
*/

#include<iostream>
#include <cmath>

using namespace std;


void givebin(int n){
int i=0 ,bit;
float answer=0; // have to declare answer as float as pow function gives floating point number in return
    while (n!=0)
    {
        bit = (n & 1);
        n >>=  1;  // n = n >> 1
        cout<< n << endl;
        answer += (bit * pow(10,i)); 
        i++;
    }
cout<< "The binary form of given decimal number is : " << answer << endl;

}   

    
int main(){
int num;
cout<< "Enter the number : " << endl;
cin >> num ;
givebin(num);

return 0;
}   