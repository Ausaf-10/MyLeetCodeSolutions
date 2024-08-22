class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        // S1->S2;
        // X->S1
        // S2->S1

        if (s1.empty()) s1.push(x);
        else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while (!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        return;
    }
    
    int pop() {
        if (s1.empty()) return -1;
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if (s1.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */