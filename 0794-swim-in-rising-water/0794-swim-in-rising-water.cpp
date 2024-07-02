class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    int n,m;
    bool isValid(int row, int col){
        if (row>=0 && row<n && col>=0 && col<m) return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> distance(n, vector<int>(m,1e9));
        priority_queue<pair<int, pair<int,int>>, 
        vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        int maxi = mat[0][0]; 
        distance[0][0] = mat[0][0];
        pq.push({mat[0][0],{0,0}});
        
        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            int time = node.first, row = node.second.first, col = node.second.second;
            if (row == n-1 && col == n-1) return time;
            for (int i=0; i<4; i++){
                int nrow = dir[i][0] + row, ncol = col + dir[i][1];
                if (isValid(nrow, ncol)){
                    int diff = max(time, mat[nrow][ncol]);
                    if (diff < distance[nrow][ncol]){
                        distance[nrow][ncol] = diff;
                        pq.push({diff, {nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};