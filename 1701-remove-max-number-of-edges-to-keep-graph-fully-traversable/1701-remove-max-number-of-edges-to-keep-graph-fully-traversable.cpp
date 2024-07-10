class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for (int i=1; i<=n; i++) parent[i] = i;
    }
    int findUPar(int node){
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u), ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return ;
        if (size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] =  ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] =  ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        return ;
    }
};
class Solution {
public:
    bool isTraversable(DSU& a, int n){
        int cnt = 0;
        for (int i=1; i<=n; i++){
            if (a.findUPar(i) == i) cnt++;
        }
        return cnt == 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n), bob(n);
        auto cmp = [&](vector<int> a, vector<int> b){
            return a[0] > b[0];
        };
        sort(edges.begin(), edges.end(), cmp);
        int cnt1 = 0, cnt2 = 0;
        for (auto it : edges){
            int type = it[0], u = it[1], v = it[2];
            if (type == 3){
                int ulp_u_alice = alice.findUPar(u), ulp_v_alice = alice.findUPar(v);
                int ulp_u_bob = bob.findUPar(u), ulp_v_bob = bob.findUPar(v);
                if (ulp_u_alice == ulp_v_alice || ulp_u_bob == ulp_v_bob) cnt1++;
                else{
                    alice.unionBySize(u,v);
                    bob.unionBySize(u,v);
                }
            }
        }
        for (auto it : edges){
            int type = it[0], u = it[1], v = it[2];
            if (type == 2){
                int ulp_u = bob.findUPar(u), ulp_v = bob.findUPar(v);
                if (ulp_u == ulp_v) cnt2++;
                else{
                    bob.unionBySize(u,v);
                }
            }
        }
        if (!isTraversable(bob, n)) return -1;
        for (auto it : edges){
            int type = it[0], u = it[1], v = it[2];
            if (type == 1){
                int ulp_u = alice.findUPar(u), ulp_v = alice.findUPar(v);
                if (ulp_u == ulp_v) cnt2++;
                else{
                    alice.unionBySize(u,v);
                }
            }
        }
        if (!isTraversable(alice, n)) return -1;
        return cnt1 + cnt2;

    }
};