using ll = long long int;
class Solution {
public:
    // AGGRESSIVE COWS!!
    bool isPossible(vector<int> &stalls, ll dist, ll k){
        ll lastCow = 0; 
        k-=1;
        ll i = 1;
        while (i < stalls.size() && k!=0){
            ll reqDist = stalls[i] - stalls[lastCow];
            if (reqDist >= dist){
                lastCow = i;
                k-=1;
                i++;
            }
            else{
                i++;
            }
        }
        
        if (k!=0) return false;
        
        return true;
    }

    int maxDistance(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());
        ll maxi = *max_element(stalls.begin(), stalls.end());
        ll mini = *min_element(stalls.begin(), stalls.end());
        
        ll low = 1, high = maxi-mini;
        
        while (low <= high){
            ll mid = low + (high - low)/2;
            if (isPossible(stalls,mid,k)){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return high;
    }
};