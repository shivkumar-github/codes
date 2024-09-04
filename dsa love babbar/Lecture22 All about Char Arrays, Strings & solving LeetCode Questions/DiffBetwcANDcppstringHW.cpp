// difference between string and char arrays(c type strings)
#include <iostream>
using namespace std;

int main()
{
    char array[] = "yohello";
    string s = "yohello";
    cout << s[7];
    cout << array[7];
    /*
    Feature 	                                     C-style strings	                           C++ strings
    Type    	                                  Array of characters                              Class
    Memory management                      	Manual	                                   Automatic
    Safety	                                            Prone to errors                 Bounds checking, exceptions
    Operations	                              Limited built-in functions	   Rich set of member functions
    Modification	                            Can be cumbersome	               Easier and safer
    */
    return 0;
}