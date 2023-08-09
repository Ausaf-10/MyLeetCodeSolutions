class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') stk.push(ch);
            else{
                if (stk.empty()) return false;
                else{
                    if ((ch == ')' && stk.top() == '(') || (ch == ']' && stk.top() == '[') ||
                        (ch == '}' && stk.top() == '{')) {
                            stk.pop();
                    }
                    else return false;
                }
            }
        }
        if (stk.empty()) return true;
        return false;
    }
};