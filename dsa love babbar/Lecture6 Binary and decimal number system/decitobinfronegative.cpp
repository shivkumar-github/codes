/*
converting a negative number to binary
*/

#include<iostream>
using namespace std;

// i.e. two's complement representation of negative numbers
void decitobinnegative(int n)
{
    int num=-n;
    int bin[100],index=1;
    //first loop // directly creating one's complement of the binary form of positive part of given number
    int i=0;
   while (num)
   {
    bin[i]=(!(num%2)); // ! not equal to as we want to create ones complement directly 
    num/=2;
    // index*=10;
    i++;
   }

//    now for getting two's complement have to add 1
   int carrybit=1;
  for (int j = 0; j < i; j++)
  {
    if (bin[j]==1)
    {
        bin[j]=0;
    }
    else if(bin[j]==0){
        bin[j]=1;
        break;
    }
  }

//    printing the number from j=(i-1) to j>=0 
   for (int j = (i-1); j >= 0; j--)
   {
    cout<<bin[j];
   }
   

}
int main(){
int num;
cout<< "Enter the negative number" << endl;
cin >> num ;
if (num >= 0)
{
    cout<< "Please enter a negative number !" << endl;
    return 0;
}

decitobinnegative(num);
return 0;
}




/*
That means 2s complement used only when we want to represent negative numbers 
ChatGPT
Yes, that's correct. The two's complement representation is primarily used to represent negative numbers in a binary system.
 Positive numbers are typically represented directly in binary form, while negative numbers are represented using the two's complement 
 */