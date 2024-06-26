class Solution {
public:
    int n,m;
    void convertString(vector<int>& nums1, vector<string>& s1){
        for (auto it : nums1){
            string str = to_string(it);
            s1.push_back(str);
        }
        return ;
    }
    int tabulation(vector<string>& s1, vector<string>& s2){
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for (int indx1=1; indx1<=n; indx1++){
            for (int indx2=1; indx2<=m; indx2++){
                if (s1[indx1-1] == s2[indx2-1]){
                    dp[indx1][indx2] = 1 + dp[indx1-1][indx2-1];
                }
                else{
                    dp[indx1][indx2] = 0;
                }
                maxi = max(maxi, dp[indx1][indx2]);
            }
        }
        return maxi;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<string> s1,s2;
        convertString(nums1, s1);
        convertString(nums2, s2);
        n = s1.size(), m = s2.size();
        return tabulation(s1, s2);

    }
};