// Conctructors with default arguements in C++

#include<iostream>
using namespace std;
class Simple{
    int data1,data2,data3;
public:
Simple(int a=0, int b=0, int c=0){
    data1=a;
    data2=b;
    data3=c;
}
void printdata(){
    cout << "The value of data1, data2 and data3 is :" <<data1 << "," <<data2<< ","<<data3<< endl;
}
};
int main()
{
Simple s1(1,5,6);
s1.printdata();
Simple s2(7,2);
s2.printdata();
Simple s3(9);
s3.printdata();

return 0;
}