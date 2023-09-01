using ll = long long int;
class DisjointSet{
    public: 
    vector<int> parent, size;
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
        if (ulp_u == ulp_v) return ;
        if (size[ulp_u] > size[ulp_v]){
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = parent[ulp_u]; 
        } 
        else{
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = parent[ulp_v]; 
        }
        return ;
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for (auto it : edges){
            int u = it[0], v = it[1];
            ds.unionBySize(u,v);
        }
        ll cnt = 0;
        ll s=0;
        vector<int> vec;
        for (int i=0; i<n; i++){
            if (ds.parent[i] == i) vec.push_back(i);
        }
        
        for (int i=0; i<vec.size(); i++){
            ll curPar = vec[i];
            ll curSize = ds.size[curPar];
            cnt+=(curSize)*(n-s-curSize);
            s+=curSize;
        }

        return cnt;
        
    }
};