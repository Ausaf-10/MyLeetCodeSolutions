class Solution {
public:
    void solve(int indx, vector<int>& arr,vector<vector<int>>& ans){
        if (indx == arr.size()){
            ans.push_back(arr);
            return ;     
        }
        for (int i = indx; i<arr.size(); i++){
            swap(arr[i],arr[indx]);
            solve(indx+1, arr, ans);
            swap(arr[i],arr[indx]);
        }

        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};