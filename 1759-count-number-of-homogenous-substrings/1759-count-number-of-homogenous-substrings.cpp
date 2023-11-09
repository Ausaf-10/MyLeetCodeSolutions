class Solution {
public:
    int countHomogenous(string str) {
        long long cnt = 0;
        int mod = 1e9+7;
        
        int i=0;
        while (i<str.size()){
            int j=i;
            while (j<str.size() && str[i] == str[j]) j++;
            long long n = j-i;
            cnt = (cnt + (n)*(n+1)/2)%(mod);
            i = j;
        }
        return (int)cnt;
    }
};