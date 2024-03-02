class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size(), i = 0, j = n-1, x = n-1;
        vector<int> ans(n);
        while (i <= j){
            int sq1 = pow(arr[i],2);
            int sq2 = pow(arr[j],2);
            if (sq2 > sq1){
                ans[x--] = sq2;
                j--;
            }
            else{
                ans[x--] = sq1;
                i++;
            }
        }
        return ans;
    }
};