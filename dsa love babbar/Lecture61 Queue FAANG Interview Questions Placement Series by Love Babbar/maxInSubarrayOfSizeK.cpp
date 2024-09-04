// https://leetcode.com/problems/sliding-window-maximum/
#include<bits/stdc++.h>

class Solution {
public:
/*
    Thinking: 
    1. We need two pointers which will keep track of the start and end of window.(to handle each insertion)
    2. We need a data structure which will give the first inserted element first and then remove the first inserted from the front and insert a new element that is added to the window from the back, so we will use deque (dq).
    3. We have a dq which we have to use to get somehow the maximum element in a subarray from that dq.
    4. For that, we have to insert each element in dq.
    5. But we don't need the elements which are inserted before that element (element which is to be inserted now) and are smaller than that element as they won't be the answer now.
    6. So while inserting an element, we pop all the elements in dq which are smaller than that element and then insert that element.
    7. Each time the window size reaches k (determined by the difference between two pointers), the element at the front will be the maximum element in that window; hence, store that in the ans vector.
    Note that there will not be any smaller element in dq which is before that element, but the elements smaller and after that element will be there as they can be an answer for the next window.
    8. Each time when we store max, check if the max is the starting element. If yes, then pop the element out from dq.
    9. In this approach, we are not keeping the size of the window as k; instead, we are checking only when the size is k.
*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; 
        int i = 0; // For keeping track of the starting point of the subarray
        int j = 0; // Ending point of the subarray
        while (j < n) {
            while (!dq.empty() && dq.back() < nums[j]) { // Pop the elements that are smaller than the current element (don't pop when equal; otherwise, there will be only 1 element in dq for more than 1 max element, and that will be popped, leading to a wrong max result ([1,3,3,-1,2,5,3] - try running this after placing equal to, and then try; you will understand then))
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if (j - i + 1 == k) { // When the subarray length becomes k
                int el = dq.front();
                if (el == nums[i]) // If it is the first element, then pop it out from dq
                    dq.pop_front();
                ans.push_back(el);
                i++;
            }
            j++;
        }
        return ans;
    }
};
