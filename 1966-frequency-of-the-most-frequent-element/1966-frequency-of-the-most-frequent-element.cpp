using ll = long long int;
class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        int n = arr.size(), i = 0, j = 0, maxi = 0;
        ll s = 0;
        sort(arr.begin(), arr.end());
        while (j < n){
            s = s + arr[j];
            while (((j-i+1)*1ll*arr[j] - s) > k){
                s = s - arr[i];
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};