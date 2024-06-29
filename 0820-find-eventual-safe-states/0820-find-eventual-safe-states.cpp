class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1 , pathVis[node] = 1;
        
        for (auto neighbour : adj[node]){
            if (!vis[neighbour]) {
                if (dfs(adj,neighbour,vis,pathVis)) return true;
            }
            else if (pathVis[neighbour]) return true;
        }

        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for (int i=0; i<V; i++){
            if (!vis[i])
                if (dfs(graph,i,vis,pathVis)) ;
        }

        vector<int> ans;
        for (int i=0; i<V; i++){
            if (!pathVis[i]) ans.push_back(i);
        }
        
        return ans;
    }

};