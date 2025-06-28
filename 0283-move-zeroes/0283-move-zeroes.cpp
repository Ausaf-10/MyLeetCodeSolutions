class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int indx = -1, n = arr.size();
        for (int i = 0; i<n; i++){
            if (arr[i] == 0){
                indx = i;
                break;
            }
        }
        if (indx == -1) return ;
        for (int i = indx; i<n; i++){
            if (arr[i] == arr[indx]) continue;
            swap(arr[i], arr[indx++]);
        }
        return ;
    }
};