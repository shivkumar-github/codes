// Destructor in C++

#include <iostream>
using namespace std;
// Destructor never takes an arguement nor it gives any value
int count = 0;
class num
{
    // we can also use static int count instead of global count variable
public:
    num()
    {
        count++;
        cout << "This is th time when constructor is called for object number" << count << endl;
    }
    ~num()
    {
        cout << "This is the time when my destructor is called for object number" << count << endl;
        count--;
    }
};
int main()
{
    cout << "We are inside our main function" << endl;
    cout << "Creating firsts object n1" << endl;
    num n1;
    // Created a block (the data of block ends inside the block)
    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3;
        cout << "Exiting the block" << endl;
    }
    cout << "Entering the main " << endl;
    return 0;
}