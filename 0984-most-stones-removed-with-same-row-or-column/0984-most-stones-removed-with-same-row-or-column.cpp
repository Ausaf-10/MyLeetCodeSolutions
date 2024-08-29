class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1, 1);
        size.resize(n+1, 1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]); 
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        return ;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = 0, m = 0, cnt = 0;
        for (auto it: stones){
            n = max(n, it[0]);
            m = max(m, it[1]);
        }
        DSU dsu(n+m+2);
        for (auto it : stones){
            int row = it[0], col = it[1] + n + 1;
            dsu.unionBySize(row, col);
        }
        for (int i=0; i<n+m+2; i++){
            int ulp = dsu.findUPar(i);
            if (ulp == i && dsu.size[ulp] > 1) cnt++;
        }
        return stones.size()-cnt;
    }
};