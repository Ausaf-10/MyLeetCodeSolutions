class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (!node) return true;
        bool lt = validate(node->left, prev);
        if (prev!=NULL && node->val <= prev->val) return false;
        prev = node;
        bool rt = validate(node->right, prev);
        return lt && rt;
    }
};