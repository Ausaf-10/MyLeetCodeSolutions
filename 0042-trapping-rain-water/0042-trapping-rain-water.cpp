class Solution {
public:
    int trap(vector<int>& arr) {
        int ans =0 ;
        int l = 0, r = arr.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (l <= r){
            if (arr[l]<=arr[r]){
                if (arr[l] >= leftMax) leftMax = arr[l];
                else ans+= leftMax - arr[l];
                l++;
            }
            else{
                if (arr[r] >= rightMax) rightMax = arr[r];
                else ans+= rightMax - arr[r] ;
                r--;
            }
        }
        return ans;
    }
};