class Solution {
public:
    void getInorder(TreeNode* root,vector<int>&ds){
        if (root == NULL) return ;
        getInorder(root->left,ds);
        ds.push_back(root->val);
        getInorder(root->right,ds);
        return ;
    }
    
    TreeNode* solve(vector<int>& arr, int start, int end){
        if (start > end) return NULL;
        int mid = start + (end-start)/2;

        TreeNode* root = new TreeNode(arr[mid]);
        root->left = solve(arr, start, mid-1);
        root->right = solve(arr, mid+1, end);
        return root;
    }
    TreeNode* constructFromInorder(vector<int>& arr){
        if (arr.size() == 1){
            return new TreeNode(arr[0]);
        }
        int start = 0, end = arr.size()-1;
        return solve(arr, start, end);
   
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if (root == NULL) return NULL;
        vector<int> inorder;
        getInorder(root,inorder);
       
        return constructFromInorder(inorder);
    }
};