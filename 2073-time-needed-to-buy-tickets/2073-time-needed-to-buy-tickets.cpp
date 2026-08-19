class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i=0; i<tickets.size(); i++){
            q.push({i, tickets[i]});
        }
        int time=0;
        while(!q.empty()){
            int idx=q.front().first;
            int remaining=q.front().second;
            q.pop();

            remaining--;
            time++;

            if(idx==k && remaining==0){
                return time;
            }
            if(remaining>0){
                q.push({idx, remaining});
            }
        }
        return time;
    }
};