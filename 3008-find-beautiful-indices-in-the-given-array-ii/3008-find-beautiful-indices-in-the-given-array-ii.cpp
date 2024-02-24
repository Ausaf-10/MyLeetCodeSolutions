class Solution {
public:
    void computeLPS(string& pattern, vector<int>& LPS){
        int m = pattern.size();
        LPS[0] = 0;
        int i = 1, length = 0;
        while (i < m){
            if (pattern[length] == pattern[i]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{
                if (length!=0){
                    length = LPS[length-1];
                }
                else{
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return ;
    }
    vector<int> KMP(string &pattern, string& text){
        string str = pattern + "#" + text;
        int n = text.size(), m = pattern.size();
        vector<int> LPS(n+m+1);
        vector<int> ans;
        computeLPS(str, LPS);
        for (int i=0; i<LPS.size(); i++){
            if (LPS[i] == m) ans.push_back(i-2*m);
        }
        return ans;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> i_indx = KMP(a, s);
        vector<int> j_indx = KMP(b, s);
        int n = j_indx.size();
        vector<int> ans;
        for (auto it : i_indx){
            int lowerLimit = it-k, upperLimit = it+k;
            auto lowerBound = lower_bound(j_indx.begin(), j_indx.end(), lowerLimit);
            if (lowerBound!=j_indx.end() && *lowerBound<=upperLimit){
                ans.push_back(it);
            }
        }
        return ans;
    }
};