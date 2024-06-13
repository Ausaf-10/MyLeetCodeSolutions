class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1, prevEnd = intervals[0][1];
        for (int i=1; i<n; i++){
            int urStart = intervals[i][0];
            if (urStart >= prevEnd){
                cnt++;
                prevEnd = intervals[i][1];
            }
            
        }
        
        return n-cnt;
    

    }
};