const int mod = 1e9+7;
class Solution {
public:
    int recursion(int indx){
        if (indx == 0) return 1;
        if (indx == 1) return 2;
        int pick = 0;
        pick = recursion(indx-2);
        int notPick = recursion(indx-1);
        return pick + notPick;
    }
    int tabulation(int n){
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 2;
        for (int indx=2; indx<=n; indx++){
            int pick = 0;
            pick = dp[indx-2];
            int notPick = dp[indx-1];
            dp[indx] = (pick + notPick)%mod;
        }
        int x = dp[n];
        return (x*1ll*x)%mod;
    }
    int countHousePlacements(int n) {
        return tabulation(n);
    }
};