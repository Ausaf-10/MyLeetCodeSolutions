class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch == '(') stk.push(i);
            else if (ch == ')'){
                if (stk.empty()){
                    s[i] = '#';
                }
                else stk.pop();
            }
        }
        while (!stk.empty()){
            int indx = stk.top();
            s[indx] = '#';
            stk.pop();
        }
        string ans;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '#') continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};