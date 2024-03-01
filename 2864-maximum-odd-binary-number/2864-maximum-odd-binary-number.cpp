class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt0=0, cnt1=0;
        for (auto it : s){
            if (it == '1') cnt1++;
            else cnt0++;
        }
        int n = s.size();
        vector<char> str(n);
        str[n-1] = '1';
        cnt1--;
        for (int i=n-2; i>=0; i--){
            if (i!=(cnt1-1)){
                str[i] = '0';
            }
            else{
                str[i] = '1';
                cnt1--;
            }
        }
        string ans;
        for (auto it : str) ans.push_back(it);
        return ans;
    }
};