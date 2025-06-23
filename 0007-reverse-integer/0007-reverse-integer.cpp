using ll = long long int;
class Solution {
public:
    ll count (ll n){
        ll num = n, rev = 0;
        while (num > 0){
            ll rem = num % 10;
            rev = rev*10 + rem;
            if (rev > INT_MAX) return 0;
            num/=10;
        }
        return rev;
    }
    int reverse(int x) {
        ll num = x;
        if (x < 0){
            return -1 * count(abs(num));
        }
        return count (x);
    }
};