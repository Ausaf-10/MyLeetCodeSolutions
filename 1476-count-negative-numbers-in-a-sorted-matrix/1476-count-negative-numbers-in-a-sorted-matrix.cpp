class Solution {
public:
    int countNegatives(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), ans = 0, row = n-1, col = 0;
        while (row>=0 && col<m){
            if (mat[row][col]<0){
                ans+=(m-col);
                row--;
            }
            else{
                col++;
            }
        }
        return ans;
    }
};