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
class BSTIterator {
public:
    void pushAll(TreeNode* root, stack<TreeNode*>& stk){
        TreeNode* cur = root;
        while (cur){
            stk.push(cur);
            cur = cur->left;
        }
        return ;
    }
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root,stk);
    }
    
    int next() {
        TreeNode* node = stk.top(); stk.pop();
        if (node->right!=NULL){
            TreeNode*  cur = node->right;
            pushAll(cur,stk);
        }
        return node->val;
    }
    
    bool hasNext() {
        if (!stk.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */