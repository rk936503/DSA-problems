class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty()? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& arr){
        vector<int> psee(arr.size());
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        int total = 0;
        const int MOD = 1e9+7;
        for(int i=0; i<arr.size(); i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (left * right * 1LL * arr[i])%MOD)%MOD;
        }
        return total;
    }
};