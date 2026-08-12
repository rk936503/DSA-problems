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
    vector<vector<int>> freqStack;
    int maxFreq;
    FreqStack() {
        maxFreq=0;
        freqStack.resize(20000 + 1);
    }
    
    void push(int val) {
        int freq = freqMap[val]+1;
        freqMap[val] = freq;

        maxFreq = max(freq, maxFreq);

        freqStack[freq].push_back(val);
    }
    
    int pop() {
        int val = freqStack[maxFreq].back();
        freqStack[maxFreq].pop_back();

        freqMap[val]--;

        if(freqStack[maxFreq].empty()){
            maxFreq--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */