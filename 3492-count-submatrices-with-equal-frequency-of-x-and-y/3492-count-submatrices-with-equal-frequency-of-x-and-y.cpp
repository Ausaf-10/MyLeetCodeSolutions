class Solution {
public:
    int n,m;
    void calculatePrefix(vector<vector<char>>& mat, vector<vector<int>> &prefix, char ch){
        for (int i=0; i<n; i++){
            if (mat[i][0] == ch) prefix[i][0] = 1;
        }

        for (int i=0; i<n; i++){
            for (int j=1; j<m; j++){
                if (mat[i][j] == ch){
                    prefix[i][j] = prefix[i][j-1] + 1;
                }
                else{
                    prefix[i][j] = prefix[i][j-1];
                }
            }
        }

        for (int i=1; i<n; i++){
            for (int j=0; j<m; j++){
                prefix[i][j] = prefix[i][j] + prefix[i-1][j];
            }
        }
        return ;
    }
    int numberOfSubmatrices(vector<vector<char>>& mat) {
        n = mat.size(), m = mat[0].size();
        int cntX = 0, cntY = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 'X') cntX++;
                else if (mat[i][j] == 'Y') cntY++;
            }
        }
        if (!cntX || !cntY) return 0;

        vector<vector<int>> prefixX (n, vector<int>(m,0));
        vector<vector<int>> prefixY (n, vector<int>(m,0));
        
        calculatePrefix(mat, prefixX, 'X'); calculatePrefix(mat, prefixY, 'Y');
        
        int cnt = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (prefixX[i][j] == prefixY[i][j] && prefixX[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};