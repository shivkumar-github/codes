/*
reverse queue
https://www.geeksforgeeks.org/problems/queue-reversal/1
*/

// METHOD: 1 USING STACK
// As we are told to reverse we will use stack as anything inserted in stack comes out in reversed order
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        return q;
    }
}; // tc and sc both O(n)

class Solution
{
    public:
    void reverse(queue<int>& q){
        if(q.empty()) return;
        int tp = q.front();
        q.pop();
        reverse(q);
        q.push(tp);
    }
    queue<int> rev(queue<int> q)
    {
        reverse(q);
        return q;
    }
}; // same tc and sc

// this method gives error because in this method we are passing q using pass by value which creates copy of queue which is time consuming specially in cases  where q is large and in our first approach we are passing it by reference so no copying is involved hence it gives lesser time complexity
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        if(q.empty()) return q;
        int tp = q.front();
        q.pop();
        q = rev(q);
        q.push(tp);
        return q;
    }
}; 