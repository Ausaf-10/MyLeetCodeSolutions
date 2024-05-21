class Solution {
public:

    void generateSubset(int i,vector<int>&arr,vector<int>& ds,vector<vector<int>>& ans){
        if (i == arr.size()){
            ans.push_back(ds);
            return;
        }
        //PICK
        ds.push_back(arr[i]);
        generateSubset(i+1,arr,ds,ans);
        //not pick
        ds.pop_back();
        generateSubset(i+1,arr,ds,ans);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int>ds;
       generateSubset(0,nums,ds,ans);
       return ans; 
    }
};