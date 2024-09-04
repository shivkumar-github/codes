/*determining whether the entered character is upper case lower case or a number*/

// my logic
#include <iostream>
using namespace std;
int main()
{
    char input;
    cout << "Enter the character : " << endl;
    cin >> input;
    int char_num = input;

    if (char_num >= 97 && char_num <= 122)
    {
        cout << "The entered character is lower case. " << endl;
    }

    else if (char_num >= 65 && char_num <= 90)
    {
        cout << "The entered character is upper case. " << endl;
    }

    else if (char_num >= 48 && char_num <= 57)
    {
        cout << "The entered character is a number. " << endl;
    }

    else
    {
        cout << "Please enter a valid character !!" << endl;
    }

    return 0;
}