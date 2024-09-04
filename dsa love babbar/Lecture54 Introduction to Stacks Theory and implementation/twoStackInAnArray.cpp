// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class twoStacks {
  public:
    int size = 200;
    int* arr;
    int top1=-1, top2 = size;
    twoStacks() {
        arr = new int[size];
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1+1 == top2){
            cout << "Stack is Full!" << endl;
        }
        arr[++top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top1+1 == top2){
            cout << "Stack is Full!" << endl;
        }
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 == -1){
            return -1;
        }
        return arr[top1--];
    }

    // Function to remove an element from top of the stack2.
    int pop2() {       
        if(top2 == size){
            return -1;
        }
        return arr[top2++];}
};

#include <bits/stdc++.h>
class TwoStack
{
    // array to implement stack
    int *array;

    // indices of two stacks
    int top1 = -1, size, top2;

public:
    TwoStack(int s)
    {
        this->size = s;
        top2 = size;

        // creating array dynamically
        array = new int[size];
    }

    void push1(int num)
    {
        // push only if stack is not oveflowed
        if (top2 > top1 + 1)
            array[++top1] = num;
        // else do nothing
    }

    void push2(int num)
    {
        // push only if stack is not oveflowed
        if (top2 > top1 + 1)
            array[--top2] = num;
        // else do nothing
    }

    int pop1()
    {
        // if stack empty
        if (top1 < 0)
            return -1;

        // else pop
        return array[top1--];
    }
    int pop2()
    {
        // if stack empty
        if (top2 >= size)
            return -1;
        // else pop
        return array[top2++];
    }
};
