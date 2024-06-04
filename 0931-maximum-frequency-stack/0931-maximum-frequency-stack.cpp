class FreqStack {
public:
    unordered_map<int,int> mp;
    vector<stack<int>> arr;
    int maxi;
    FreqStack() {
        maxi = -1;
        arr.resize(100000);
    }
    
    void push(int val) {
        mp[val]++;
        maxi = max(maxi, mp[val]);
        arr[mp[val]-1].push(val);
        return ;
    }
    
    int pop() {
        int x = arr[maxi-1].top(); 
        arr[maxi-1].pop();
        mp[x]--;
        if (mp[x] == 0) mp.erase(x);
        if (arr[maxi-1].size() == 0) maxi--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */