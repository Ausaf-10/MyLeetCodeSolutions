class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int node,int iniColor,vector<int> &color){
        int n = grid.size();
        if (color[node] == -1) color[node] = iniColor;

        for (auto adjNodes : grid[node]){
            if (color[adjNodes] == -1){
                if (dfs(grid,adjNodes,!color[node],color) == false) return false;
            }
            else if (color[adjNodes]!=-1 && color[adjNodes] == color[node]) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> color(n,-1);
        int iniColor = 0;

        for (int i=0; i<n; i++){
            if (color[i] == -1){
                if (dfs(grid,i,iniColor,color) == false) return false;
                // iniColor = !iniColor;
            }
        }

        return true;
    }
};