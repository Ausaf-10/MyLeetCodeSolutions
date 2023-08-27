// METHOD 1 -> USING STACK -> EXTRA SPACE
// ADD A EXTRA SPACE AT THE LAST OF THE STRING 
// WHEN U SEE A SPACE JUST PUT THE TEMP STRING INTO THE STACK

// METHOD 2 -> USING 2 POINTERS
// AGAR HUM SABKO REVERSE KRDEIN AND THEN INDIVIDUAL WORDS KO REVERSE KRDENGE TOH HUMARA ANS SAHI AA JAYEGA
// EK i, l,r AND POINTERS RAKHENGE JAHAN 
// i -> YEH BATAYEGA KI ABHI AAP KAUNSE CHARACTER PE HO 
// l,r -> 2 POINTERS HAIN JINKI MADAD SE AAP UN INDIVIDUAL WORDS KO REVERSE KROGE!
// AGAR str[i]!=space THEN ASSIGN THAT VALUE TO r AND MOVE BOTH R AND I BUT THE MOMENT U SEE THAT str[i] == space THEN REVERSE THE WORD USING L AND R AND ONCE REVERSED, MOVE THE POINTER L AND R TO ONE STEP AND ALSO MOVE ITH POINTER TILL THE TIME U DONT SEE A VALID CHARACER!!!!!


class Solution {
public:
    void reverseUsingStack(string str, string& ans){
        str+=" ";
        stack<string> stk;      // SC: O(N)
        string temp="";          // SC: O(N)

        // TC: O(N)
        for (int i=0; i<str.size(); i++){
            if (str[i] == ' '){
                if (temp.size() != 0) stk.push(temp);
                temp = "";
            }
            else temp+=str[i];
        } 

        while (!stk.empty()){
            ans.append(stk.top());
            ans.append(" ");
            stk.pop();
        }

        ans.pop_back();     // LAST WAALA SPACE KO HATA DO

        return ;
    }

    void method2(string& str){
        int n = str.size();
        // 1. REVERSE ALL THE CHARACTERS IN THE STRING 
        reverse(str.begin(), str.end());

        int i=0,l=0,r=0;

        while (i<str.size()){
           
            while (i < n && str[i]!=' '){
                str[r++] = str[i++];
            }
            if (l < r){
                reverse(str.begin() + l, str.begin() + r);
                str[r] = ' ';
                r++;
                l = r;
            }
            i++; // jab str[i] = space hoga tab usko increment krte rahnge!
        }
        str = str.substr(0,r-1);
        return ;
    }

    string reverseWords(string s) {
        // string ans = "";
        // reverseUsingStack(s,ans);
        method2(s);
        return s;
    }
};