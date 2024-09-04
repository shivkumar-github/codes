/*
Actual logic for character pattern problems is while setting limits of iterators (i and j) and calculating the character
we can make our output more beautiful by using namespace
*/

/*
first 4 patterns got deleted but are written in notebook
now printing the pattern
ABC
ABC
ABC
*/

#include<iostream>
using namespace std;

int main(){
int dim;
cout<< "Enter the dimensions of the letter matrix : " << endl;
cin >> dim ;

for (int i = 0; i < dim; i++)
{
    for (int j = 0; j < dim; j++)
    {
        char ch=('A' + j);
        cout<< ch << "\t";
    }
    cout << endl;
}

return 0;
}