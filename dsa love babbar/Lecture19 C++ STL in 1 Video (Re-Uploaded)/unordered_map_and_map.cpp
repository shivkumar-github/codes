/*

*/

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
    unordered_map<int, string> students_unordered;
    map<int, string> students_ordered;
    pair<int, string> p1(1, "shivkumar1");
    pair<int, string> p3(3, "shivkumar3");
    pair<int, string> p2(2, "shivkumar2");
    students_unordered.insert(p1);
    students_unordered.insert(p3);
    students_unordered.insert(p2);
    students_ordered.insert(p1);
    students_ordered.insert(p3);
    students_ordered.insert(p2);

    for (auto i : students_ordered) // printed according to key values
    {
        cout << i.first << " ";
        cout << i.second << endl;
    }
    cout << endl;

    for (auto i : students_unordered) // printed as inserted
    {
        cout << i.first << " ";
        cout << i.second << endl;
    }

    // cout<< students_ordered.front() << endl;
    return 0;
}