class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i=n-1; i>=0; i--){
            while (!stk.empty() && stk.top() > arr[i]) stk.pop();
            if (stk.empty()) ans[i] = arr[i];
            else ans[i] = arr[i] - stk.top();
            stk.push(arr[i]);
        }
        return ans;
    }
};