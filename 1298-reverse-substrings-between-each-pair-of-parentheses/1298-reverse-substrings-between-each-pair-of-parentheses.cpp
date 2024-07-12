class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        int open = 0;
        stack<char> stk;
        for (auto ch: s){
            if (ch == '(') stk.push(ch);
            else if (ch != '(' && ch != ')'){
                if (stk.empty()) ans.push_back(ch);
                else stk.push(ch);
            }
            else if (ch == ')'){
                string temp;
                while (!stk.empty() && stk.top() != '('){
                    temp.push_back(stk.top()); stk.pop();
                }
                stk.pop();
                if (stk.empty()){
                    ans.append(temp);
                }
                else{
                    for (auto it : temp) stk.push(it);
                }
            }
        }
        return ans;
    }
};