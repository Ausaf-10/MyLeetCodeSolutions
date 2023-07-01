class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long int sum = 0; 
        for (int i=0; i<nums.size(); i++){
            long long maxi = nums[i],  mini = nums[i];
            for (int j=i; j<n; j++){
                if (nums[j] > maxi) maxi = nums[j];
                if (nums[j] < mini) mini = nums[j];
                sum += (maxi - mini);
                
            }
            
        }
        
        return sum;
    }
};