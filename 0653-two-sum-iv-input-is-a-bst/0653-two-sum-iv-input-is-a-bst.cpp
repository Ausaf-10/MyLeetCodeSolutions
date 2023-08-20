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
    bool reverse = false;
    // reverse->true -> before;
    // reverse->false -> next;
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;  
        pushAll(root);
    }
    bool hasNext() {
        if (!stk.empty()) return true;
        return false;
    }
    
    int next() {
        TreeNode* node = stk.top(); stk.pop();
        if (reverse == false) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
private:
    void pushAll(TreeNode* root){
        for (;root!=NULL;){
            stk.push(root);
            if (reverse) root=root->right;
            else root = root->left;
        }
        return ;
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l (root,false);
        BSTIterator r (root,true);

        int i=l.next(), j = r.next();
        while (i<j){
            if (i + j == k) return true;
            else if (i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};