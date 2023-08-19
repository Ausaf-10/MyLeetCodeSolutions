/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        Node* temp = root;
        root->next = NULL;

        while (temp->left){
            Node* a = temp;
            while (a!= NULL){
                a->left->next = a->right;
                if (a->next!=NULL){
                    a->right->next = a->next->left;
                }
                else a->right->next = NULL;
                a = a->next;
            }   
            temp = temp->left;
        }
        
        return root;
    }
};