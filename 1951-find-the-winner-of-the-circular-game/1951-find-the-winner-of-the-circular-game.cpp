class Solution {
public:
    int solve(int n, int k){
        if (n == 1) return 0;
        int getIndx = solve(n-1, k);
        return (getIndx+k)%n;
    }
    int tabulation(int n, int k){
        int prev = 0;
        for (int indx=2; indx<=n; indx++){
            int getIndx = prev;
            int cur = (getIndx+k)%indx;
            prev = cur;
        }
        return prev;
    }
    int findTheWinner(int n, int k) {
        return tabulation(n,k) + 1;
    }
};