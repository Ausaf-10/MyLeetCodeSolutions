class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        int n = arr.size(), maxi = *max_element(arr.begin(), arr.end()), ans = 0;
        vector<int> freq(n+maxi, 0);
        for (auto it : arr) freq[it]++;
        for (int i=0; i<freq.size(); i++){
            if (freq[i] <= 1) continue;
            int extra = freq[i]-1;
            ans+=extra; freq[i+1] += extra;
        }
        return ans;
    }
};