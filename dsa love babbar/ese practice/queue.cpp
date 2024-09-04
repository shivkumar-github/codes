/*

*/

#include <iostream>
using namespace std;

class Queue
{
        int qfront, qrear, size;
        int *arr;
        Queue(int size)
        {
                this->size = size;
                arr = new int[this->size];
                qfront = qrear = -1;
        }
        ~Queue(){
                delete arr;
        }
        void enqueue(int element)
        {
                if (qrear == size)
                {
                        cout << "overflow!" << endl;
                }
                else
                {
                        arr[qrear++] = element;
                }
        }

        int front()
        {
                if (qfront == qrear)
                {
                        cout << "underflow!" << endl;
                        return -1;
                }
                else
                {
                        return arr[qfront];
                }
        }

        int deque()
        {
                if (qfront == qrear)
                {
                        cout << "underflow!" << endl;
                        return -1;
                }
                else
                {
                        int temp = arr[qfront];
                        for (int i = 0; i < qrear - 1; i++)
                        {
                                arr[i] = arr[i + 1];
                        }
                        return temp;
                }
        }

        bool isemp()
        {
                return qrear == qfront;
        }
        void printQ()
        {
                for (int i = qfront; i < qrear; i++)
                {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
};

int main()
{

        return 0;
}