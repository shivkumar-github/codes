/*
int n;
cin >> n;
int arr[n] -> array created using static memory allocation
according to C++ standards it is wrong to create an array like this only newer compilers support these type of VLA(variable length arrays) 
instead we create an array of greater size (as we did in matrix wale questions) for example arr[1000]

for more details about heap and stack memory you can refer to
https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/
which also conatins the main keypoints in a table at last which can be used to revise

->> In brief,
    when the program executes,the main memory divided into three parts.
    One part for code section, the second one is heap memory and another one is stack memory.
    Remember that the program can directly access only the stack memory,
    it can’t directly access the heap memory so we need the help of pointer to access the heap memory.
->> But in short you can say that heap memory can be resised at runtime and stack is determined at compile time
and new keyword returns the address of the memory allocated in heap
->> we have to free up the heap memory  by ourselves
*/

#include <iostream>
using namespace std;

int main()
{

    /*

        // case 1
        while (true)
        {
            int i = 5;
        }// ->> at any instant of time we are taking memory of only one int variable as when the code block of while loop  ends the variables memory is deallocated

        // case 2
        while (true)
        {
            int *ptr = new int(10);
        } // when we declare this type the ptr is stored in stack memry which conains the address of memory in heap which store the int variable
        // when the code of block ends we are not using delete keyword the stack part gets deleted but the memory allocated in heap remains hence it may lead to system crash -> 4 + 4 + 4....
        // this memory is freed using delete keyword

        */

    // for single element
    int *ptr = new int(10);
    delete ptr;

    // for an array
    int *arr = new int[10];
    delete[] arr;

    return 0;
}