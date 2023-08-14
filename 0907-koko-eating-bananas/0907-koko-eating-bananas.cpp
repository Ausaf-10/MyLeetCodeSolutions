using ll = long long int;
class Solution {
public:
    ll fun(vector<int>& arr, int hour){
        long long totTime = 0;
        for (int i=0; i<arr.size(); i++){
            totTime += ceil((double)arr[i]/(double)hour);
        }
        return totTime;
    }
    int minEatingSpeed(vector<int>& arr, int h){
        ll maxi = *max_element(arr.begin(), arr.end());
        ll low = 1, high = maxi;
        while (low <= high){
            ll mid = low + (high - low)/2;
            // CHECK WHETHER IT IS POSSIBLE OR NOT
            ll reqTime = fun(arr,mid);
            if (reqTime<=h){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};