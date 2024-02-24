class Solution {
public:
    int n;
    void recursion(string s, vector<string> &dictionary, unordered_set<string>& st, int indx, string ans, vector<string>& path){
        if (indx >= n){
            ans.pop_back();
            path.push_back(ans);
            return ;
        }
        for (int i=indx; i<n; i++){
            string str = s.substr(indx, i-indx+1);
            if (st.find(str) != st.end()){
                recursion(s, dictionary, st, i+1, ans+str+' ', path);
            }
        }
        return ;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        string ans;
        vector<string> path;
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        recursion(s, wordDict, st, 0, ans, path);
        return path;
    }
};