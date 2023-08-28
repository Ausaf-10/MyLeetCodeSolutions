class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        if (q.empty()){
            q.push(x);
            return ;
        }
        q.push(x);
        int size = q.size();
        for (int i=0; i<size-1; i++){
            int x = q.front();
            q.pop();
            q.push(x);
        }

        return ;
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */