using ll = long long int;
class Solution {
public:
    ll isPossible(vector<int>& arr, ll number){
        ll hoursRequired = 0;
        for (ll i=0; i<arr.size(); i++){
            hoursRequired =  hoursRequired + ceil(arr[i]/(double)number);
        }
        return hoursRequired;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        ll maxi = *max_element(arr.begin(), arr.end());
        ll low = 1, high = maxi;
        while (low <= high){
            ll mid = low + (high - low)/2;
            ll totalHoursTaken = isPossible(arr,mid);
            if (totalHoursTaken <= (long long)h){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return low;
    }
};