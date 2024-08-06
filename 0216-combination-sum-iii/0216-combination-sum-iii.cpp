class Solution {
public:
    int n,k;
    void recursion(int indx, int var_sum, vector<int>& ds, vector<vector<int>>& ans){
        if (ds.size() == k || indx == 10){
            if (var_sum == 0){
                if (ds.size() == k){
                    ans.push_back(ds);
                }
            }
            return ;
        }
        // PICK
        ds.push_back(indx);
        recursion(indx+1, var_sum-indx, ds, ans);
        ds.pop_back();

        // NOT PICK;
        recursion(indx+1, var_sum, ds, ans);
        return ;
    }
    vector<vector<int>> combinationSum3(int K, int N) {
        n = N, k = K;
        vector<int> ds; 
        vector<vector<int>> ans;
        recursion(1, n, ds, ans);
        return ans;
    }
};