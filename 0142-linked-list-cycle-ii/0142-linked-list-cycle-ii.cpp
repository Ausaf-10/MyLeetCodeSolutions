/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* detectionCycle(ListNode* head){
        if (head == NULL || head->next == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return slow;
        }
        
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = detectionCycle(head);
        if (slow!=NULL){
            ListNode* dummy = head;
            while (dummy!=slow){
                dummy = dummy->next; 
                slow = slow->next; 
            }
            return slow;
        }
        else return NULL;
    }
};