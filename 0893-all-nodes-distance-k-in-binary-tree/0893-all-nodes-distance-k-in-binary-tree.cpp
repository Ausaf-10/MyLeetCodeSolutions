/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp ){
        // BFS TRAVERSAL
        // queue<TreeNode*> q;
        // q.push(root);
        
        // while (!q.empty()){
        //     int size = q.size();
        //     for (int i=0; i<size; i++){
        //         TreeNode* node = q.front();
        //         q.pop();
               
        //         if (node->left!=NULL){
        //             q.push(node->left);
        //             mp[node->left] = node;
        //         }
        //         if (node->right!=NULL){
        //             q.push(node->right);
        //             mp[node->right] = node;
        //         }
        //     }
        // }

        if (root == NULL) return ;
        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;
        markParents(root->left,mp);
        markParents(root->right,mp);
        
        return ;
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL) return ans; 
        if (k == 0) return {target->val};
            
        // NODE->PARENT
        unordered_map<TreeNode*,TreeNode*> parentTrack;
        markParents(root,parentTrack);
        
        // TAKING A VISITED MAP TO KEEP A TRACK OF ALL THE NODES WHICH HAVE BEEN VISITED
        unordered_map<TreeNode*,bool> vis;
        // AGAIN DOING A LEVEL ORDER TRAVERSAL FROM THE TARGET NODE
        queue<TreeNode*> q;
        q.push(target);
        
        vis[target] = true; // MARK THE TARGET NODE AS VISITED
        
        int curr_level = 0;
        
        while (!q.empty() && curr_level!=k){
            
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                //CHECKING FOR ITS LEFT
                if (node->left!=NULL && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                //CHECKING FOR ITS RIGHT
                if (node->right!=NULL && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                //CHECKING FOR ITS PARENT
                if (parentTrack[node]!=NULL && !vis[parentTrack[node]]){
                    q.push(parentTrack[node]);
                    vis[parentTrack[node]] = true;
                }
            }
            
            curr_level++;
        }
        
        // PUTTING ALL ELEMENTS FROM QUEUE TO ANS
        while (!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
                
        return ans;
    }
};