class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }
    int findUltimateParent(int node){
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]){
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v] = parent[ulp_u];
        }
        else{
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u] = parent[ulp_v];
        }
        return ;
    }
};
class Solution {
public:
    int V;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        V = edges.size();
        DisjointSet ds(V);
        for (auto it : edges){
            int u = it[0], v = it[1];
            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                ds.unionBySize(u,v);
            }
            else{
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
        }
        return ans;
    }
};