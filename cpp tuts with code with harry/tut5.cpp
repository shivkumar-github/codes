// basic input output ,extraction and insertion operators and reserved keywords

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter the value of num1:\n";
    /*'<<' is insertion operator as it is telling the processor to insert it into display */
    cin >> num1;
    /* '>>'this is extraction operator as it is telling the processor to extract the input given by user */

    cout << "Enter the value of num2:\n"; /* '<<' is insertion operator as it is telling the processor to insert it into display */
                                          /* '<<' is insertion operator as it is telling the processor to insert it into display */
    cin >> num2;
    /* '>>' this is extraction operator as it is telling the processor to extract the input given by user */

    cout << "The sum is " << num1 + num2;

    return 0;
}
