class Solution {
public:
    int spaceOptimisation(int start,vector<int> arr, int n){
        int prev = arr[start], prev2 = 0;
        for (int i = start + 1; i < n; i++){
            int pick = arr[i] ;
            if (i > 1) pick += prev2;
            int notPick = 0 + prev;
            int cur = max(pick,notPick);
            prev2 = prev, prev = cur; 
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0]; 

        int ans1 = spaceOptimisation(0,nums,n-1);
    
        //excluding the first element
        int ans2 = spaceOptimisation(1,nums,n);

        return max(ans1,ans2);
    }
};