class Solution {
public:
    int n;
    void fun(int indx, vector<string> &ans, string& ds, int open, int close){
        if (indx == 2*n){
            ans.push_back(ds);
            return;
        }
        if (open < n){
            ds.push_back('(');
            fun(indx+1, ans, ds, open+1, close);
            ds.pop_back();
        }
        if (close < open){
            ds.push_back(')');
            fun(indx+1, ans, ds, open, close+1);
            ds.pop_back();
        }
        
        return ;
    }
    vector<string> generateParenthesis(int N) {
        n = N;
        vector<string> ans;
        string ds;
        fun(0, ans, ds, 0, 0);
        return ans;
    }
};