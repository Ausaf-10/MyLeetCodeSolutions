class Solution {
public:
    int n, target;
    int memoization(int indx, int remWidth, int maxHeight, vector<vector<int>>& books, vector<vector<int>> &dp){
        if (indx == n) return maxHeight;
        if (dp[indx][remWidth] != -1) return dp[indx][remWidth];
        int bookHeight = books[indx][1], bookWidth = books[indx][0], one = INT_MAX, two = INT_MAX;
        if (bookWidth <= remWidth){
            one = memoization(indx+1, remWidth-bookWidth, max(maxHeight, bookHeight), books, dp);
        }
        two = maxHeight + memoization(indx+1, target-bookWidth, bookHeight, books, dp);
        return dp[indx][remWidth] = min(one,two); 
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size(), target = shelfWidth;
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return memoization(0, shelfWidth, 0, books, dp);
       
    }
};