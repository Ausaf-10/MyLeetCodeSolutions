class Solution {
public:

    void find(int i,int sum,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans){
        if (i == arr.size() ){
            if (sum == 0){
                ans.push_back(ds);
            }
            return ;
        }
        //PICK
        if (arr[i] <= sum){
            ds.push_back(arr[i]);
            find(i,sum-arr[i],arr,ds,ans);
            ds.pop_back();
        }

        find(i+1,sum,arr,ds,ans);
        return;
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(0,target,candidates,ds,ans);
        return ans;

    }
};