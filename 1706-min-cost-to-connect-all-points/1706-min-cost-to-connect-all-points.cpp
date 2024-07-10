using ll = long long int;
class DSU{
public:
    vector<int> parent,size;
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for (int i=0; i<=n; i++) parent[i] = i;
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return ;

        if (size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
    
    int findUPar(int node){
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        ll n = points.size(), s = 0;
        vector<vector<ll>> edges;
        DSU ds(n);
        for (ll i=0; i<points.size(); i++){
            for (ll j=i+1; j<points.size(); j++){
                ll wt = abs(points[i][0] - points[j][0]);
                wt = wt + abs(points[i][1] - points[j][1]);
                edges.push_back({wt,i,j});
            }
        }
        sort(edges.begin(), edges.end());
        for (auto it : edges){
            ll wt = it[0], u = it[1], v = it[2];
            ll ulp_u = ds.findUPar(u), ulp_v = ds.findUPar(v);
            if (ulp_u == ulp_v) continue;
            s+=wt;
            ds.unionBySize(u,v);
        }
        return s;
    }
};