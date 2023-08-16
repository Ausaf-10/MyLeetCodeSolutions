class Solution {
public:
    bool binarySearch(vector<int>& arr, int target){
        int low = 0, high = arr.size()-1;
        while (low <= high){
            int mid = (low + high)/2;
            if (arr[mid] == target) return true;
            else if (arr[mid] > target) high--;
            else low++;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();

        for (int i=0; i<n; i++){
            if (mat[i][0]<=target && target<=mat[i][m-1] && binarySearch(mat[i] , target)) return true;    
        }

        return false;
    }
};