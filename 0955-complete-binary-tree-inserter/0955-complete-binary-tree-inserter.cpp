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
class CBTInserter {
public:
    TreeNode* root;
    int indx;
    unordered_map<int, TreeNode*> mp;
    CBTInserter(TreeNode* node) {
        root = node;
        indx  = 0;
        queue<pair<TreeNode*, int>> q; q.push({node, 0}); 
        while (!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto it = q.front(); q.pop();
                TreeNode* noodee = it.first;
                indx = it.second;
                mp[indx] = noodee;
                if (noodee->left) q.push({noodee->left,2*indx+1});
                if (noodee->right) q.push({noodee->right,2*indx+2});
            } 
        }
    }
    
    int insert(int val) {
        indx++;
        int parent = (indx-1)/2;
        TreeNode* parentNode = mp[parent];
        TreeNode* newNode = new TreeNode(val);
        if (!parentNode->left){
            parentNode->left = newNode;
        }
        else{
            parentNode->right = newNode;
        }
        mp[indx] = newNode;
        return parentNode->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */