class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int room, vector<int>& vis){
        vis[room] = 1;

        for (auto it : rooms[room]){
            if (!vis[it]){ 
                dfs(rooms, it, vis);
            }
        }

        return ;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(rooms, 0, vis);
        for (auto x : vis){
            if (x == 0) return false;
        }

        return true;
    }
};