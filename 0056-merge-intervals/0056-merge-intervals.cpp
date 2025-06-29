
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int prevStart = arr[0][0], prevEnd = arr[0][1];
        for (int i=1; i<n; i++){
            int curStart = arr[i][0], curEnd = arr[i][1];
            if (curStart <= prevEnd){
                prevEnd = max(prevEnd, curEnd);
            }
            else{
                ans.push_back({prevStart, prevEnd});
                prevStart = curStart, prevEnd = curEnd;
            }
        }
        ans.push_back({prevStart, prevEnd});
        return ans;
    }
};