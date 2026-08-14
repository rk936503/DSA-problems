class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDq;
        deque<int> minDq;
        int maxLen = 0;
        int l=0, r=0;
        for(int r=0; r<nums.size(); r++){
            //maintaining decreasing deque for max num from front
            while(!maxDq.empty() && maxDq.back()<nums[r]){
                maxDq.pop_back();
            }
            //maintaining increasing deque for min num from front
            maxDq.push_back(nums[r]);
            while(!minDq.empty() && minDq.back()>nums[r]){
                minDq.pop_back();
            }
            minDq.push_back(nums[r]);
            //if limit exceeds, shrink window
            while(maxDq.front() - minDq.front() > limit){
                if(nums[l] == maxDq.front()) maxDq.pop_front();
                if(nums[l] == minDq.front()) minDq.pop_front();
                l++;
            }
            //current window
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};