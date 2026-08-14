class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        dq.push_back(0);
        for(int i=1; i<nums.size(); i++){
            //removing indices outside the window
            while(!dq.empty() && dq.front() < i-k){
                dq.pop_front();
            }
            //best previous score
            ans[i] = nums[i] + ans[dq.front()];
            //maintaining decreasing order 
            while(!dq.empty() && ans[dq.back()] <= ans[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return ans[ans.size()-1];
    }
};