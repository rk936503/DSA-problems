// push(val):
//  Increase frequency of val.
//  Update maxFreq.
//  Push val into the stack corresponding to its new frequency.

// pop():
//  Take the stack corresponding to maxFreq.
//  The top element is the most recently pushed element
//    -having the highest frequency.
//  Pop it.
//  Decrease its frequency in freqMap.
//  If that frequency stack becomes empty:
//       -decrease maxFreq.
//  Return the popped element.
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