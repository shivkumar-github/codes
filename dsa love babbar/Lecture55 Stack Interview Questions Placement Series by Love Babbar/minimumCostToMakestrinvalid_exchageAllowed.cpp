// https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770?count=25&page=1&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
int findMinimumCost(string str)
{
    // Write your code here
    if (str.size() % 2)
        return -1; // odd number of braces
    int cost = 0;
    stack<int> st;

    // METHOD : 1 TRAVELLING FROM LEFT TO RIGHT
    // int i = 0;
    //   int n = str.size();
    //   while(i<n){ // using while loop so that we can adjust iterator in different cases
    //     if(str[i] == '{'){
    //       st.push(str[i]);
    //       i++;
    //     }
    //     else{
    //       if(!st.empty()){ // if stack is not empty then pop the opening brace and remove those element to make further operations easier
    //         st.pop();
    //         str.erase(i-1,2);
    //         i--; // reset i to starting position
    //       }
    //       else{ // else if stack is empty then change the closing to opening as there are no opening on left
    //         str[i] = '{';
    //         st.push('{');
    //         i++;
    //         cost++;
    //       }
    //     }
    //     n = str.size(); // readjusting size every time
    //   }
    //   return cost+(st.size()/2); // checking when only opening braces are remaining, half of them will be reversed
    //   // if there is no opening bracket to left of the closing bracket then that bracket needs to be reversed
    //   // but like this we can not do anything for opening bracket because for any opening bracket there may or may not be closing bracket on the right (we can not determine as we are travelling from left to right but if we were travelling from right to left then the approach will become vice versa means we have to exchange the {,} in approach)

    // METHOD : 2 travelling from right to left
    int i = str.size() - 1;
    int n = str.size();
    while (i >= 0)
    { // using while loop so that we can adjust iterator in different cases
        if (str[i] == '}')
        {
            st.push(str[i]);
            i--;
        }
        else
        {
            if (!st.empty())
            { // if stack is not empty then pop the opening brace and remove those element to make further operations easier
                st.pop();
                str.erase(i, 2);
                i--; // reset i to starting position
            }
            else
            { // else if stack is empty then change the opening to closing as there are no closing on right
                str[i] = '}';
                st.push('}');
                i--;
                cost++;
            }
        }
        // no need to readjust size in this traverse
    }
    return cost + (st.size() / 2); // WHEN ONLY CLOSING BRACES ARE REMAINING HALF OF THEM MUST BE REVERSED
}

// METHOD : 3 - third approach by babbar remove all valid pair of braces and the remaining expression will be invalid where the cost of remaining will be (a+1)/2 and (b+1)/2

int findMinimumCost(string str)
{
    if (str.size() % 2)
        return -1;
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == '{')
            st.push(c);
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
    }
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
            a++;
        else
            b++;
    }
    return (a + 1) / 2 + (b + 1) / 2;
}
