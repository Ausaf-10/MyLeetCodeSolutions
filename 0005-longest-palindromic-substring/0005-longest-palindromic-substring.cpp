class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int st = 0, end = 0;
        int maxLen = 1;
       
       // ODD LENGTH PALLINDROME!!!
        for (int i=0; i<n-1; i++){
            int l=i, r = i;
            while (l>=0 && r < n){
                if (s[l] == s[r]){
                    l--,r++;
                }
                else break;
            }
            int len = r - l - 1;
            if (len > maxLen){
                maxLen = len;
                st = l+1, end = r-1;
            }
        }

        for (int i=0; i<n-1; i++){
            int l=i, r = i+1;
            while (l>=0 && r < n){
                if (s[l] == s[r]){
                    l--,r++;
                }
                else break;
            }
            int len = r - l - 1;
            if (len > maxLen){
                maxLen = len;
                st = l+1, end = r-1;
            }
        }
        

        string ans(end-st+1, ' ');
        int indx = 0;
        for (int i=st; i<=end; i++){
            ans[indx] = s[i];
            indx++;
        }

        return ans;
    }
};