class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n = arr.size(), num3 = -1e9;
        stack<int> stk;
        for (int i=n-1; i>=0; i--){
            if (arr[i] < num3) return true;
            while (!stk.empty() && arr[i] > stk.top()){
                num3 = stk.top(); stk.pop();
            }
            stk.push(arr[i]);
        }
        return false;
    }
};