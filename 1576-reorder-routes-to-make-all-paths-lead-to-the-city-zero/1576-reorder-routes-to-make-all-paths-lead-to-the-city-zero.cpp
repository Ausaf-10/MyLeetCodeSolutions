// WE START FROM 0 AND SEE KI KAUN KAUN SE NODES HUM VISIT KR PAA RHE HAIN FROM 0 AND ALL THE NODES THAT WE ARE ABLE TO VISIT FROM 0, MEANS WE 
// NEED TO REVERSE THOSE EDGES SO THAT'S Y HUM EK NAKLI AUR ASLI EDGE RAKH LENGE JISSE HUM 0 SE SAARE NODES PE VISIT KR SKEIN 
// FROM 0, AGAR HUM KISI CITY PE JAA RHE HAIN FROM ASLI EDGE THEN WOH REVERSE KRNA HAI AND AGAR NHI PAHONCH PAA RHE TOH WOH SAHI EDGE HAI AND 
// USS CITY TAK PAHONCHNE KE LIYE HUM EK NAKLI EDGE KE THROUGH PAHONCH SKTE HAIN
class Solution {
public:    
    int minReorder(int V, vector<vector<int>>& connections) {
        // CREATING THE ADJACENCY LIST, ASLI-> 1, NAKLI -> 0
        
        vector<pair<int,int>> adj[V];
        
        for (auto it : connections){
            int u = it[0], v = it[1];   // u->v
            adj[u].push_back({v,1});    // this is the original edge -> 1
            adj[v].push_back({u,0});    // nakli edge -> 0
        }

        vector<int> vis(V,0);
        queue<int> q; vis[0] = 1; q.push(0);

        int reverseEdges = 0;
        while (!q.empty()){
            int node = q.front(); q.pop();

            for (auto it : adj[node]){
                int neighbor = it.first, edgeWeight = it.second;
                if (!vis[neighbor]){
                    if (edgeWeight == 1){
                        reverseEdges++;
                    }
                    q.push(neighbor);
                    vis[neighbor] = 1;
                } 
            }
        }

        return reverseEdges;
    }
};