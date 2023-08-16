class Solution {
public:
    int getLowerbound(vector<int> arr, int m, int x){
        int low =0, high = m-1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] >= x){
                high = mid-1;
            }
            else low = mid + 1;
        }
        return low;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCnt = 0, n = mat.size(), m = mat[0].size();
        int indx = -1;
        
        for (int i=0; i<n; i++){
            sort(mat[i].begin(), mat[i].end());
        }
       
        for (int i=0; i<n; i++){
            // int lb = lower_bound(mat[i].begin(), mat[i].end(),1) - mat[i].begin();
            int lb = getLowerbound(mat[i],m,1);
            int cnt = m - lb;
            if (cnt > maxCnt){
                maxCnt = cnt;
                indx = i;
            }
        }   

        if (maxCnt == 0) return {0,0};
        
        return {indx, maxCnt};
    }
};