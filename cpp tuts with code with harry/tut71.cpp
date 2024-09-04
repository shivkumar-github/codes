/*
Vecotor in C++

we can access all methods on vector on cplusplus.com wali site
*/

#include <iostream>
#include <vector>
using namespace std;

// template function to display the vector
template <class T>
void display(vector<T> &v)
{
    cout << "Dislpaying the vector : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        // cout<< v[i] << " "; // this can also be written as
        cout << v.at(i);
    }
    cout << endl
         << endl;
}

// main function
int main()
{
    vector<int> vec1; // zero size vector

    int element, size;

    // // accepting the size of vector
    // cout << "Enter the size of vector you want : " << endl;
    // cin >> size;

    // // Accepting the elements of the vector
    // for (int i = 0; i < size; i++)
    // {
    //     cout<< "Enter an element to add in vector: " ;
    //     cin>>element;
    //     vect1.push_back(element);
    // }

    // // vect1.pop_back(); // it will pops out the last element
    // display(vect1);

    // vector<int> :: iterator iter = vect1.begin(); // Points the pointer to the first element of the vector
    // // vect1.insert(iter + 1, 566);
    // vect1.insert(iter + 1, 2, 566); // 566 ki 2 copies insert kardo
    // display(vect1);

    // different ways of declaring the vector
    vector<char> vec2(4); // 4 element character vector

    vec2.push_back('c');
    cout << "Displaying vec2 : " << endl;
    display(vec2);

    vector<char> vec3(vec2); // 4-element character vector from vec2
    cout << "Displaying vec3 : " << endl;
    display(vec3);

    vector<int> vec4(6, 3); // 6-element vector of 3s
    cout << "Displaying vec4 : " << endl;
    display(vec4);
    cout << vec4.size() << endl;

    return 0;
}