class Solution {
public:
    int n;
    void fun(int indx, int open, int close, string path, vector<string>& ans){
        if (indx == 2*n){
            ans.push_back(path);
            return ;
        }
        if (open < n){
            fun(indx+1, open+1, close, path+"(", ans);
        }
        if (close < open){
            fun(indx+1, open, close+1, path+")", ans);
        }
        return;
    }
    vector<string> generateParenthesis(int N) {
        n = N;
        vector<string> ans;
        fun(0, 0, 0, "", ans);
        return ans;

    }
};