using ll = long long int;
class Solution {
public:
    int fun(vector<int>& arr, int d){
        int sum = 0;
        for (int i=0; i<arr.size(); i++){
            sum+= ceil((double)arr[i]/(double)d);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int k) {
        int n = nums.size();

        // int mini = *min_element(nums.begin(), nums.end());
        ll low = 1;
        ll high = *max_element(nums.begin(), nums.end());

        while (low <= high){
            ll mid = low + (high - low)/2;
            // CHECK WHETHER IT IS POSSIBLE OR NOT
            
            ll reqTime = fun(nums,mid);
            
            if (reqTime<=k){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};