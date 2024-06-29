class Solution {
public:
    int k;
    vector<int> topoSort(vector<int> adj[]){
        vector<int> indegree(k+1,0);
        for (int i=1; i<=k; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=1; i<=k; i++){
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> arr;
        while (!q.empty()){
            int node = q.front(); q.pop();
            arr.push_back(node);
            for (auto it : adj[node]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if (arr.size() != k) return {};
        return arr;
    }
    vector<vector<int>> buildMatrix(int K, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        k = K;
        vector<int> adjRow[k+1], adjCol[k+1];
        for (auto it : rowConditions){
            adjRow[it[0]].push_back(it[1]);
        }
        for (auto it : colConditions){
            adjCol[it[0]].push_back(it[1]);
        }
        vector<int> rows = topoSort(adjRow);
        vector<int> cols = topoSort(adjCol);
        if (!rows.size() || !cols.size()) return {};
        vector<vector<int>> ans(k, vector<int>(k,0));
        unordered_map<int, int> mp;
        for (int i=0; i<rows.size(); i++){
            mp[rows[i]] = i;
        }
        for (int i=0; i<cols.size(); i++){
            int row = mp[cols[i]], col = i;
            ans[row][col] = cols[i];
        }
        return ans;
    }
};