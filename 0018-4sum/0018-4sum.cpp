class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0;
        while (i < n){
            int j = i + 1  ;
            while (j < n){
                int k = j + 1, l = n - 1;
                while (k < l){
                    long long int sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k]; 
                    sum+=nums[l];
                    if (sum > target) l--;
                    else if (sum < target) k++;
                    else{
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++,l--;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        while (k < l && nums[l] == nums[l+1]) l--;
                        
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j-1]) j++; 
            }
            i++;
            while (i < n && nums[i] == nums[i-1]) i++;
                
        }
        
        return ans;
    }
};