class Solution {
public:
    int minAddToMakeValid(string s) {
        // JO VALID HAIN UNKO HATAO AND JO BHI INVALID HAIN UNKE
        // CLOSING AUR OPENINING BRACKETS COUNT KRLO!!
        
        stack<char> stk;
        int open=0,close=0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '('){
                stk.push(s[i]);
                open++;
            }
            else{
                if (!stk.empty()){
                    stk.pop();
                    open--;
                }
                else close++;
            }
        }
        if (stk.empty() && close == 0 && open == 0) return 0;

        return open + close;
    }
};