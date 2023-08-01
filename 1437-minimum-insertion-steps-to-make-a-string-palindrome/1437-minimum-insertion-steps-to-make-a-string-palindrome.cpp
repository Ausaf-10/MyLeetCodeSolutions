class Solution {
public:
    int LPS(string str1){
        int n = str1.size();
        string str2="";
        for (int i=n-1; i>=0; i--) str2.push_back(str1[i]);

        vector<int> prev(n+1,0);
        for (int i=0; i<=n; i++) prev[i] = 0;

        for (int indx1 = 1; indx1<=n; indx1++){
            vector<int> temp(n+1,0);
            temp[0] = 0;
            for (int indx2 = 1; indx2<=n; indx2++){
                if (str1[indx1 -1] == str2[indx2 - 1]){
                    temp[indx2] = 1 + prev[indx2 - 1];
                }
                else temp[indx2] = max(temp[indx2 - 1], prev[indx2]);
            }
            prev = temp;
        }

        return prev[n];
    }
    int minInsertions(string s) {
        int longestPallindrome = LPS(s);
        int n = s.size();
        return n - longestPallindrome;
    }
};