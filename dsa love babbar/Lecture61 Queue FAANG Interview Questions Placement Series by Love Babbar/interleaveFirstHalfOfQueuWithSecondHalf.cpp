// https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1


// METHOD: 1 By using queue
    // by using queue
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        int halfsize = n/2;
        vector<int> ans;
        queue<int> q1;
        int itr1 = halfsize;
        while(itr1--){
            q1.push(q.front());
            q.pop();
        }
        for(int i = 0;i<halfsize;i++){
            ans.push_back(q1.front());
            ans.push_back(q.front());
            q1.pop();
            q.pop();
        }
        // return the ans
        return ans;
    }
};

// METHOD: 2 By using only ans vector
class Solution{
public:
    // without using q or any stack (using array)
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        int halfsize = n/2;
        vector<int> ans;
        // first store them in ans vector
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        // then push the elements from the queue in order required
        for(int i = 0;i<halfsize;i++){
            q.push(ans[i]);
            q.push(ans[i+halfsize]);
        }
        // then store the ans from q to ans vector
        for(int i = 0;i<n;i++){
            ans[i] = q.front();
            q.pop();
        }
        // return the ans
        return ans;
    }
};

// METHOD: 3 by using stack
class Solution{
public:
    // by using queue
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        int halfsize = n/2;
        vector<int> ans;
        stack<int> st;
        int itr1 = halfsize;
        
		// first push half element in the stack
        while(itr1--){
            st.push(q.front());
            q.pop();
        }
		// then push them again in q ( now they will be in reversed order )
        itr1 = halfsize;
        while(itr1--){
            q.push(st.top());
            st.pop();
        }
		// again push the elements at the front of the queue again in queue (the second half elements which were present initially in q)
        itr1 = n - halfsize;
        while(itr1--){
            q.push(q.front());
            q.pop();
        }
		// then now push first half element in stack(these are the first half but in reversed order)
        itr1 = halfsize;
        while(itr1--){
            st.push(q.front());
            q.pop();
        }
		// now choose each element from stack and then q and push in ans
        while(!q.empty() && !st.empty()){ // as in problem  it is given that queue is of even length both st and q will be of equal size
            ans.push_back(st.top());
            ans.push_back(q.front());
            st.pop();
            q.pop();
        }
        // return the ans
        return ans;
    }
};