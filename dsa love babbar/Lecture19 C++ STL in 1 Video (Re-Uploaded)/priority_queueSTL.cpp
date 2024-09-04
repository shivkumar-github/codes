/*
priority_queue => Based on concept of max heap
jab hum koi element bahar nikalenge to vo hamesha queue ka maximum element niklega
*/

#include <iostream>
#include <queue>
using namespace std;

void printmyMaxi(priority_queue<int> &myMaxi)
{
    int n = myMaxi.size();
    for (int i = 0; i < n; i++) // we can not use size() function directly in loop as size will decrease as we pop out elements
    {
        cout << myMaxi.top() << " ";
        myMaxi.pop();
    }
    cout << endl;
}

void printmyMini(priority_queue<int, vector<int>, greater<int>> &myMini){
    int n = myMini.size();
    for (int i = 0; i < n; i++)
    {
        cout<< myMini.top() << " ";
        myMini.pop();
    }
    cout << endl;
}

    int main()
{

    // max heap
    priority_queue<int> myMaxi1;

    // min heap
    priority_queue<int, vector<int>, greater<int>> myMini1;

    // pushing data
    myMaxi1.push(1);
    myMaxi1.push(3);
    myMaxi1.push(2);
    myMaxi1.push(0);

    cout<< "elements in myMaxi1 are : " << endl;
    printmyMaxi(myMaxi1);

    myMini1.push(5);
    myMini1.push(0);
    myMini1.push(1);
    myMini1.push(4);
    myMini1.push(3);

    cout<< "elements in myMini1 are : " << endl;
    printmyMini(myMini1);

    cout<< "Bhai Khali hai kya ? -> " << myMini1.empty() << endl;

    return 0;
}