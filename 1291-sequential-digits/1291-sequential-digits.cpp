class Solution {
public:
    void solve(vector<int>& ans, int low, int high, int indx,string &str){
        if (indx > 10) return ;
        if (2 <= indx && indx <= 10){
            int number = stoi(str);
            ans.push_back(number);
        }
        if (indx == 0){
            for (int i=1; i<=9; i++){
                char ch = i+'0';
                str.push_back(ch);
                solve(ans, low, high, indx+1, str);
                str.pop_back();
            }
        }
        else{
            for (int i=0; i<=9; i++){
                char ch = i+'0';
                if (str.back()-'0' == i-1){
                    str.push_back(ch);
                    solve(ans, low, high, indx+1, str);
                    str.pop_back();
                }
                
            }
        }

        return ;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans, res;
        string str;
        solve(ans, low, high, 0, str);
        for (auto it : ans){
            if (low <= it && it <= high)
                res.push_back(it);
        }
        sort(res.begin(), res.end());
        return res;
    }
};