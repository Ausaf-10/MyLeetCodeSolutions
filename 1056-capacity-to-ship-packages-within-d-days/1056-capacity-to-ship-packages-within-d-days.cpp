using ll = long long int;
class Solution {
public:
    int fun(vector<int>& wt, int cap){
        int days = 1, load = 0;
        for (int i=0; i<wt.size(); i++){
            if (load + wt[i] > cap){
                days = days + 1;
                load = wt[i];
            }
            else load += wt[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& wt, int days) {
        ll n = wt.size();
        ll min_range = *max_element(wt.begin(), wt.end());
        ll max_range = 0;
        for (auto it : wt) max_range += it;

        ll low = min_range, high = max_range;
        
        while (low <= high){
            ll mid = low + (high - low)/2;
            int reqDays = fun(wt, mid);
            if (reqDays <= days){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return low;
    }
};