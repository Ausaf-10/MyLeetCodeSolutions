class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int maxi = INT_MIN;
        int n = candies.size();
        vector<bool> ans(n,false);
        for (int i=0; i<n; i++) maxi = max(maxi, candies[i]);

        for (int i=0; i<n; i++){
            int a = candies[i] + extra;
            if (a >= maxi) ans[i] =  true;
        }

        return ans;
    }
};