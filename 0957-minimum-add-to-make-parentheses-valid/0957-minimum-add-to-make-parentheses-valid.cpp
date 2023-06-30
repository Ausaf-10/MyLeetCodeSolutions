class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int open=0,close=0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(') stk.push(s[i]);
            else{
                if (!stk.empty()){
                    if (stk.top() == '(') stk.pop();
                    else close++;
                }
                else close++;
            }
        }
        if (stk.empty() && close == 0 && open == 0) return 0;

        while (!stk.empty()){
            open++;
            stk.pop();
            
        }

        if (open == 0 && close!=0) return close;
        else if (open != 0 && close == 0) return open;
        // else if (open == close) return open + close;
        // else if (close > open) return close - open;
        return open + close;
    }
};