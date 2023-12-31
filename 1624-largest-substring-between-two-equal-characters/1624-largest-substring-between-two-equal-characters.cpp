class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = -1;
        for (int i=0; i<s.size(); i++){
            for (int j=i+1; j<s.size(); j++){
                if (s[i] == s[j]){
                    int start = i+1, end = j-1;
                    len = max(len,end-start+1);
                }
            }
        }
        return len;
    }
};