class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) return nums[0]+nums[1]+nums[2];

        int x = 0, diff = INT_MAX;

        sort(nums.begin(),nums.end());

        for (int i=0; i<nums.size(); i++){
            int j = i+1, k = nums.size() - 1;
            while (j < k){
                int sum = 0;    
                sum+= nums[i];
                sum+= nums[j];
                sum+= nums[k];

                if (target == sum) return sum;
                
                int number = abs(target - sum);
                    if (diff > number) {
                        diff =min(diff,number);
                        x = sum;
                    }
                
                else if (sum > target) k--;
                else if (sum < target) j++;

            }
        }

        return x;

    }
};