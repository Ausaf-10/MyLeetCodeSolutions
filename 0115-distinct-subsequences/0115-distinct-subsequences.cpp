using ll = long long int;
class Solution {
public:
    int n, m;
    int recursion(int indx1, int indx2, string s, string t){
        if (indx2 == 0) return 1;
        if (indx1 == 0) return 0;

        int one = 0, two = 0, three = 0;
        if (s[indx1-1] == t[indx2-1]){
            one = recursion(indx1-1, indx2-1, s, t);
            two = recursion(indx1-1, indx2, s, t);
        }  
        else{
            three = recursion(indx1-1, indx2, s, t);
        }

        return one + two + three;
    }
    int tabulation(string s, string t){
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for (int i=0; i<n; i++) dp[i][0] = 1;
        for (int indx1=1; indx1<=n; indx1++){
            for (int indx2=1; indx2<=m; indx2++){
                int one = 0, two = 0, three = 0;
                if (s[indx1-1] == t[indx2-1]){
                    one = dp[indx1-1][indx2-1];
                    two = dp[indx1-1][indx2];
                }  
                else{
                    three = dp[indx1-1][indx2];
                }
                ll s = 0;
                s = one;
                s = s + two;
                s = s + three;
                dp[indx1][indx2] = s;
            }
        }
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        n = s.size(), m = t.size();
        // return recursion(n, m, s, t);
        return tabulation(s, t);
    }
};