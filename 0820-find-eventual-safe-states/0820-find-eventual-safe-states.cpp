class Solution {
public:
    int V;
    bool dfs(vector<int> adj[], int node, vector<int>& vis, vector<int>& pathVis, vector<int>& checkNode){
        vis[node] = 1, pathVis[node] = 1;
        for (auto neighbor : adj[node]){
            if (!vis[neighbor]){
                if (dfs(adj, neighbor, vis, pathVis, checkNode)) return true;
            }
            else if (pathVis[neighbor]) return true;
        }

        pathVis[node] = 0;
        checkNode[node] = 1;

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        V = graph.size();
        vector<int> adj[V];
        for (int i=0; i<graph.size(); i++){
            for (int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>checkNode(V,0);

        for (int i=0; i<V; i++){
            if (!vis[i]){
                if (dfs(adj,i,vis,pathVis,checkNode));
            }
        }

        vector<int> safeNodes;
        for (int i=0; i<V; i++){
            if (checkNode[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};