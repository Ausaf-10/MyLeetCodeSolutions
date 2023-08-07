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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for (auto it : matrix){
            if (binarySearch(it , target)) return true;    
        }

        return false;
    }
};