class Solution {
public:
    int solve(int n ,int k){
        if (n == 1) return 0;
        int indx = solve(n-1, k);
        int myPosition = (indx + k) % n;
        return myPosition;
    }
    int findTheWinner(int n, int k) {
        return solve(n,k) + 1;
    }
};