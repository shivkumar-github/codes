//https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack) {
        // code here..
        int top = sizeOfStack-1;
        int ind = sizeOfStack/2;
        stack<int>st;
        for(int i = 0;i<=ind;i++){//pop elements till mid and store it in another stack
            if(i == ind){
                s.pop();
                continue;
            }
            st.push(s.top());
            s.pop();
        }
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
    }/// space and time complexity = O(n) 
	// there is also a recursive way to do the same proble it also has same complexities
	void solve(stack<int>&s, int sizeOfStack, int count){
		int mid = sizeOfStack / 2;
		if(count == mid){
			s.pop();
			return;
		}else{
			int el = s.top();
			s.pop();
			solve(s, sizeOfStack, count + 1);
			s.push(el);
		}
	}
	void deleteMid(stack<int>&s, int sizeOfStack){
		solve(s, sizeOfStack, 0);
	}
};