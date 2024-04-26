const int mod = 1e9+7;
class Solution {
public:
    vector<int> adj[10] = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
    int recursion(int indx, int number, vector<int> adj[]){
        if (indx == 0) return 1;
        int ans = 0;
        for  (auto it : adj[number]){
            ans = (ans + recursion(indx-1, it, adj)) % mod;
        }  
        return ans;
    }

    int memoization(int indx, int number, vector<vector<int>> &dp){
        if (indx == 0) return 1;
        if (dp[indx][number] != -1) return dp[indx][number];
        int ans = 0;
        for  (auto it : adj[number]){
            ans = (ans + memoization(indx-1, it, dp)) % mod;
        }  
        return dp[indx][number] = ans;
    }

    int tabulation(int& n){
        vector<vector<int>> dp(n, vector<int>(10,0));
        for (int i=0; i<10; i++){
            dp[0][i] = 1;
        }
    
        for (int indx=1; indx<n; indx++){
            for (int number=0; number<10; number++){
                int ans = 0;
                for (auto it: adj[number]){
                    ans = (ans + dp[indx-1][it]) % mod;
                }
                dp[indx][number] = ans;
            }
        }

        int ans = 0;
        for (int i=0; i<=9; i++){
            ans = (ans + dp[n-1][i]) % mod;
        }
        return ans;
    }

    int knightDialer(int n) {
        if (n == 1 ) return 10;
        return tabulation(n);
    }
};