// ISMEIN HUME WOH COORDINATES CHAHIYE JAHAN PE PACIFIC AUR ATLANTIC DONO KA PAANI AA RHA HAI, TO ISKE LIYE REVERSE ENGG. LAGA KE SOLVE KRTE HAIN
// INSTEAD OF GOING TO EVERY CELL AND THEN CHECK WILL WE BE ABLE TO REACH TO ATLANTIC AND PACIFIC FROM THIS CELL OR NOT 
// WHAT WE DO IS THAT WE GO FROM PACIFIC AND MARK ALL THE CELLS THAT CAN GET WATER FROM PACIFIC IN INCREASING ORDER 
// SIMILARY THIS IS DONE FOR THE ATLANTIC OCEAN AS WELL AND ONCE WE HAVE CALCUALTED THE WATER FOR BOTH THE OCEANS FOR ALL THE CELLS, WE COMBINED
// THE COMMON CELLS AND RETURN THEM AS THE ANSWER!!!!
class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &vis){
        if (row>=0 && row<n && col>=0 && col<m && !vis[row][col]) return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &vis){
        vis[row][col] = 1;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;                                         // TC : O(N*M*4)              
            int ncol = delcol[i] + col;
            
            if (isValid(grid,nrow,ncol,vis) && grid[row][col] <= grid[nrow][ncol]){
                dfs(grid,nrow,ncol,vis);
            } 
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> result;
        
        // FIRSTlY START FROM THE PACIFIC -> NOW WE KNOW THE TOP(0th ROW) AND LEFT EDGE(0th COLUMN) CELLS WILL BE COVERED WITH PACIFIC
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (i == 0 || j == 0){
                    dfs(grid,i,j,pacific);
                }
            }
        }
        // NOW ATLANTIC -> NOW WE KNOW THE BOTTOM(N-1 th ROW) AND RIGHT EDGE(M-1 th COLUMN) CELLS WILL BE COVERED WITH PACIFIC
       for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (i == n-1 || j == m-1){
                    dfs(grid,i,j,atlantic);
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (pacific[i][j] == 1 && atlantic[i][j] == 1){
                    result.push_back({i,j});
                }
            }
        }

        return result;

    }
};