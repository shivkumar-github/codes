#include <bits/stdc++.h>
using namespace std;
// METHOD : by me
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty()) // if stack empty then push
            st.push(arr[i]);
        else if (arr[i] > st.top())
        { // if this condition is satisfied then top is answer for i th index element
            ans[i] = st.top();
            st.push(arr[i]); // also push that element in stack (as it could be smaller for another el)
        }
        else
        { // if top is greater then pop until we find smaller or the stack becomes empty
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (!st.empty()) // if stack not empty then element is found so store the answer
                ans[i] = st.top();
            else // else no answer exists
                ans[i] = -1;
            st.push(arr[i]); // push this el also to stack
        }
    }
    return ans;
} // time complexity = O(n)
// space complexity = O(n) for stack and ans vector
// we are iterating in reverse order becuase we need the index of greater element and value of smaller element to store in ans if we traverse in forward direction we will get index of smaller el and value of greater one
// also if we were to find value of previous smaller el then we will traverse from front

// also  doubt - if we are popping element if smaller element is not found for index i then for upcoming indices (which are less than i) the smaller exists in that stack
// ans - no need as the curr element is smaller than all of them and is pushed in stack hence for upcoming indices the ans will be cur index or lesser than that

// SHORT METHOD : by babbar in this approach all cases are handled automatically as all elements are positive and last element is -1 ,the elements for which answer doesn't exist automatically gets last element of stack as answer i.e. -1
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> ans(n, -1);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        ans[i] = st.top();
        s.push(curr);
    }
    return ans;
} // same time complexity as above approach (both approaches are same just i written extra waste)
