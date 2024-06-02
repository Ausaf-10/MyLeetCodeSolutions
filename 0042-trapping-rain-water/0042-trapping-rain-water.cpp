class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), left = 0, right = n-1, leftBar = height[0], rightBar = height[n-1], ans = 0;
        while (left <= right){
            if (leftBar <= rightBar){
                if (height[left] > leftBar) leftBar = height[left];
                else{
                    ans += leftBar - height[left];
                    left++;
                }
            }
            else{
                if (height[right] > rightBar) rightBar = height[right];
                else{
                    ans += rightBar - height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};