class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), i = 0, j = 0, ans = 0, s = 0;
        while (j<n){
            s += arr[j];
            if (j-i+1 < k) j++;
            else{
                if (s/k >= threshold) ans++;
                s-=arr[i];
                i++,j++;
            }
        }
        return ans;
    }
};