class MinStack {
public:
    stack<long long> stk;
    long long mini;
    MinStack() {
    }
    
    void push(int value) {
        long long val = value;
        if (stk.empty()){
            mini = val;
            stk.push(val);
        }
        else if (val >= mini) stk.push(val);
        else{
            stk.push(2*val*1LL - mini);
            mini = val;
        }
        return;
    }
    
    void pop() {
        if (stk.top() >= mini) stk.pop();
        else{
            // long long el = stk.top();
            mini = 2*mini - stk.top();
            stk.pop();
        }
        return;
    }
    
    int top() {
        if (stk.top() >= mini) return stk.top();
        else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */