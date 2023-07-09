/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while (fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (fast == NULL) return prev; // IF EVEN NODES
        return slow; // IF ODD NODES
    }

    ListNode* merge(ListNode* left,ListNode* right){
        
        if (left == NULL) return right;
        if (right == NULL) return left;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (left!=NULL && right!=NULL){
            if (left->val <= right->val){
                temp->next = left;
                temp = temp->next;
                left = left->next; 
            }
            else{
                temp->next = right;
                temp = temp->next;
                right = right->next; 
            }
        }

        if (left == NULL){
            temp->next = right;
        }
        if (right == NULL) temp->next = left;

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* mid = getMiddle(head);
        ListNode* r = mid->next;
        
        mid->next = NULL;
        
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(r);
        return merge(left,right); 
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        return mergeSort(head);
    }
};