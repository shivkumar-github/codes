/*

*/

#include<iostream>
using namespace std;
int main(){
        // we can only create array of a fixed size 
        // for example lets take 10 and now we want to store some elements in array which can have maximum size of 10
         
        int arr[10];
        // suppose elements 23 45 67 89 12 34 56 78 90 42 24
        // now to store these elements in array  of size 10 we will use hashing
        // division method
        // hash function = key % size of array
        // key = element to be stored
        // size of array = 10
        // 23 % 10 = 3 // this element will be stored at index 3
        // 45 % 10 = 5 // this element will be stored at index 5
        // 67 % 10 = 7 // this element will be stored at index 7 and so on
        // and whenever we have two numbers with same hash(collisions) value then we will use linked list to store them
        // for example 23 and 33 both have hash value 3 then we will store them in linked list at index 3
        // we may say that index is key here
        
        return 0;
}