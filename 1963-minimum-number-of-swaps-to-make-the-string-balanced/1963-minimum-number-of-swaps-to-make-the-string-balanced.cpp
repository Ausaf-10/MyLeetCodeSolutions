class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int cnt = 0;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch == '[') stk.push(ch);
            else{
                if (stk.empty()) cnt++;
                else stk.pop();
            }
        }
        int ans = ceil(cnt/2.0);
        return ans;
    }
};