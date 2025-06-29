class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        long long ans = 0;
        while (i<n && s[i] == ' ') i++;
        if (s[i] == '-'){
            sign = -1;
            i++;
        } else if (s[i] == '+'){
            i++;
        }
        while (i<n && s[i]== '0') i++;
        while (i<n){
            if (s[i] >= '0' && s[i] <= '9'){
                ans = ans*10 + (s[i]-'0');
                if (sign == 1 && ans > INT_MAX) return INT_MAX;
                if (sign == -1 && -1*ans < INT_MIN) return INT_MIN;
            }
            else{
                break;
            }
            i++;
        }
        if (sign == -1) ans*=-1;
        return ans;
    }
};