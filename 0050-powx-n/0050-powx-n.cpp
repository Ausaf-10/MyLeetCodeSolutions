using ll = long long int;
class Solution {
public:
    double myPow(double x, ll n){
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;

        double halfPow = myPow(x,n/2);
        double ans = halfPow * halfPow;
        if (n&1){
            return x * ans;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (x == 0) return 0.0;

        if (n < 0){
            return 1/myPow(x, (ll)n*-1*1LL);
        }

        return myPow(x, (ll)n);
    }
};