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
    int makeConnected(int n, vector<vector<int>>& edges) {
        int extraEdges = 0;
        DisjointSet ds(n);
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            
            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                ds.UnionBySize(u,v);
            }
            else extraEdges++;
        }
        
        int numberOfComponents = 0;
        for (int i=0; i<n; i++) if (ds.parent[i] == i) numberOfComponents++;
        
        int ans = numberOfComponents-1;
        if (extraEdges >= ans) return ans;
        
        return -1;
        
    }
};