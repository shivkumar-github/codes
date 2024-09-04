/*
A delimiter is a character or sequence of characters used to specify the boundary between separate, independent regions or groups within a data stream or string. Delimiters are commonly used to split or tokenize a string into smaller parts, making it easier to process or manipulate the data.
Common delimiters include commas (,), spaces ( ), tabs (\t), semicolons (;), and more. The choice of delimiter depends on the data format and the specific requirements of the application.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1;
    getline(cin, s1, ','); // by default delimeter in getline function is '\0' character and we can change to any charcter like spaces or comma or asterik etc
    /*
In C++, std::getline is a function used to read input from a stream until a specified delimiter is encountered. The delimiter is a character that signals the end of the input to be read. The std::getline function is commonly used with strings and can be useful for parsing input or breaking a string into components.
*/
    cout << s1 << endl;
    return 0;
}