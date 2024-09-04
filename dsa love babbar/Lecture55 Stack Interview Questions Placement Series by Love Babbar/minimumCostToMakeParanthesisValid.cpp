// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
// on leetcode we are to find numer of paranthesis to be added in the expression
class Solution {
public:
    int minAddToMakeValid(string s) {
        if(!s.size()){
            return 0;
        }
        stack<char>st;
        int cost = 0;
        for(auto i : s){
            if(i == '(')
                st.push(i);
            else{// character is closing bracket
                if(!st.empty()){// if our stack contains opening brackets
                    st.pop();
                    continue;
                }
                else{// else a bracket needs to be added 
                    cost++;
                }
                
            }
        }
        while(!st.empty()){ // if there are more opening brackets than the closing bracket
            st.pop();
            cost++;
        }
        return cost;
    }
};