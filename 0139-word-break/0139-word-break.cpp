class Solution {
public:
    bool recursion(int indx, string str, unordered_set<string> &dict){
        if (indx == str.size()) return true;
        if (dict.find(str) != dict.end()) return true;

        for (int l=1; l<=str.size(); l++){
            string temp = str.substr(indx,l);
            if (dict.find(temp)!= dict.end() && recursion(indx+l, str, dict)) return true;
        }

        return false;

    }
    bool memoization(int indx, string str, unordered_set<string> &dict, vector<int>& dp){
        if (indx == str.size()) return true;
       
        if (dict.find(str) != dict.end()) return true;
       
        if (dp[indx]!=-1) return dp[indx];
       
        for (int l=1; l<=str.size(); l++){
            string temp = str.substr(indx,l);
            if (dict.find(temp)!= dict.end() && memoization(indx+l, str, dict, dp)){
                return dp[indx] = true;
            }
        }

        return dp[indx] = false;

    }


    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(1000,-1);
        return memoization(0, s, st, dp);
    }
};