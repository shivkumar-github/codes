/*
queue in STL
First in first out => fifo
*/

#include<iostream>
#include<queue>
using namespace std;
  
int main(){
    queue<string> myQueue;
    myQueue.push("1st entered");
    myQueue.push("2nd entered");
    myQueue.push("3rd entered");

    cout<< "Size before pop() = " << myQueue.size() << endl;
    cout<<"First Element : " << myQueue.front() << endl;
    myQueue.pop(); // here pop function pops out the first element in the queue
    cout<< "After pop first element : " << myQueue.front() << endl;

    cout<< "Size after pop() = " << myQueue.size() << endl;


return 0;
}