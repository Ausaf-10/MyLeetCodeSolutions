class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x, ans = 0;
        while (low<=high){
            long long mid = low + (high - low)/2;
            long long res = mid*mid;
            if (res <= x){
                // ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};