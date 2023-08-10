class Solution {
public:
    string removeStars(string s) {
        string ans="";
        stack<char> stk;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch!='*') stk.push(ch);
            else{
                stk.pop();
            }
        }
        while (!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};