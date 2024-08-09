class Solution {
public:
    int recursion(int k){
        if (k == 0 || k == 1) return k;
        int val = recursion(k/2);
        if (k&1) return !k;
        return k;
    }
    int kthGrammar(int n, int k) {
        return recursion(k-1);
    }
};