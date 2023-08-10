class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char> stk;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch!='*') ans+=ch;
            else ans.pop_back();
        }
        return ans;
    }
};