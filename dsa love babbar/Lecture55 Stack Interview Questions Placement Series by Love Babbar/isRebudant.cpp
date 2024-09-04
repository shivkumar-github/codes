// https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution
{
public:
    bool op(char c)
    {
        return (c == '*' || c == '/' || c == '-' || c == '+');
    }
    int checkRedundancy(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {

            char c = s[i];

            if (c == '(' || op(c)) // opening char
                st.push(c);

            else if (c == ')') // closing bracket
            {
                if (op(st.top()))
                {
                    while (op(st.top()))
                    {             // operator present at top
                        st.pop(); // removing operator from stack
                    }
                    st.pop(); // removing 1 opening brace
                }
                else
                {
                    return 1;
                }
            } // do nothin for alphabet
        }
        return 0;
    }
};

class Solution
{
public:
    bool isOpening(char c)
    {
        return c == '(';
    }
    bool isClosing(char c)
    {
        return c == ')';
    }
    bool op(char c)
    {
        return (c == '*' || c == '/' || c == '-' || c == '+');
    }
    int checkRedundancy(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(' || op(c))
                st.push(c);
            else if (c == ')') // closing bracket
            {
                if (op(st.top()))
                {
                    while (op(st.top()))
                    {             // operator present at top
                        st.pop(); // removing operator from stack
                    }
                    st.pop(); // removing 1 opening brace
                }
                else
                {
                    return 1;
                }
            }
            else // character eat 5 star
                continue;
        }
        return 0;
    }
};

class Solution
{
public:
    // time complexity = O(n)
    // space complexity = O()
};
using namespace std;