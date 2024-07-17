using ll = long long int;
class Solution {
public:
    int n, target;
    void fun(int indx, string& s, string path, vector<string> &ans, ll resultSoFar,ll prev){
        if (indx == n){
            if (resultSoFar == target){
                ans.push_back(path);
            }
            return ;
        }
        for (int i=indx; i<n; i++){
            string str = s.substr(indx, i-indx+1);
            ll curNo = stoll(str);
            if (s[indx] == '0' && i-indx+1 >= 2) return;
            if (indx == 0){
                fun(i+1, s, path+to_string(curNo), ans, curNo, curNo);
            }
            else{
                fun(i+1, s, path+'+'+ to_string(curNo), ans, resultSoFar + curNo, curNo);
                fun(i+1, s, path+'-'+ to_string(curNo), ans, resultSoFar - curNo, -curNo);
                fun(i+1, s, path+'*'+ to_string(curNo), ans, (resultSoFar-prev)+(prev*curNo), prev*curNo);
            }   
        }
        
        return ;
    }
    vector<string> addOperators(string s, int T) {
        n = s.size(), target = T;
        vector<string> ans;
        string path;
        fun(0, s, path, ans, 0, 0);
        return ans;
    }
};