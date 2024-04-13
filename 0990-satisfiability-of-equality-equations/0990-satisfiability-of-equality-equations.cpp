class DisjointSet{
    public:
        vector<int> parent,size;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for (int i=0; i<=n; i++){
                parent[i] = i;
            }
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
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        for (int i=0; i<equations.size(); i++){
            int u = equations[i][0]-'a', v = equations[i][3]-'a';
            char ch1 = equations[i][1] , ch2 = equations[i][2];
            if (ch1 == ch2){
                ds.unionBySize(u,v);
            }
        }
        for (int i=0; i<equations.size(); i++){
            int u = equations[i][0]-'a', v = equations[i][3]-'a';
            char ch1 = equations[i][1] , ch2 = equations[i][2];
            if (ch1 != ch2){
                if (ds.findUPar(u) == ds.findUPar(v)) return false;
            }
        }
        return true;
    }

};