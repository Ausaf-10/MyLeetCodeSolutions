using ll = long long int;
class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k){
        int cnt = 0, bouqets = 0;
        for (int i=0; i<arr.size(); i++){
            if (arr[i]<=day) cnt++;
            else{
                bouqets+=cnt/k;
                cnt = 0;
            }
        }
        bouqets+=cnt/k;
        if (bouqets >= m) return true;
        return false;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        long long a = m, b = k;
        long long res = a * b;
        if (res > n) return -1;

        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
       
        int ans = -1;
        bool flag = false;
        // for (int i=mini; i<=maxi; i++){
        //     if (possible(arr,i,m,k)){
        //         ans = i;
        //         break;
        //     }
        // }
       
        int low = mini, high = maxi;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (possible(arr,mid,m,k)){
                ans = mid, high = mid - 1, flag = true;
            }
            else low = mid + 1;
        }

        if (flag) return ans;
        return  -1;

        return ans;
    }
};