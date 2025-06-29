class Solution {
public:
    vector<int> returnRow(int row){
        vector<int> ans;
        ans.push_back(1);
        int res = 1;
        for (int i=0; i<row; i++){
            res*=(row-i);
            res/=(i+1);
            ans.push_back(res); 
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i=2; i<=numRows; i++){
            ans.push_back(returnRow(i-1));
        }
        return ans;
    }
};