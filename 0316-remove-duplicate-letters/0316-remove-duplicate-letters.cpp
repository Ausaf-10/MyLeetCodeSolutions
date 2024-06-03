class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> stk;
        string ans;
        vector<int> lastIndx(26, -1), seen(26, 0);
        for (int i=0; i<n; i++) lastIndx[s[i]-'a'] = i; 
        for (int i=0; i<n; i++){
            char ch = s[i];
            if (seen[ch-'a']) continue;
            while (!stk.empty() && ch < stk.top() && i < lastIndx[stk.top()-'a']){
                seen[stk.top()-'a'] = 0;
                stk.pop();
            }
            seen[ch-'a'] = 1;
            stk.push(ch);
        }
        while (!stk.empty()){
            ans.push_back(stk.top()); stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};