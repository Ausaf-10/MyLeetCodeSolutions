using ll = long long int;
class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.second > b.second;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for (auto it : roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<pair<int,int>> deg(n);
        for (int i=0; i<n; i++){
            deg[i] = {i,adj[i].size()};
        }
        sort(deg.begin(), deg.end(), compare);
        ll s = 0;
        int k = n;
        for (int i=0; i<n; i++){
            s += (k*1ll*(deg[i].second));
            k--;
        }
        return s;
    }
};