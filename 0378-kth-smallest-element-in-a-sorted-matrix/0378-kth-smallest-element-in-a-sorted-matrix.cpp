class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        int low = mat[0][0], high = mat[n-1][m-1];
        while (low <= high){
            int mid = low + (high - low)/2;
            int cnt = 0;
            for (int i=0; i<n; i++){
                cnt+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            }
            if (cnt < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};