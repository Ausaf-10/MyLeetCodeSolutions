class DisjointSet{
    vector<int> parent,size;
    public:
        DisjointSet(int n){
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for (int i=0; i<=n; i++) parent[i] = i;
        }
        int findUPar(int node){
            if (parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]){
                size[ulp_v]+=size[ulp_u];
                parent[ulp_u] = ulp_v;
            }
            else{
                size[ulp_u]+=size[ulp_v];
                parent[ulp_v] = ulp_u;
            }
        }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            ds.unionBySize(u,v);
        }

        if (ds.findUPar(source)== ds.findUPar(destination)) return true;
        return false;
    }
};