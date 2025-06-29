class Solution {
public:
    int k;
    void fun(int indx, vector<vector<int>> &ans, vector<int>& ds, int var_sum){
        if (indx > 9 || var_sum == 0){
            if (var_sum == 0){
                if (ds.size() == k){
                    ans.push_back(ds);
                }
            }
            return;
        }
        for (int i=indx; i<=9; i++){
            if (i <= var_sum){
                ds.push_back(i);
                fun(i+1, ans, ds, var_sum-i);
                ds.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int K, int n) {
        k = K;
        vector<vector<int>> ans;
        vector<int> ds;
        fun(1, ans, ds, n);
        return ans;
    }
};