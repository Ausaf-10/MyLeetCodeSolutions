class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];
        for (int i=1; i<n; i++){
            prefix[i] = arr[i]^prefix[i-1];
        }
        for (auto it : queries){
            int start = it[0], end = it[1];
            if (start == 0){
                ans.push_back(prefix[end]);
            }
            else{
                int res = prefix[end]^(prefix[start-1]);
                ans.push_back(res);
            }
        }
        return ans;
    }
};