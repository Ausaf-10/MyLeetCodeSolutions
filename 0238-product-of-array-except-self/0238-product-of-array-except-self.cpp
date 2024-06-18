class Solution{
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return {arr[0]};
        vector<int> ans(n), prefix(n), suffix(n);
        prefix[0] = arr[0], suffix[n-1] = arr[n-1];
        for (int i=1; i < n; i++){
            prefix[i] = prefix[i-1]*arr[i];
        }
        for (int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1]*arr[i];
        }

        for (int i=0; i<n; i++){
            if (i>0 && i<n-1){
                ans[i] = prefix[i-1] * suffix[i+1];
            }
            else if (i == 0){
                ans[i] = suffix[i+1];
            }
            else if (i == n-1){
                ans[i] = prefix[i-1];
            }
        }
        return ans;
    }

};