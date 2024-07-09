class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        stack<char> stk;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch == '('){
                if (!stk.empty()) str.push_back(ch);
                stk.push(ch);
            }
            else{
                if (stk.size() > 1){
                    str.push_back(ch);
                }
                stk.pop();
            }
        }
        
        return str;
    }
};
