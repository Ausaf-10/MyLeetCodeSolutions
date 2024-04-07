class Solution {
public:
    bool checkValidString(string str) {
        int n = str.size(), cnt = 0;
        stack<int> stk; unordered_map<int,int> mp;
        for (int i=0; i<n; i++){
            char ch = str[i];
            if (ch == '*'){
                cnt++;
                mp[i]++;
            }
            else if (ch == '(') stk.push(i);
            else{
                if (!stk.empty()) stk.pop();
                else{
                    if (cnt > 0) cnt--;
                    else return false;
                }
            }
        }
        if (stk.empty()) return true;
        if (mp.size() < stk.size()) return false;
        while (!stk.empty()){
            int indx = stk.top(); 
            int asteriskIndx = mp.begin()->first;
            if (indx > asteriskIndx) return false;
            stk.pop();
            mp.erase(asteriskIndx);
        }
        return true;

    }
};