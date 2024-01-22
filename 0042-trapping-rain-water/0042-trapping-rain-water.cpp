class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1, ans = 0;
        int leftMax = arr[0], rightMax = arr[n-1];
        
        while (left <= right){
            if (leftMax <= rightMax){
                if (arr[left] > leftMax) leftMax = arr[left];
                else{
                    ans+=leftMax - arr[left];
                    left++;
                }
            }
            else{
                if (arr[right] > rightMax) rightMax = arr[right];
                else{
                    ans+=rightMax - arr[right];
                    right--;
                }
            }
        }
        
        
        return ans;
    }
};