class Solution {
public:
    void reverseInPlace(string& str, string &ans){
        str.push_back(' ');
        string temp;
        for (int i=0; i<str.size(); i++){
            if (str[i] == ' '){
                if (temp.size()!=0){
                    reverse(temp.begin(), temp.end());
                    ans.append(temp+" ");
                    temp="";
                }
            }
            else{
                temp.push_back(str[i]);
            }
        }

        ans.pop_back(); // to remove the last space !

        return ;
    }
    string reverseWords(string s) {
        string ans;
        reverseInPlace(s,ans);
        return ans;
    }
};