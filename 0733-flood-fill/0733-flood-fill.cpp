class Solution {
public:
    int n, m;
    bool isValid(vector<vector<int>>& image, vector<vector<int>>& vis,  int row, int col, int iniColor){
        if (row>=0 && row<n && col>=0 && col<m && !vis[row][col] && image[row][col] == iniColor){
            vis[row][col] = 1;
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>>& image, vector<vector<int>>& newImage, vector<vector<int>>& vis, int row, int col, int iniColor, int color){
        vis[row][col] = 1, newImage[row][col] = color;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if (isValid(image,vis,nrow,ncol,iniColor)){
                newImage[nrow][ncol] = color;
                dfs(image, newImage, vis, nrow, ncol, iniColor, color);
            }
        }

        return ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        vector<vector<int>> newImage = image;
        vector<vector<int>> vis(n, vector<int>(m,0));

        if (image[sr][sc] == color) return newImage;
        int iniColor = image[sr][sc];

        dfs(image, newImage, vis, sr, sc, iniColor, color);

        return newImage;
    }
};