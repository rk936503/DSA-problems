class FreqStack {
public:
    unordered_map<int,int> freqMap;
    unordered_map<int, stack<int>> freqStack;
    int maxFreq;
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {
        int freq = freqMap[val]+1;
        freqMap[val] = freq;

        maxFreq = max(freq, maxFreq);

        freqStack[freq].push(val);
    }
    
    int pop() {
        stack<int>& st = freqStack[maxFreq];

        int topEle = st.top();
        st.pop();

        freqMap[topEle]--;

        if(st.empty()){
            maxFreq--;
        }

        return topEle;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */