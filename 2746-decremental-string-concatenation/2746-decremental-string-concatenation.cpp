class Solution {
public:
    int n;
    int recursion(int indx, char start, char end, vector<string>& words){
        if (indx >= n) return 0;

        char curStart = words[indx][0];
        char curEnd = words[indx][words[indx].size()-1];
        
        // S + Si
        int left = words[indx].size() - (end == curStart) + recursion(indx + 1, start, curEnd, words);
        
        // Si + S
        int right = words[indx].size() - (curEnd == start) + recursion(indx+1, curStart, end, words);
        
        return min(left, right);
    }   

    int memoization(int indx, char start, char end, vector<string>& words, vector<vector<vector<int>>> &dp){
        if (indx >= n) return 0;

        if (dp[indx][start-'a'][end-'a'] != -1) return dp[indx][start-'a'][end-'a'];

        char curStart = words[indx][0];
        char curEnd = words[indx][words[indx].size()-1];
        
        // S + Si
        int left = words[indx].size() - (end == curStart) + memoization(indx + 1, start, curEnd, words, dp);
        
        // Si + S
        int right = words[indx].size() - (curEnd == start) + memoization(indx+1, curStart, end, words, dp);
        
        return dp[indx][start-'a'][end-'a'] = min(left, right);
    }   

    int minimizeConcatenatedLength(vector<string>& words) {
        n = words.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(26, vector<int>(26,-1)));
        return (int)words[0].size() + memoization(1, words[0][0], words[0][words[0].size()-1], words, dp);
    }
};