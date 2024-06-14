class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        int n = arr.size();
        vector<int> freq(1000000, 0);
        for (auto it : arr) freq[it]++;
        int ans = 0;
        sort(arr.begin(), arr.end());
        int i = 0, j = 0;
        while (i < n){
            if (arr[i] > j){
                j++;
                continue;
            }
            if (freq[arr[i]] == 1){
                i++;
                continue;
            }
            if (freq[j] == 0){
                freq[j] = 1; freq[arr[i]]--;
                ans += abs(j - arr[i]);
                i++,j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};