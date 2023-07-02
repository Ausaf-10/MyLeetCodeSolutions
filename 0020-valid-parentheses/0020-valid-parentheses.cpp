class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for (int i=0; i<s.size(); i++){
            int element = s[i];
            if (element =='(' || element =='[' || element =='{') stk.push(element);
            else{
                if (!stk.empty()){
                    if ((stk.top()=='(' && element ==')') || (stk.top()=='{' && element =='}') || (stk.top()=='[' && element ==']')) stk.pop();
                    else return false;
                }
                else return false;
            }  
        }
        if (stk.empty()) return true;
        return false;
    }
};