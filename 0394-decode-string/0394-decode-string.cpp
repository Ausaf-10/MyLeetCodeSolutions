class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string ans;
        int n = s.size();
        for (int i=0; i<n; i++){
            if (s[i] != ']') stk.push(s[i]);
            else{
                string temp;
                while (!stk.empty() && stk.top()!='['){
                    temp.push_back(stk.top());
                    stk.pop();
                }
                reverse(temp.begin(), temp.end());
                stk.pop();
                string number;
                while (!stk.empty() && stk.top() >= '0' && stk.top() <= '9'){
                    number.push_back(stk.top());
                    stk.pop();
                }
                reverse(number.begin(), number.end());
                int freq = stoi(number);
                string var = temp;
                for (int j=0; j<freq-1; j++) temp += var;
                for (auto it : temp) stk.push(it);
            }
        }
        while (!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};