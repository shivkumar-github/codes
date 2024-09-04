/*
calculate power using recursion
*/

#include <iostream>
using namespace std;
// approach -> if power => even then num^power = num^(power/2) * num^(power/2)
// => odd then num^power = num^(power/2) * num^(power/2) * num
long long int returnpower(int num, int power)
{
    if (power == 0)
        return 1;
    if (power % 2)
    {
        return num * returnpower(num, power / 2) * returnpower(num, power / 2);
    }
    else
    {
        return returnpower(num, power / 2) * returnpower(num, power / 2);
    }
}

int main()
{
    int num, power;
    cin >> num;
    cin >> power;
    cout << returnpower(num, power) << endl;
    return 0;
}
