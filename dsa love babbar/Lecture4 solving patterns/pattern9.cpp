/*
printing the pattern 
    *
   **
  ***
 **** 
*****
*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
    int dim;
    cout<< "Enter the dim of pattern : " << endl;
    cin >> dim ;
// 1. using setw() function
for (int i = 1; i <= dim ; i++)
{
    string s="";
    for (int j = 1; j <= i; j++)
    {
        s=s+"*";
    }
    cout<< setw(dim) << s << endl;
    
}

// 2.looping spaces
for (int i = 1; i <= dim; i++)
{
    for(int j=1 ; j <= (dim-i) ; j++) {
    cout<< " ";
    }      
    for(int k=1 ; k <= i ; k++) {
    cout<< "*";
    }
    cout<<  endl;
}


return 0;
}