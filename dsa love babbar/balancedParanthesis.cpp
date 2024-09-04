/*
https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
Check for Balanced Brackets in an expression (well-formedness)
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given expression.

Example:

Input: exp = “[()]{}{[()()]()}”
Output: Balanced
Explanation: all the brackets are well-formed

Input: exp = “[(])”
Output: Not Balanced
Explanation: 1 and 4 brackets are not balanced because
there is a closing ‘]’ before the closing ‘(‘
*/

#include <iostream>
#include <stack>
using namespace std;

// look at the image on gfg for better understanding
bool balanced(string exp)
{
    // stack to store previous brackets
    stack<char> st;
    for (int i = 0; i < exp.size(); i++)
    {
        if (st.empty())
        {
            st.push(exp[i]);
        }
        else if (st.top() == '{' && exp[i] == '}' || st.top() == '(' && exp[i] == ')' || st.top() == '[' && exp[i] == ']')
        {
            st.pop();
        }
        else{
            st.push(exp[i]);
        }
    }
    return st.empty();
}

int main()
{
    string exp = "[()]{}{[()()]()}";
    cout<< balanced(exp) << endl;

    return 0;
}