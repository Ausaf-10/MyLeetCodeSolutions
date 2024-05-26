class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, n = s.size() , i = 0;
        long long number = 0 ;
        while (s[i] == ' ') i++;
        if (s[i] == '-') {
            sign = -1; i++;
        }
        else if (s[i] == '+'){
            sign = 1; i++;
        }
        while (s[i]>='0' && s[i]<='9' && i < n){
            number = number * 10 + (s[i]-'0');
            if (sign == -1 && sign*number < INT_MIN) return INT_MIN;
            if (sign == 1 && sign*number > INT_MAX) return INT_MAX;
            i++;
        }
        number = number * sign;
        return (int)number;
    }
};