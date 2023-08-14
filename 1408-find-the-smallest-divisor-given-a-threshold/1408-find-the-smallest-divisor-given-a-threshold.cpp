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

        int mini = 1;
        int maxi = *max_element(nums.begin(), nums.end());

     
        int low = mini, high = maxi;
        while (low <= high){
            int mid = low + (high - low)/2;
            int reqSum = fun(nums, mid);
            if (reqSum <= k){
                high = mid - 1;
            } 
            else low = mid + 1;
        }
        
        return low;
    }
};