/*
Templates with multiple parametres
*/

#include<iostream>
using namespace std;


template< class T1, class T2 > // In this way we can defined n number of generic data types T1, T2, T3, .... Tn
class myClass{
    public:
    T1 data1;
    T2 data2;
    myClass(T1 a, T2 b){
        data1 = a;
        data2 = b;
    }
    void display(){
        cout<< "data1 = " << this->data1 << endl << "data2 = " << this->data2 << endl;
    }
};
int main(){
    myClass<int,char> obj1(1, 'c');
    obj1.display();
return 0;
}