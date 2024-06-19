class Solution {
public:
    bool canTransform(string s, string t) {
        int n = s.size(), i = 0, j = 0;
        while (i < s.size() || j< t.size()){
            while (i<s.size() && s[i] == 'X') i++;
            while (j<t.size() && t[j] == 'X') j++;

            if (i == s.size() && j == t.size()) return true;
            if (i == s.size() || j == t.size() || s[i]!=t[j]) return false;


            if (s[i] == 'L' && i<j) return false;
            if (s[i] == 'R' && i>j) return false;

            i++,j++;
        }
        return true;
    }
};