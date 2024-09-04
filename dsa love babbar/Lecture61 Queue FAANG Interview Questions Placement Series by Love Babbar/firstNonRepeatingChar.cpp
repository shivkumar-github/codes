// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
class Solution {
	public:
	string FirstNonRepeating(string A){
	    int n = A.size();
	    string ans = "";
	    vector<int> oc(26, false); // vector to store if an element is previously occured or not
	    queue<char> q; // queue to store the cahrcters which have not occucred twice till that position 
	    for(int i = 0;i<n;i++){ 
	        char ch = A[i];
	        if(!q.empty() && ch == q.front()) q.pop(); // if the queue is not empty and the front charcter is equal to the cur char then it is it's second occurance hence remove it from q(we don't need to use while as that element will be occuring once in q as we are pushing in q only when it is it's first occurance)
	        if(!oc[ch]) q.push(ch); // if the charcter is occuring for first time then push it in stack
	        if(!q.empty()) ans.push_back(q.front()); // now the element remaining at the front will be answer
		    else ans.push_back('#'); // else no answer hence push #
            oc[ch] = true; // flag the character
	    }
	    return ans;
	}
};
