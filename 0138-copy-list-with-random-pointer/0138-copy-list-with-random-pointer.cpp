/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;

        Node* temp = head;
        // 1. INSERTING THE COPY OF THE NODES IN BETWEEN 
        while (temp!=NULL){
            Node* newNode = new Node(temp->val);
            Node* front = temp->next;
            temp->next = newNode;
            newNode->next = front;
            temp = newNode->next;
        }   
        // 2. ASSIGINING THE RANDOM POINTERS OF THE COPY NODES
        Node* dummy = head->next;
        temp = head;
        while (temp!=NULL && temp->next != NULL){
            if (temp->random == NULL){
                temp->next->random = NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // 3. DELETING THE LINKS BETWEEN ORIGINAL AND THE COPIES
        temp = head;
        
        while (temp!=NULL){
            Node* front = temp->next->next;
            if (front == NULL) temp->next->next = NULL;
            else temp->next->next = front->next;
            temp->next = front;
            temp = front;
        }

        return dummy;
    }
};