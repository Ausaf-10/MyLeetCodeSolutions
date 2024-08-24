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
        if (node->right!=NULL) pushAll(node->right,stk);
        return node->val;
    }
    
    bool hasNext() {
        if (stk.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */