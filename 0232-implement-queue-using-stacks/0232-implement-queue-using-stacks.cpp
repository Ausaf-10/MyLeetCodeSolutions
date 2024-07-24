class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        return ;
    }
    
    int pop() {
        int x;
        if (!s2.empty()){
            x = s2.top();
            s2.pop();
        }
        else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            x = s2.top();
            s2.pop();
        }
        return x;
    }
    
    int peek() {
        int x;
        if (!s2.empty()){
            x = s2.top();
        }
        else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            x = s2.top();
        }
        return x;
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) return true;
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