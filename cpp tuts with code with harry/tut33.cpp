// Dynamic initialisation of objects using constructors
#include <iostream>
using namespace std;

class BankDeposit
{
    int principal;
    int years;
    float interestRate;
    float returnValue;

public:
    // constructor to call when no arguement is passed //always make a default constructor while dealing with constructors
    // Also have to give curly braces otherwise "function defination not found"
    BankDeposit() {}

    // constructor that will be called when interest is passed in terms of fraction
    BankDeposit(int p, int y, float r)
    {
        principal = p;
        years = y;
        interestRate = r;
        returnValue = float(principal);
        // we are taking for loop as the principal amount will be updated every year in bank and then again interest is calculated on new principal amount
        for (int i = 0; i < years; i++)
        {
            returnValue = returnValue * (1 + (interestRate)); // the code is different from code of code with harry
        }
    }

    // constructor that will be called when interest is passed in terms of percentage
    BankDeposit(int p, int y, int R)
    { // here the rate in terms of percentage
        principal = p;
        years = y;
        interestRate = float(R);
        returnValue = float(principal);
        // we are taking for loop as the principal amount will be updated every year in bank and then again interest is calculated on new principal amount
        for (int i = 0; i < years; i++)
        {
            returnValue = returnValue * (1 + (interestRate / 100)); // the code is different from code of code with harry
        }
    }
    void show()
    {
        cout << "The  principal amount was " << principal << " and The return value after " << years << " years is :" << returnValue << endl;
    }
};

int main()
{
    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;
    cout << "Enter the values of p,y and r respectively: (value of r should be in fraction)" << endl;
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    cout << "Enter the values of p,y and R respectively: (value of R should be in percentage)" << endl;
    cin >> p >> y >> R;
    bd2 = BankDeposit(p, y, R);
    bd2.show();
    cout << endl;
    return 0;
}