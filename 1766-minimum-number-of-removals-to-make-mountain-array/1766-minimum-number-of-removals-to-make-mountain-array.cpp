class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr){
        int n = arr.size();
        
        vector<int> dp(n,1);
        vector<int> temp;
        
        temp.push_back(arr[0]);
        
        for (int i=1; i<n; i++){
            if (arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int indx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[indx] = arr[i];
            }
            dp[i] = temp.size();
        }
       
       return dp;
	}
	 
	vector<int> longestDecreasingSubsequence(vector<int>& arr){	       
	    int n = arr.size();
        
        vector<int> dp(n,1);
        vector<int> temp;
        
        temp.push_back(arr[n-1]);
        
        for (int i=n-2; i>=0; i--){
            if (arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int indx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[indx] = arr[i];
            }
            dp[i] = temp.size();
        }
       
       return dp;
	}

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> LIS = longestIncreasingSubsequence(nums);
	    vector<int> LDS = longestDecreasingSubsequence(nums);

        vector<int> temp(n,0);
	    int maxi = -1e9;
	    for (int i=0; i<n; i++){
	        if (LIS[i] > 1 && LDS[i] > 1){
                temp[i] = LIS[i] + LDS[i] - 1;
                maxi = max(maxi, temp[i]);
            }
	        
	    }

        return n - maxi;
        
        
    }
};