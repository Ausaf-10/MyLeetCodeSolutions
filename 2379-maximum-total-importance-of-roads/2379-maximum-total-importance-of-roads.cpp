using ll = long long int;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>> pq;
        unordered_map<int, int> mp;
        vector<int> adj[n];
        for (auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i=0; i<n; i++){
            int size = adj[i].size();
            pq.push({size,i});
        }
        int k = n;
        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            mp[node.second] = k;
            k--;
        }
        ll s = 0;
        for (int i=0; i<roads.size(); i++){
            s+=mp[roads[i][0]];
            s+=mp[roads[i][1]];
        }
        return s;
    }
};