using ll = long long int;
typedef pair<ll, char> pi;
class Solution {
public:
    void dijkstra(char src, vector<vector<ll>>& dist, unordered_map<char, vector<pair<char, int>>>& mp){
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        minHeap.push({0, src}); dist[src-'a'][src-'a'] = 0;
        while (!minHeap.empty()){
            auto node = minHeap.top(); minHeap.pop();
            ll dis = node.first;
            char ch = node.second;
            for (auto &it : mp[ch]){
                char neigh = it.first;
                ll wt = it.second;
                if (dist[src-'a'][neigh-'a'] > dis + wt){
                    minHeap.push({dis+wt, neigh});
                    dist[src-'a'][neigh-'a'] = dis + wt;
                } 
            }
        }
        return ;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> costMatrix(26, vector<ll>(26, 1e15));
        unordered_map<char, vector<pair<char, int>>> adj;
        for (int i=0; i<original.size(); i++){
            char u = original[i], v = changed[i];
            int wt = cost[i];
            adj[u].push_back({v, wt});
        }

        for (char ch='a'; ch<='z'; ch++){
            if (adj.find(ch) == adj.end()) continue;
            dijkstra(ch, costMatrix, adj);
        }

        long long ans = 0;
        for (int i=0; i<source.size(); i++){
            if (source[i] == target[i]) continue; 
            char u = source[i], v = target[i];
            if (costMatrix[u-'a'][v-'a'] == 1e15) return -1;
            ans = ans + costMatrix[u-'a'][v-'a'];
        }
        return ans;
    }
};