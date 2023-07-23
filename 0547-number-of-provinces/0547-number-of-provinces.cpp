
class DisjointSet{
    public:
        vector<int> parent,size;
        DisjointSet(int n){
            size.resize(n+1,1);
           
            parent.resize(n+1,0);
            for (int i=0; i<=n; i++) parent[i] = i;
        }

        int findUltimateParent(int node){
            if (parent[node] == node) return node;
            return parent[node] = findUltimateParent(parent[node]);
        }

        void UnionBySize(int u, int v){
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
            if (ulp_u == ulp_v) return ;
            if (size[ulp_u] < size[ulp_v]){
                size[ulp_v]+=size[ulp_u];
                parent[ulp_u] = parent[ulp_v]; 
            }
            else{
                size[ulp_u]+=size[ulp_v];
                parent[ulp_v] = parent[ulp_u]; 
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        DisjointSet ds(V);
        for (int i=0; i<V; i++){
            for (int j=0; j<V; j++){
                if (adj[i][j] == 1){
                    ds.UnionBySize(i,j);
                }
            }
        }
        int cnt = 0 ;
        for (int i=0; i<V; i++){
            int x = ds.findUltimateParent(i);
        }
        for (int i=0; i<V; i++){
            if (ds.parent[i] == i) cnt++;
        }
        
        return cnt;
        
    }
};