class Solution {
public:
    bool checkRow(int sr, int sc, vector<vector<int>>& mat){
        int m = mat[0].size();
        for (int j=0; j<m; j++){
            if (j == sc) continue;
            if (mat[sr][j] == 1) return false;
        }   
        return true;
    }
    bool checkCol(int sr, int sc, vector<vector<int>>& mat){
        int n = mat.size();
        for (int i=0; i<n; i++){
            if (i == sr) continue;
            if (mat[i][sc] == 1){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0) continue;
                if (checkRow(i,j,mat) && checkCol(i,j,mat)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};