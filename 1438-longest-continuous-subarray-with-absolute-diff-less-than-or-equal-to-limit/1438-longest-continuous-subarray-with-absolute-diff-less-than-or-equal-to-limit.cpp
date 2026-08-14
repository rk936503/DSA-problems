class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDq;
        deque<int> minDq;
        int maxLen = 0;
        int l=0, r=0;
        for(int r=0; r<nums.size(); r++){
            while(!maxDq.empty() && maxDq.back()<nums[r]){
                maxDq.pop_back();
            }
            maxDq.push_back(nums[r]);
            while(!minDq.empty() && minDq.back()>nums[r]){
                minDq.pop_back();
            }
            minDq.push_back(nums[r]);
            while(maxDq.front() - minDq.front() > limit){
                if(nums[l] == maxDq.front()) maxDq.pop_front();
                if(nums[l] == minDq.front()) minDq.pop_front();
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};