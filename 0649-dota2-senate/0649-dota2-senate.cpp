class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qR;
        queue<int> qD;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                qR.push(i);
            else
                qD.push(i);
        }
        while (!qR.empty() && !qD.empty()) {

            int r = qR.front();
            int d = qD.front();

            qR.pop();
            qD.pop();

            if (r < d) {
                qR.push(r + n);
            }
            else {
                qD.push(d + n);
            }
        }

        return qR.empty() ? "Dire" : "Radiant";
    }
};