using ll = long long int;
class MinStack {
public:
    ll minEle;
    stack<ll> s;
    MinStack() {
        minEle = 1e9;
    }
    
    void push(int value) {
        ll val = value;
        if (s.empty()){
            minEle = val;
            s.push(val);
        }
        else if (val >= minEle){
            s.push(val);
        }
        else{
            s.push(2*val*1ll-minEle);
            minEle = val;
        }
        return ;
    }
    
    void pop() {
        if (s.top() < minEle){
            minEle = 2*minEle*1ll - s.top();
        }
        s.pop();
    }
    
    int top() {
        if (s.top() < minEle){
            return minEle;
        }
        return s.top();
    }
    
    int getMin() {
        return minEle;
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