class Solution {
public:
    string convertToTitle(int columnNumber) {
        // EVERY 26 LETTERS KE BAAD SEQUENCE CHANGES!!
        string ans = "";

        while (columnNumber > 0){
            columnNumber--; // to avoid corner cases! like if it is a multiple of 26
            int rem = columnNumber%26;
            ans.push_back(char(rem+65));

            columnNumber/=26;
       }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};