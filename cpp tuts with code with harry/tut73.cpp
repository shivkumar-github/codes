/*
Map in C++ 
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;


// Map is an associative array
int main(){
     
    map<string, int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;
    // insert method
    marksMap.insert({{"Shivkumar", 54},{"krishna", 45}});
    map<string, int> :: iterator itr;
    for ( itr = marksMap.begin(); itr != marksMap.end() ; itr++)
    {
        cout<< (*itr).first << " " << (*itr).second << endl;
    }
    cout<< "The size is : " << marksMap.size() << endl;
    cout<< "The maxsize is : " << marksMap.max_size() << endl;
    cout<< "The empty's return value is : " << marksMap.empty() << endl;

return 0;
}