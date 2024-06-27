using ll = long long int;
class Solution {
public: 
    int n;
    void dfs(int indx, int& cnt, vector<vector<int>>& bombs, vector<int> &vis, int &maxi){
        vis[indx]++;
        cnt++;
        maxi=max(maxi, cnt);
        for (int i=0; i<n; i++){
            if (vis[i]) continue;
            int x1 = bombs[indx][0], y1 = bombs[indx][1], x2 = bombs[i][0], y2 = bombs[i][1];
            ll radius = bombs[indx][2], area = radius*radius;
            ll x_dist = abs(x2-x1), y_dist = abs(y2-y1);
            ll dist = x_dist*x_dist + y_dist*y_dist;
            if (dist <= area){
                dfs(i, cnt, bombs, vis, maxi);
            }
        }
        return ;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int maxi = 1;
        n = bombs.size();
        for (int i=0; i<n; i++){
            vector<int> vis(n,0);
            int cnt = 0;
            dfs(i, cnt, bombs, vis, maxi);
        }
        return maxi;
    }
};