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
    pair<int,int> fun(TreeNode* root, int& cnt){
        if (root == NULL) return {0,0};
        
        if (root->left == NULL && root->right == NULL){
            cnt++;
            return {root->val, 1};
        }

        pair<int,int> leftTree = fun(root->left, cnt);
        pair<int,int> rightTree = fun(root->right, cnt);

        int curSum = leftTree.first + rightTree.first + root->val;
        int curCnt = leftTree.second + rightTree.second + 1;
        int avg = curSum / curCnt;

        if (avg == root->val) cnt++;

        return {curSum, curCnt};

    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        pair<int,int> p = fun(root, cnt);
        return cnt;
   }
};