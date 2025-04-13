class Solution {
public:
    int atMost(vector<int>& arr, int k){
        int n = arr.size(), cnt = 0, ans = 0, i = 0, j = 0;
        while (j < n){
            if (arr[j]&1) cnt++;
            while (cnt > k){
                if (arr[i]&1) cnt--;
                i++;
            }
            ans = ans + j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int k) {
        return atMost(arr, k) - atMost(arr, k-1);
    }
};