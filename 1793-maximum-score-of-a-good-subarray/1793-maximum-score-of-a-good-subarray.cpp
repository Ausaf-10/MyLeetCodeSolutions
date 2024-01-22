class Solution {
public:
    vector<int> PSE(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);
        for (int i=0; i<n; i++){
            while (!stk.empty() && arr[i] < arr[stk.top()]) stk.pop();
            if (stk.empty()) ans[i] = -1;
            else ans[i] = stk.top();
            stk.push(i);
        }

        return ans;
    }
    vector<int> NSE(vector<int>& arr){
        int n = arr.size();
        stack<int> stk;
        vector<int> ans(n);
        for (int i=n-1; i>=0; i--){
            while (!stk.empty() && arr[i]<=arr[stk.top()]) stk.pop();
            if (stk.empty()) ans[i] = n;
            else ans[i] = stk.top();
            stk.push(i);
        }

        return ans;
    }
    int maximumScore(vector<int>& arr, int k) {
        int n =arr.size();
        vector<int> pse = PSE(arr);
        vector<int> nse = NSE(arr);
        
        int maxi = -1e9;
        for(int i=0; i<n; i++){
            int leftRange = pse[i]+1, rightRange = nse[i]-1;
            if (leftRange > k || rightRange < k) continue;
            int len = rightRange - leftRange + 1;
            maxi = max(maxi, arr[i]*len);
        }

        return maxi;
    }
};