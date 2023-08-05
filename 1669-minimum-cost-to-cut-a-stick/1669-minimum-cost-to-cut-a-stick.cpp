class Solution {
public:
    int recursion(int i, int j,vector<int>& cuts){
        if (i > j) return 0;
        int mini = 1e9;
        for (int indx = i; indx<=j; indx++){
            int cost = cuts[j+1] - cuts[i-1] + recursion(i, indx-1, cuts) + 
            recursion(indx + 1, j, cuts);
            mini = min(mini, cost);
        }

        return mini;
    }
    
    int memoization(int i, int j,vector<int>& cuts, vector<vector<int>>& dp){
        if (i > j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for (int indx = i; indx<=j; indx++){
            int cost = cuts[j+1] - cuts[i-1] + memoization(i, indx-1, cuts, dp) + 
            memoization(indx + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        vector<vector<int>> dp(c+1, vector<int>(c+1,-1));
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        return memoization(1, c, cuts, dp);
    }
};