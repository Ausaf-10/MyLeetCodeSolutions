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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        prev->next = head;
        while (temp!=NULL && temp->next!=NULL){
            if (temp->val == temp->next->val){
                while (temp!=NULL && temp->next!=NULL && temp->val == temp->next->val){
                    temp = temp->next;
                }
                temp = temp->next;
                prev->next = temp;
            }
            
            else prev = temp, temp = temp->next;
        }   
        if (dummy->next == NULL) return NULL;
        return dummy->next;
    }
};