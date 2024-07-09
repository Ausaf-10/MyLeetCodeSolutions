class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string str;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch == '('){
                if (open!=0) str.push_back(ch);
                open++;
            }
            else{
                if (open!=1) str.push_back(ch);
                open--;
            }
        }
        return str;
    }
};