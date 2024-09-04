// Array of Objects in C++

#include<iostream>
using namespace std;

class Employee{
    int id;
    int salary;
    public:
    void setId(void){
salary=122;
        cout << "Enter the id of employee : " << endl;
        cin >> id ;
    }

    void getId(){
        cout << "The id of the employee is : " << id << endl;
    }
};




int main()
{
// Employee harry, lovish, rohan ;
// harry.getId();
// harry.setId();

Employee fabtech[4]; //to get 4 objects as employees workiing in fabtech company

for( int i = 0 ; i < 4  ; i++ )
{
fabtech[i].setId();
fabtech[i].getId();
}

return 0;
}