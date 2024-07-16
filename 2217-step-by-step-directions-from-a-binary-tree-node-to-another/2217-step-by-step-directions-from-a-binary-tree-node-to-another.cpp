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
    void parentTrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &mp, int startValue, int destValue){
        if (!root) return ;
        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;
        parentTrack(root->left, mp, startValue, destValue);
        parentTrack(root->right, mp, startValue, destValue);
        return ;
    }
    TreeNode* getNode(TreeNode* root, int startValue) {
        if (!root) return nullptr;
        if (root->val == startValue) return root;
        TreeNode* lt = getNode(root->left, startValue);
        TreeNode* rt = getNode(root->right, startValue);
        if (lt) return lt;
        return rt;
    }
    bool solve(TreeNode* root, int &destValue, unordered_map<TreeNode*, TreeNode*> &mp, 
        string& path, unordered_set<int> &vis){
        if (!root) return false;
        vis.insert(root->val);
        if (root->val == destValue) return true;
        if (root->left && !vis.count(root->left->val)){
            path.push_back('L');
            if (solve(root->left, destValue, mp, path, vis)) return true;
        }
        if (root->right && !vis.count(root->right->val)){
            path.push_back('R');
            if (solve(root->right, destValue, mp, path, vis)) return true;
        }
        if (mp[root] && !vis.count(mp[root]->val)){
            path.push_back('U');
            if (solve(mp[root], destValue, mp, path, vis)) return true;
        }
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_set<int> vis;
        parentTrack(root, mp, startValue, destValue);
        TreeNode* node = getNode(root, startValue);
        string path;
        if (solve(node, destValue, mp, path, vis)) return path;
        return "";
    }
};