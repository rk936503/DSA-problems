class MyCircularQueue {
public:
    vector<int> arr;
    int start, end, size, currSize;
    MyCircularQueue(int k) {
        arr.resize(k);
        size=k;
        currSize=0;
        start=-1,end=-1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(currSize == 0){
            start=0;
            end=0;
        }
        else{
            end = (end+1) % size;
        }
        arr[end]=value;
        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(currSize == 1){
            start=-1;
            end=-1;
        }
        else start = (start+1) % size;
        currSize--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[start];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[end];
        
    }
    
    bool isEmpty() {
        return currSize==0;
    }
    
    bool isFull() {
        return currSize==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */