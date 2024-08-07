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
        if (head == NULL || head->next == NULL) return head;
        ListNode* t1 = head;
        while (t1!=NULL && t1->next!=NULL){
            ListNode* t2 = t1->next;
            while (t2!=NULL && t1->val == t2->val) t2 = t2->next;
            t1->next = t2;
            t1 = t2;
        }
        return head;
    }
};