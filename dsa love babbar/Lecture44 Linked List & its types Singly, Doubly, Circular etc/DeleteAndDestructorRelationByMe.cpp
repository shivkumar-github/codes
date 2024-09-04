/*

*/

#include<iostream>

using namespace std;
class A{
    public:
    int data;
    A(int data){
        this-> data = data;
    }
    ~A(){
        cout << "object deleted which has data -> " << this-> data << endl;
    }
};
int main(){
    A* myPointer = new A(3);
    delete myPointer;
    cout << "hey there" << endl;
return 0;
}
// conclusion when we delete a pointer to object using delete key word then its destructor is called