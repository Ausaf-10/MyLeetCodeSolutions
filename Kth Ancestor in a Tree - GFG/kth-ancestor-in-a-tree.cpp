//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* findNode(Node* root, int k){
    if (root == NULL || root->data == k) return root;
    Node* lt = findNode(root->left, k);
    if (lt != NULL) return  lt;
    Node* rt = findNode(root->right, k);
    if (rt!=NULL) return rt;
    
    return NULL;
}
bool rootNodePath(Node* root, int k, Node* node, vector<int>& ds){
    if (root == NULL) return false;
    ds.push_back(root->data);
    if (root->data == node->data) return true;
    
    bool lt = rootNodePath(root->left, k, node, ds);
    bool rt = rootNodePath(root->right, k, node, ds);
    
    if (lt == false && rt == false){
        ds.pop_back();
        return false;
    }
    
    return true;

}
int kthAncestor(Node *root, int k, int givenNode){
    // Code here
    vector<int> ds;
    Node* node = findNode(root,givenNode);
    bool x = rootNodePath(root, k, node, ds);
    
    // reverse(ds.begin(), ds.end());
    
    int n = ds.size();
    
    if (n-k-1 >= 0) return ds[n-k-1];
    
    return -1;
}
