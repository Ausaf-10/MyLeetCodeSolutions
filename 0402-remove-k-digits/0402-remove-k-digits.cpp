class Solution {
public:
    string removeKdigits(string num, int k) {
        // JUST USING STRING IN THE FORM OF A STACK SO THAT WE JUST RETURN THE ENTIRE STRING ONLY
        string ans = "";
        int n = num.size();
        
        if (k >= n) return "0";

        for(int i=0; i<n; i++){
            while (ans.size()!=0 && k>0 && ans.back() > num[i]){
                ans.pop_back();
                k--;
            }
            if (ans.size()!=0 || num[i]!='0') ans.push_back(num[i]); // to avoid adding prefix 0's
        }
        
        // THIS CASE IS USED TO DELETE THE ELEMENTS TILL THE VALUE OF K
        while (ans.size()!=0 && k!=0){
            ans.pop_back();
            k--;
        }

        return (ans=="")?"0":ans;
    }
};