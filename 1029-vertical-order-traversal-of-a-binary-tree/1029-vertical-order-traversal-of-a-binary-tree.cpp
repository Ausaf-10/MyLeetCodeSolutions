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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        // NODE,VERTICAL,LEVEL
        queue<pair<TreeNode*,pair<int,int>>> q;

        // MAP : VERTICAL -> LEVEL -> NODES, using multiset to store multiple duplicate values in sorted order
        map<int,map<int,multiset<int>>> mp;

        q.push({root,{0,0}});

        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                int vertical = q.front().second.first;
                int level = q.front().second.second;

                q.pop();

                mp[vertical][level].insert(node->val);

                if (node->left!=NULL) q.push({node->left,{vertical-1,level+1}});
                if (node->right!=NULL) q.push({node->right,{vertical+1,level+1}});
            }
        }

        for (auto p : mp){
            vector<int> col;
            for (auto q : p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};