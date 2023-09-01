class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n);
        for (auto it : edges){
            int u = it[0], v = it[1];
            inDegree[v]++;
        }
        vector<int> ans;
        for (int i=0; i<n; i++){
            if (inDegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};