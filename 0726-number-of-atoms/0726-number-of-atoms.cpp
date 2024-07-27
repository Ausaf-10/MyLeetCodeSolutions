class Solution {
public:
    string countOfAtoms(string s) {
        stack<unordered_map<string, int>> stk;
        stk.push(unordered_map<string, int>());
        int i = 0, n = s.size();
        while (i < n){
            if (s[i] == '('){
                stk.push(unordered_map<string, int>());
                i++;
            }
            else if (s[i] == ')'){
                unordered_map<string, int> curMap = stk.top(); stk.pop();
                i++;
                string curNumber;
                while (i < n && isdigit(s[i])){
                    curNumber.push_back(s[i]);
                    i++;
                }
                if (!curNumber.empty()){
                    int number = stoi(curNumber);
                    for (auto it : curMap){
                        string str = it.first;
                        curMap[str] *= number;
                    }
                }
                for (auto it : curMap){
                    string str = it.first;
                    int count = it.second;
                    stk.top()[str] += count;
                }

            }
            else{
                string cur;
                cur.push_back(s[i]);
                i++;
                while (i < n && isalpha(s[i]) && islower(s[i])){
                    cur.push_back(s[i]);
                    i++;
                }
                string curNumber;
                while (i < n && isdigit(s[i])){
                    curNumber.push_back(s[i]);
                    i++;
                }
                int number = 1;
                if (!curNumber.empty()){
                    number = stoi(curNumber);
                }
                stk.top()[cur] += number;
            }
        }

        string res;
        map<string, int> curMap(stk.top().begin(), stk.top().end());
        for (auto it : curMap){
            string str = it.first;
            int count = it.second;
            res.append(str);
            if (count > 1){
                res.append(to_string(count));
            }
        }
        return res;
    }
};