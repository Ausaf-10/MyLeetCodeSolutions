class Solution {
public:
    
    void find(int i,int n,int target,int k, vector<int> &ds,vector<vector<int>> &ans){
        if (i > n || i>10) return;
        
        if (ds.size() == k){
            
            if (target == 0){
                ans.push_back(ds);
            }
        
            return;
        }
        //PICK
        if ( i <= target){
            ds.push_back(i);
            find(i+1,n,target-i,k,ds,ans);
            ds.pop_back();
        }
        find(i+1,n,target,k,ds,ans);
        return;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> ds; 
        vector<vector<int>> ans;
        find(1,n,n,k,ds,ans);
        return ans;
    }
};