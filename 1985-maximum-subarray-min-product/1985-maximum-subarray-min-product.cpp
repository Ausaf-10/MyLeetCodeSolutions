using ll = long long int;
const int mod = 1e9+7;
class Solution {
public:
    int n;
    vector<int> PSE(vector<int>& arr){
        stack<int> stk;
        vector<int> ans(n);
        for (int i=0; i<n; i++){
            while (!stk.empty() && arr[i] < arr[stk.top()]) stk.pop();
            if (stk.empty()) ans[i] = 0;
            else ans[i] = stk.top()+1;
            stk.push(i);
        }

        return ans;
    }
    vector<int> NSE(vector<int>& arr){
        stack<int> stk;
        vector<int> ans(n);
        for (int i=n-1; i>=0; i--){
            while (!stk.empty() && arr[i]<=arr[stk.top()]) stk.pop();
            if (stk.empty()) ans[i] = n-1;
            else ans[i] = stk.top()-1;
            stk.push(i);
        }

        return ans;
    }
    int maxSumMinProduct(vector<int>& arr) {
        n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> pse = PSE(arr);
        vector<ll> preSum(n, 0);
        preSum[0] = arr[0];
        for (int i=1; i<n; i++){
            preSum[i] = preSum[i-1] + arr[i]; 
        }
        ll maxi = -1e9;
        for (int i=0; i<n; i++){
            int leftRange = pse[i], rightRange = nse[i];
            ll sum = preSum[rightRange];
            if (leftRange - 1 >= 0){
                sum -= preSum[leftRange-1];
            }
            maxi = max(maxi, (arr[i]*1ll*sum));
        }
        return maxi%mod;
    }
};