// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        int n = q.size();
        
        stack<int> st;
        // variable for iteration
        int itr = k;
        // push k elements from queue to stack
        while(itr--){
            st.push(q.front());
            q.pop();
        }
        itr = k;
        // push those elements to q again from stack and now they will be in reverse order
        while(itr--){
            q.push(st.top());
            st.pop();
        }
        itr = n-k;
        // take the remaining elements from queue and push them again in queue 
        while(itr--){
            q.push(q.front());
            q.pop();
        }
        return q;
    } // tc = O(n) and sc = O(k)
};