class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size(), i = 0;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        while (i  < n){
            int j = i + 1, k = n-1;
            while (j < k){
                long long s = 0;
                s += arr[i];
                s += arr[j];
                s += arr[k];
                if (s == 0){
                    vector<int> res = {arr[i], arr[j], arr[k]};
                    ans.push_back(res);
                    j++;
                    while (j<k && arr[j-1] == arr[j]) j++;
                    k--;
                    while (j<k && arr[k] == arr[k+1]) k--;
                }
                else if (s > 0){
                    k--;
                } 
                else {
                    j++;
                }
            }
            i++;
            while (i<n && arr[i] == arr[i-1]) i++;
        }
        return ans;
    }
};