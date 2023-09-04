class Solution {
public:
    int n;
    bool dfs(vector<vector<int>>& grid,int node,int iniColor,vector<int> &color){
        if (color[node] == -1) color[node] = iniColor;

        for (auto adjNodes : grid[node]){
            if (color[adjNodes] == -1){
                if (dfs(grid,adjNodes,!color[node],color) == false) return false;
            }
            else if (color[adjNodes]!=-1 && color[adjNodes] == color[node]) return false;
        }

        return true;
    }
    bool bfs(vector<vector<int>>& adj, int& src){
        queue<pair<int,int>> q;
        vector<int> color(n,-1);
        color[src] = 0; q.push({src,0});
        while (!q.empty()){
            int node = q.front().first, newColor = q.front().second;
            q.pop();

            for (auto it : adj[node]){
                if (color[it] == -1){
                    q.push({it,!color[node]});
                    color[it] = !color[node];
                }
                else if (color[it] == color[node]) return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& grid) {
        n = grid.size();

        vector<int> color(n,-1);
        int iniColor = 0;

        for (int i=0; i<n; i++){
            if (color[i] == -1){
                if (bfs(grid,i) == false) return false;
            }
        }

        return true;
    }
};