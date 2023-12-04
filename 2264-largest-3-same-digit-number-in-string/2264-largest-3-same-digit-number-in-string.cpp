class Solution {
public:
    string largestGoodInteger(string str) {
        int n = str.size();
        if (str.size() < 3) return "";
        string ans="";
        for (int i=0; i<n-1; i++){
            int j=i+1;
            while (j < n){
                int len = j-i+1;
                if (str[i] != str[j]) break;
                if (len == 3){
                    if (ans.size() == 0){
                        ans+=str.substr(i,len);
                    }
                    else{
                        int numLast = stoi(ans);
                        int num = stoi(str.substr(i,len));
                        if (num > numLast){
                            for (int k=0; k<3; k++){
                                ans.pop_back();
                            }
                            ans+=str.substr(i,len);
                        }
                    }
                    break;
                }
                j++;  
            }

        }
        return ans;
    }
};