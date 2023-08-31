class Solution {
public:
    int method1(int n, vector<vector<int>>& trust){
        vector<int> adj[n+1];
        // FIRST CREATE AN ADJACENY LIST
        for (auto it : trust){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }
        
        // THIS PERSON CAN BE A TOWN JUDGE!
        int townJudge = -1;
        for (int i=1; i<=n; i++){
            if (adj[i].size() == 0){
                townJudge = i;
                break;
            }
        }

        // NOW CHECK WHETHER THIS CAN BE A TOWN EDGE OR NOT 
        for (int i=1; i<=n; i++){
            bool flag = 0;
            if (i == townJudge) continue;
            for (auto it : adj[i]){
                if (it == townJudge){
                    flag = 1;
                }
            }
            if (flag == 0) return -1; 
        }
        return townJudge;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        // WE CAN STORE THE INDEGREE AND OUTDDEGREE OF EVERY NODE 
        // INDGREE(TOWN JUDGE) == N-1 && OUTDEGREE(TOWN JUDGE) == 0
        vector<int> inDegree(n+1,0);
        vector<int> outDegree(n+1,0);
        for (auto it : trust){
            int u = it[0], v = it[1];
            inDegree[v]++, outDegree[u]++;
        }
        for (int i=1; i<=n; i++){
            if (inDegree[i] == n-1 && outDegree[i] == 0) return i;
        }
        return  -1;
    }
};