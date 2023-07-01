class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n),suffix(n);
        int sum=0;
        //FOR CALCULATING THE PREFIX HEIGHT
        int maxPrefix = INT_MIN;
        for (int i=0; i<n; i++){
            maxPrefix = max(height[i],maxPrefix);
            prefix[i] = maxPrefix;
        }

        //FOR CALCULATING THE SUFFIX HEIGHT
        int maxSuffix = INT_MIN;
        for (int i=n-1; i>=0; i--){
            maxSuffix = max(height[i],maxSuffix);
            suffix[i] = maxSuffix;
        }

        for (int i=0; i<n; i++){
            sum+= min(prefix[i],suffix[i]) - height[i];
        }

        return sum;
        
    }
};