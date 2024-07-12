class Solution {
public:
    int fun1(string &s, int x, int y){
        stack<char> stk;
        int ans = 0;
        for (auto ch : s){
            if (stk.empty()) stk.push(ch);
            else if (ch == 'b'){
                if (!stk.empty() && stk.top() == 'a'){
                    stk.pop();
                    ans+=x;
                }
                else{
                    stk.push(ch);
                }
            }
            else{
                stk.push(ch);
            }
        }
        string temp;
        while (!stk.empty()){
            temp.push_back(stk.top()); stk.pop();
        }
        reverse(temp.begin(), temp.end());
        for (auto ch : temp){
            if (stk.empty()) stk.push(ch);
            else if (ch == 'a'){
                if (!stk.empty() && stk.top() == 'b'){
                    stk.pop();
                    ans+=y;
                }
                else{
                    stk.push(ch);
                }
            }
            else{
                stk.push(ch);
            }
        }
        return ans;
    }
    int fun2(string &s, int x, int y){
        stack<char> stk;
        int ans = 0;
        for (auto ch : s){
            if (stk.empty()) stk.push(ch);
            else if (ch == 'a'){
                if (!stk.empty() && stk.top() == 'b'){
                    stk.pop();
                    ans+=y;
                }
                else{
                    stk.push(ch);
                }
            }
            else{
                stk.push(ch);
            }
        }
        string temp;
        while (!stk.empty()){
            temp.push_back(stk.top()); stk.pop();
        }
        reverse(temp.begin(), temp.end());
        for (auto ch : temp){
            if (stk.empty()) stk.push(ch);
            else if (ch == 'b'){
                if (!stk.empty() && stk.top() == 'a'){
                    stk.pop();
                    ans+=x;
                }else{
                    stk.push(ch);
                }
            }
            else{
                stk.push(ch);
            }
        }
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        if (x >= y){
            return fun1(s, x, y);
        }
        return fun2(s, x, y);
    }
};