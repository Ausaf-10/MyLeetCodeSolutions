// METHOD 1 -> USING STACK
// ADD A EXTRA SPACE AT THE LAST OF THE STRING 
// WHEN U SEE A SPACE JUST PUT THE TEMP STRING INTO THE STACK

class Solution {
public:
    void reverseUsingStack(string str, string& ans){
        str+=" ";
        stack<string> stk;
        string temp="";
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

        ans.pop_back();

        return ;
    }
    string reverseWords(string s) {
        string ans = "";
        reverseUsingStack(s,ans);
        return ans;
    }
};