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

    void method2(string& str){
        int n = str.size();
        
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
        string ans;
        // reverseInPlace(s,ans);
        method2(s);
        return s;
    }
};