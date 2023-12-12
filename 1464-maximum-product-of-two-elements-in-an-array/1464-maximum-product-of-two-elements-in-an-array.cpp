using ll = long long int;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll maxi = INT_MIN;
        for (int i=0; i<nums.size(); i++){
            ll prod = 1;
            for (int j=i+1; j<nums.size(); j++){
                int a = nums[i]-1, b = nums[j] - 1;
                prod = (a*b);
                maxi = max(maxi, prod);
            }
        }
        return maxi;
    }
    
};