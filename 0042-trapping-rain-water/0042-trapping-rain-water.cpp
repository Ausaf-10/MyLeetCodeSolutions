class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n),suffix(n);
        int sum=0;
        //FOR CALCULATING THE PREFIX HEIGHT
        prefix[0] = height[0];
        for (int i=1; i<n; i++){
            prefix[i] = max(height[i],prefix[i-1]);
        }

        //FOR CALCULATING THE SUFFIX HEIGHT
        suffix[n-1] = height[n-1];
        for (int i=n-2; i>=0; i--){
            suffix[i] = max(height[i],suffix[i+1]);
        }

        for (int i=0; i<n; i++){
            sum += abs(height[i] - min(prefix[i],suffix[i]));
        }

        return sum;
        
    }
};