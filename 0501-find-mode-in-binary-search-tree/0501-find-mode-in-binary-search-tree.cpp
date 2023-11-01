/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getInorder(TreeNode* root, vector<int>& arr){
        if (root == NULL) return ;
        getInorder(root->left, arr);
        arr.push_back(root->val);
        getInorder(root->right, arr);
        return ;
    }
    vector<int> findMode(TreeNode* root) {
        // WITHOUT HASH MAP
        // GETTING THE INORDER OF BST AND THEN STORING IT IN AN ARRAY AND THEN FINDING OUT THE MODE
        vector<int> inorder;
        getInorder(root, inorder);
        vector<int> ans;
        int maxStreak = 0, currNum = 0, currStreak = 0;

        for (int number : inorder){
            if (number == currNum){
                currStreak++;
            }
            else{
                currStreak = 1;
                currNum = number;
            }

            if (currStreak > maxStreak){
                ans = {};
                maxStreak = currStreak;
            }
            if (currStreak == maxStreak){
                ans.push_back(number);
            }
        }

        return ans;
        
    }
};