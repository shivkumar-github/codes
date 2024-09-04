/*
Map in STL :-
 => Two keys can point to same value
    but a key can not point two values

 => unordered maps and sets are same just they are not sorted(and a bit differences)   
*/

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> myMap1; // by default it is sorted

    myMap1[0] = "babbar";
    myMap1[1] = "love";
    myMap1[13] = "kumar";
    myMap1.insert({5, "bheem"});

    cout << "Before erase : " << endl;
    for (auto i : myMap1)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    cout << "finding 13 -> " << myMap1.count(13) << endl
         << endl;

    myMap1.erase(13);
    cout << "After erase : " << endl;
    for (auto i : myMap1)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    auto it = myMap1.find(5); // 5 ka pointer return karega
    for (auto i = it; i != myMap1.end();i++)
    {
        cout<< (*i).first << endl;
    }
    cout << endl;
    
    return 0;
}