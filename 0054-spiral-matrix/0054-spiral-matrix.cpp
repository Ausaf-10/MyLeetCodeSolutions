class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left=0,top=0,bottom=row-1,right=col-1;

        vector<int> ds;

        while (left <= right && top <= bottom){
            //PRINT RIGHT: LEFT->RIGHT
            for (int i=left; i<=right; i++){
                ds.push_back(matrix[top][i]);
            }
            top++;
            //PRINT BOTTOM: TOP->BOTTOM
            for (int i=top; i<=bottom; i++){
                ds.push_back(matrix[i][right]);
            }
            right--;
            if (top > bottom || right < left) break;
            //PRINT LEFT: RIGHT->LEFT
            for (int i=right; i>=left; i--){
                ds.push_back(matrix[bottom][i]);
            }
            bottom--;
            //PRINT TOP: BOTTOM->TOP
            for (int i=bottom; i>=top; i--){
                ds.push_back(matrix[i][left]);
            }
            left++;
        }      

        return ds;
    }
};