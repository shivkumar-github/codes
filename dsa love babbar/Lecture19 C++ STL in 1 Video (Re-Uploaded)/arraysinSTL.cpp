/*
first introductory code for stl
*/

#include<iostream>
#include<array>
using namespace std;

int main(){
    int basic[3] = {1, 2, 3}; 
    array<int,4> a = {1, 2, 3, 4};

    int size = a.size();
    for (int i = 0; i < a.size(); i++)
    {
        cout<< a[i] << endl;
    }
    
    cout<< "Element at second index is " << a.at(2) << endl; 
    cout<< "a.empty() = " << a.empty() << endl;
    cout<< "First element = " << a.front() << endl;
    cout<< "Last element = " << a.back() << endl;

    // all of them are O(1)
return 0;
}