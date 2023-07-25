//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  // TC -> O(N) SC -> O(N)
    void markParents(Node* root, unordered_map<Node*,Node*>& mp ){
        // BFS TRAVERSAL
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                Node* node = q.front();
                q.pop();
               
                if (node->left!=NULL){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if (node->right!=NULL){
                    q.push(node->right);
                    mp[node->right] = node;
                }
            }
        }
        
        return ;
        
    }
    // TC -> O(N) SC -> O(N)
    Node* srch(Node* root ,int key){
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL && root->data != key) return NULL;
        
        if (root->data == key){
            return root;
        }
        
        Node* lt = srch(root->left,key); 
        Node* rt = srch(root->right,key); 
        
        if (lt!=NULL) return lt;
        
        return rt;
        
        // if (lt == NULL) return rt;
        // if (rt == NULL) return lt;
        
        
        
    }
    
    int minTime(Node* root, int key) {
        // Your code goes here
        if (root == NULL) return 0;
        
        Node* target = srch(root,key);
        
        // NODE->PARENT
        unordered_map<Node*,Node*> parentTrack;
        markParents(root,parentTrack);
        
        // TAKING A VISITED MAP TO KEEP A TRACK OF ALL THE NODES WHICH HAVE BEEN VISITED
        unordered_map<Node*,bool> vis;
        // AGAIN DOING A LEVEL ORDER TRAVERSAL FROM THE TARGET NODE
        queue<Node*> q;
        q.push(target);
        
        vis[target] = true; // MARK THE TARGET NODE AS VISITED
        
        int curr_level = 0;
        // TC -> O(N) SC -> O(N)
        while (!q.empty()){
            
            int size = q.size();
            for (int i=0; i<size; i++){
                Node* node = q.front();
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
        
        // TOTAL TIME COMPLEXITY : O(3N) , TOTAL SPACE COMPLEXITY: O(N)-PARENT TRACK + O(N)-VISITED MAP + O(2N) 2 BFS + O(N) SEARCHING   
                
        return (curr_level-1);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends