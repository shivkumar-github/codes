// https://www.geeksforgeeks.org/problems/reverse-a-stack/1
class Solution{
public:
// basic logic -> if beggining two elements of stack are decreasing (like 5 and then 4) then swap both by popping out and pushing (push 5 first and then 4)
// but if first two are in increasing(reverse of the original i.e. as we want in our answer) order(compared to sequence of both elements in original stack) (4,5) then first pop 4 and then go for the remaining stack as mentioned in step 1
// if there are n elements in stack then repeat this for n times
    void solve(stack<int>& st){
        if(st.empty())
            return;
        int el1 = st.top();
        st.pop();
        if(st.empty()){
            st.push(el1);
            return;
        }
        int el2 = st.top();
        st.pop();
        solve(st);
        st.push(el1);
        st.push(el2);
    }
    void Reverse(stack<int> &St){
        int size = St.size();
        for(int i = 0;i<size;i++){
            if(i%2){
            int el = St.top();
            St.pop();
            solve(St);
            St.push(el);
            }
            else{
                solve(St);
            }

        }
    }
	void insertAtBottom(stack<int>&st, int x){
		if(stack.empty()){
			st.push(x);
			return;
		}
		int el = st.top();
		st.pop();
		insertAtBottom(st, x);
		st.push(el);
	}
	void Reverse(stack<int>& St){
		if(st.empty()){
			return;
		}
		int top = st.top();
		Reverse(st);
		insertAtBottom(st, top);
	}
};