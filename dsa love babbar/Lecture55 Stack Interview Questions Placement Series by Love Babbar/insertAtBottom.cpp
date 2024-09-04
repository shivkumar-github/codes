// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/0
class Solution
{
public:
    stack<int> insertAtBottom(stack<int> st, int x)
    {
        stack<int> s;
        while (!st.empty())
        {
            s.push(st.top());
            st.pop();
        }
        st.push(x);
        while (!s.empty())
        {
            st.push(s.top());
            s.pop();
        }
        return st;
    } // same code can be written using recursion with same time and space complexity

    stack<int> insertAtBottom(stack<int> st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return st;
        }
        int el = st.top();
        st.pop();
        st = insertAtBottom(st, x);
        st.push(el);
        return st;
    }// both have same TC and SC
};