class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 9;
        for (int no=9; no>=(11-n); no--){
            res *= no;
        }
        res = res + countNumbersWithUniqueDigits(n-1);
        return res;
    }
};