class Solution {
public:
    int n;
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> ans;
        for (int i=0; i<n; i++){
            if (i+3 > n) break;
            vector<int> row;
            for (int j=0; j<n; j++){
                if (j+3 > n) break;
                int maxi = -1e9;
                for (int k=i; k<i+3; k++){
                    for (int l=j; l<j+3; l++){
                        maxi = max(maxi, grid[k][l]);
                    }
                }
                row.push_back(maxi);
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};