class Solution {
public:
    int n;
    int recursion(int noCharactersOnScreen, int copiedCharacters){
        if (noCharactersOnScreen > n) return 1e9;
        if (noCharactersOnScreen == n) return 0;
        int copy = 1e9, paste = 1e9;
        // COPY
        if (noCharactersOnScreen > copiedCharacters){
            copy = 1 + recursion(noCharactersOnScreen, noCharactersOnScreen);
        }
        // PASTE
        if (copiedCharacters != 0){
            paste = 1 + recursion(noCharactersOnScreen+copiedCharacters, copiedCharacters);
        }
        return min(copy, paste);
    }
    int memoization(int noCharactersOnScreen, int copiedCharacters, vector<vector<int>> &dp){
        if (noCharactersOnScreen > n) return 1e9;
        if (noCharactersOnScreen == n) return 0;
        if (dp[noCharactersOnScreen][copiedCharacters]!=-1) return dp[noCharactersOnScreen][copiedCharacters];
        int copy = 1e9, paste = 1e9;
        // COPY
        if (noCharactersOnScreen > copiedCharacters){
            copy = 1 + memoization(noCharactersOnScreen, noCharactersOnScreen, dp);
        }
        // PASTE
        if (copiedCharacters != 0){
            paste = 1 + memoization(noCharactersOnScreen+copiedCharacters, copiedCharacters, dp);
        }
        return dp[noCharactersOnScreen][copiedCharacters] = min(copy, paste);
    }
    int minSteps(int N) {
        n = N;
        vector<vector<int>> dp(2*n+1, vector<int>(n+2,-1));
       return memoization(1, 0, dp);
    }
};