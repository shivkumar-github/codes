// METHOD: 1 USING O(N) time complexity  In this approach we are storing the minimum element till an element in the main stack in another stack named mins
// i.e. the corresponding minimum element in the stack will be stored in the mins stack
// DOUBT: OUT OF INT RANGE ERROR IN  LEETCODEf
#include <stack>
class MinStack
{
public:
    stack<int> st;
    stack<int> mins;
    MinStack()
    {
    
    }

    void push(int val)
    {
        st.push(val);
        if (mins.empty())
        {
            mins.push(val);
        }
        else
        {
            int mini = mins.top();
            if (val < mini)
            {
                mini = val;
            }
            mins.push(mini);
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            st.pop();
            mins.pop();
        }
    }

    int top()
    {
        if (!st.empty())
            return st.top();
        return -1;
    }

    int getMin()
    {
        return mins.top();
    }
};

// METHOD: 2 IN O(1) tc and sc (using hashing formula)
class MinStack {
public:
    long long min;
    long long val; // using long long as we are also given cases where the values are equal to the range of int hence we need variable that is atleast two times of the int
    
    stack<long long> st;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        this->val = (long long)(val);
        if(st.empty()){
            st.push(val);
            min = val;            
        }
        else{
            if(val>=min){
                st.push(val);
            }
            else{
                st.push((2*this->val - min)); // hashing formula 
                min = val;
            }
        }
    }
    void pop() {
        if(!st.empty()){
            if(st.top()<min){
                min = 2*min - st.top();
            }
            st.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            if(st.top()<min)
                return min;
            
            else return st.top();
        }
        else return -1;    
    }
    
    int getMin() {
        return min;
    }
};