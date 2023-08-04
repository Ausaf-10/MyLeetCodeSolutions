class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n,1), freq(n), print;
        
        for (int i=0; i<n; i++) freq[i] = i;
        
        int maxi = 1, lastIndx = 0;
        for (int i=0; i<n; i++){
            for (int j = 0; j<i; j++){
                if (nums[i] % nums[j] == 0){
                    if (dp[i] < 1 + dp[j] ){
                        dp[i] = 1 + dp[j];
                        freq[i] = j;
                    }
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];
                lastIndx = i;
            }
        }

        print.push_back(nums[lastIndx]);
		while (lastIndx!=freq[lastIndx]){
            lastIndx = freq[lastIndx];
            print.push_back(nums[lastIndx]);
        }
           
        reverse(print.begin(), print.end());
        
        return print;
    }
};