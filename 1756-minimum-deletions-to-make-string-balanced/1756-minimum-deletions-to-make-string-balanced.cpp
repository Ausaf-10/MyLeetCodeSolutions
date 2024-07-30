class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> stk;
        int n = s.size(), cnt = 0;
        for (int i=0; i<n; i++){
            if (!stk.empty() && s[i] == 'a' && stk.top() == 'b'){
                stk.pop();
                cnt++;
            }
            else{
                stk.push(s[i]);
            }
        }
        return cnt;
    }
};