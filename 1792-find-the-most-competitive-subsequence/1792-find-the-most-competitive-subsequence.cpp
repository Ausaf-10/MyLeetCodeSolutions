class Solution {
public:
    vector<int> mostCompetitive(vector<int>& arr, int k) {
        int n = arr.size();
        k = n-k;
        stack<int> stk;
        for (int i=0; i<n; i++){
            while (!stk.empty() && k!=0 && arr[stk.top()] > arr[i]) {
                stk.pop(); k--;
            }
            stk.push(i);
        }
        while (!stk.empty() && k!=0){
            stk.pop(); k--;
        }
        vector<int> ans;
        while (!stk.empty()){
            ans.push_back(arr[stk.top()]);
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};