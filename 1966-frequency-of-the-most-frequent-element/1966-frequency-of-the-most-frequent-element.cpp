using ll = long long int;
class Solution {
public:
    int n;
    bool fun(ll mid, ll indx, vector<ll> &preSum, vector<int> &arr, int k){
        int len = indx-mid+1;
        ll operations, newSum = arr[indx]*1ll*len ;
        operations = mid != 0 ? newSum - (preSum[indx]-preSum[mid-1]) : newSum - preSum[indx];
        if (operations <= k) return true;
        return false;
    }
    int maxFrequency(vector<int>& arr, int k) {
        n = arr.size();
        vector<ll> preSum(n,0);
        sort(arr.begin(), arr.end());
        preSum[0] = arr[0];
        for (int i=1; i<n; i++){
            preSum[i] =  preSum[i-1] + arr[i];
        }
        int maxi = 1;
        for(ll i=1; i<n; i++){
            int low = 0, high = i;
            while (low <= high){
                ll mid = low + (high-low)/2;
                if (fun(mid, i, preSum, arr, k)) high = mid - 1;
                else low = mid + 1;
            }
            maxi = max(maxi, int(i-low+1));
        }
        return maxi;
    }
};