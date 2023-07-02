class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>> stk;
        vector<int> ans(n,0);
        
        for (int i=n-1; i>=0; i--){
            int element = temperatures[i];
            while(!stk.empty() && stk.top().first <= element){
                stk.pop();
            }
            if (!stk.empty()) ans[i] = stk.top().second - i;
            stk.push({element,i});
        }
        
        return ans;
    }
};