using ll = long long int;
class Solution {
public:
    int target, n;
    string s;
    void recursion(int indx, string path, vector<string>& ans, ll resultSoFar, ll prevNo){
        if (indx == n){
            if (target == resultSoFar) ans.push_back(path);
            return ;
        }
        for (int i=indx; i<n; i++){
            ll curNum = stoll(s.substr(indx, i-indx+1));
            if (s[indx] == '0' && i-indx+1 >= 2) return;
            if (indx == 0){
                recursion(i+1, path + to_string(curNum), ans, curNum, curNum);
            }
            else{
                recursion(i+1, path + "+" + to_string(curNum), ans, resultSoFar+curNum, curNum);
                recursion(i+1, path + "-" + to_string(curNum), ans, resultSoFar-curNum, -curNum);
                recursion(i+1, path + "*" + to_string(curNum), ans, resultSoFar-prevNo+curNum*prevNo, curNum*prevNo);
            }
        }
        return ;
        
    }
    vector<string> addOperators(string num, int T) {
        target = T, s = num, n = num.size();
        vector<string> ans;
        string path;
        recursion(0, path, ans, 0, 0);
        return ans;
    }
};