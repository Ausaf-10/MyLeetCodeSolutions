class Solution {
public:
    int timer;
    void dfs(vector<int> adj[], int node, int parent, vector<int> &vis, int tin[], int low[],
        vector<vector<int>> &bridges){
        vis[node] = 1;
        
        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adj[node]){
            if (parent == it) continue;
            if (!vis[it]){
                dfs(adj,it,node,vis,tin,low,bridges);
                low[node] = min(low[node], low[it]);  // UPDATE THE LOW OF PARENT
                
                if (tin[node] < low[it]){              
                    bridges.push_back({node,it});
                } 
            }
            else{                                    
                low[node] = min(low[node], low[it]);
            }
        }

        return ;
    }
    vector<vector<int>> criticalConnections(int V, vector<vector<int>>& connections) {
        // THIS IS GOING TO BE SOLVED USING TARJANS ALGORITHM 
        // BRDIGE -> AN EDGE WHOSE REMOVAL DIVIDES INTO 2 OR MORE COMPONENTS!
        // WHICH IS NOTHING BUT A DFS WITH FEW VARIATIONS 

        // HAR EK NODE A KA LOW[] AND INSERTION TIME[]
        // INSERTION TIME -> KITNE STEPS LAGENGE USS NODE TAK PAHONCHNE MEIN AND
        
        // LOW[] -> AT MIN MEIN KIS NODE TAK PAHONCH SKTA HOON WHICH ARE MY CHILDREN ONLY!
        // LOW[] -> LOWEST INSERTION TIME OF ADJACENT NODES APART FROM PARENT!
        

        // 1. JAB AAP KISI NODE PE AUR AAGE NHI JAA SKTE THEN PICK UP THE LOW OF THAT NODE'S CHILDREN
        // 2. JAB WAPAS AATE HAIN PARENT NODE PE TOH AGAIN PARENT KA LOW CHANGE KR DO
        // 3 .AND NOW CHECK WHETER THIS EDGE B/W PARENT AND CHILD CAN BE A BRIDGE OR NOT 
        // IF (LOW[CHILD] <= INSERTION TIME[PARENT]) -> NO BRIDGE
        // ELSE  FOR BRIDGE -> LOW[CHILD] > INSERTION TIME[PARENT], WHICH MEANS IF WE REMOVE THE EDGE THEN THEY WILL NOT BE REACHABLE 


        vector<int> adj[V];                 // SC: O(V+2E)
        for (auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        // SC: O(3V)
        int tin[V] , low[V] ;      
        vector<int> vis(V,0);                
        
        vector<vector<int>> bridges;        
        dfs(adj,0,-1,vis,tin,low, bridges);     // TC: O(V+2E)

        return bridges;

    }
};