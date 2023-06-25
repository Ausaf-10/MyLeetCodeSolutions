class Solution {
public:

    int myPow(long long x, long long n){
        if (x == 0) return 0;
        if (n == 0) return 1;

        long long ans = myPow(x,n/2);
        ans*=ans;
        if (n % 2 == 1){
            ans*=x;
        }
        ans%=1000000007;
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = n%2 + n/2;
        long long odd = n/2;

        long long ansEven = myPow(5,even);
        long long ansOdd = myPow(4,odd);

        return (ansEven * ansOdd)%1000000007;

    }
};