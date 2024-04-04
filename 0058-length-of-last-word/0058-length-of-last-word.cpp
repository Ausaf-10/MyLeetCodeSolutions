class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), j = n-1;
        while (j >= 0 && s[j]==' '){
            j--;
        }
        int i = j-1;
        while (i>=0 && s[i]!=' '){
            i--;
        }
        i++;
        string str = s.substr(i, j-i+1);
        return (int)str.size();

    }
};