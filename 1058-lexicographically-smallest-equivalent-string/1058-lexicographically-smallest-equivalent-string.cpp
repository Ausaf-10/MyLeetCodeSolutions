class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1, 0);
            for (int i=0; i<=n; i++) parent[i] = i;
        }
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u), ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (ulp_u <= ulp_v){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
            }            
            return ;
        }
        int findUPar(int node){
            if (parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans;
        DisjointSet ds(26);
        for (int i=0; i<s1.size(); i++){
            int u = s1[i]-'a', v = s2[i]-'a';
            ds.unionBySize(u,v);
        }
        for (char &ch: baseStr){
            int ascii = ch-'a'; 
            int ulp = ds.findUPar(ascii);
            ans.push_back(ulp+'a');
        }
        return ans;
    }
};