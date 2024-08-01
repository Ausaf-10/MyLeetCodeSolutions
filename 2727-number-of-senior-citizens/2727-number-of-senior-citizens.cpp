class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto it : details){
            int n = it.size();
            string str = it.substr(n-4, 2);
            int number = stoi(str);
            if (number > 60) cnt++;
        }
        return cnt;
    }
};