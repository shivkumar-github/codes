// Array of Objects using Pointers in C++
#include <iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;

public:
    void set_data(int a, float b)
    {
        id = a;
        price = b;
    }
    void get_data(void)
    {
        cout << "Id of this item is : " << id << endl;
        cout << "The price of this item is : " << price << endl;
    }
};

int main()
{
    int size = 3;
    // 1. general store item
    // 2. veggies item
    // 3. hardware item
    ShopItem *ptr = new ShopItem[size];
    ShopItem *ptrTemp = ptr;
    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Id and price of item " << (i + 1) << endl;
        cin >> p >> q;
        // (*ptr).set_data(p,q);
        ptr->set_data(p, q);
        ptr++;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Item number : " << (i + 1) << endl;
        ptrTemp->get_data();
        ptrTemp++;
    }

    return 0;
}