class Solution {
public:
    bool checkPallindrome(string& arr, int i, int j){
        if (i >= j) return true;
        if (arr[i]!=arr[j]) return false;
        return checkPallindrome(arr,i+1,j-1);   
    }
    bool isPalindrome(string s) {
        string ans;
        for (char ch : s){
            if (ch >= 'A' && ch<='Z'){
                char var = char(ch + 32);
                ans.push_back(var);
            }
            else if (ch >= 'a' && ch<='z' || ch>='0' && ch<='9') ans.push_back(ch);
        }
        
        if (ans.size() == 0) return true;
        
        return checkPallindrome(ans,0,ans.size()-1);
        
    }
};