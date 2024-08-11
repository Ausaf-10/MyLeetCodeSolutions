class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i=1; i<n; i++){
            int urStart = intervals[i][0], urEnd = intervals[i][1];
            if (urStart <= end){
                start = min(start, urStart);
                end = max(end, urEnd);
            } 
            else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            } 

        }
        ans.push_back({start,end});
        
        return ans;
    }
};