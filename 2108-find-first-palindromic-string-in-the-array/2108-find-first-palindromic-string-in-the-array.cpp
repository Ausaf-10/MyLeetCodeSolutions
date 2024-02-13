class Solution {
public:
    bool isPallindrome(string& str){
        int n = str.size();
        for (int i=0; i<n/2; i++){
            if (str[i] != str[n-i-1]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto it : words){
            if (isPallindrome(it)) return it;
        }
        return "";
    }
};