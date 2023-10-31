class Solution {
public:
    void fun(int n, string& path){
        if (n == 1 ){
            path.push_back('1');
            return ;
        }
    
        fun(n-1, path);
        
        string ans="";
        int i=0;
        while (i < path.size()){
            int cnt = 0;
            int j = i;
            while (j < path.size() && path[i] == path[j]){
                j++;
                cnt++;
            }
            ans+=((cnt)+'0');
            ans+=path[i];
            i++;
            while (path[i] == path[i-1]){
                i++;
            }
        }
        
        path = ans;

        return ;
    }
    string countAndSay(int n) {
        string path;
        fun(n,path);
        return path;
    }
};