// Algorithm:
//  Create a deque storing indices.
//  Traverse the array from left to right.
//  Remove the front if it is outside the current window:
//       if dq.front() <= i-k
//           pop_front()

//  Remove all elements from the back that are smaller
//    than or equal to the current element:
//       while dq not empty AND nums[dq.back()] <= nums[i]
//           pop_back()

//  Push current index into the deque.

//  Once the first window is complete (i >= k-1):
//       ans = nums[dq.front()]

//  Return ans.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<nums.size(); i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};