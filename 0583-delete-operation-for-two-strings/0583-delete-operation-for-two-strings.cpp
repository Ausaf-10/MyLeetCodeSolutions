class Solution {
public:
    int LCS(string str1, string str2){
        int n = str1.size();
        int m = str2.size();

        vector<int> prev(m+1,0);
        for (int j=0; j<=m; j++) prev[j] = 0;

        for (int indx1 = 1; indx1<=n; indx1++){
            vector<int> temp(m+1,0);
            temp[0] = 0;
            for (int indx2 = 1; indx2<=m; indx2++){
                if (str1[indx1-1] == str2[indx2-1]){
                    temp[indx2] = 1 + prev[indx2-1];
                }
                else temp[indx2] = max(prev[indx2], temp[indx2-1]);
            }
            prev = temp;
        }

        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int lengthCommonSubsequence = LCS(word1, word2);
        int n = word1.size(), m = word2.size();
        
        int deletion = n -  lengthCommonSubsequence;
        int insertion = m - lengthCommonSubsequence;
        
        return deletion + insertion; 
    }
};