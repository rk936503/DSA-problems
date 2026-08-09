class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()) s[i]='!'; //problematic
                else st.pop(); //means ')' is present
            }
        }
        while(!st.empty()){
            s[st.top()]='!'; //problematic
            st.pop();
        }

        s.erase(remove(s.begin(), s.end(), '!'), s.end());
        return s;
    }
};