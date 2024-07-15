class Solution {
public:
    int solve(int start, int end){
        if (start > end) return 1;
        int ans = 0;
        for (int i=start; i<=end; i++){
            int Left = solve(start, i-1);
            int Right = solve(i+1, end);
            ans += Left*Right;
        }
        return ans;
    }
    int memoization(int start, int end, map<pair<int,int>, int> &mp){
        if (start > end) return 1;
        if (mp.find({start,end}) != mp.end()) return mp[{start,end}];
        int ans = 0;
        for (int i=start; i<=end; i++){
            int Left = memoization(start, i-1, mp);
            int Right = memoization(i+1, end, mp);
            ans += Left*Right;
        }
        return mp[{start,end}] = ans;
    } 
    int numTrees(int n) {
        map<pair<int,int>, int> mp;
        return memoization(1, n, mp);
    }
};