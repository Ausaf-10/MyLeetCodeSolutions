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
    ListNode* recursion(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* shead = recursion(head->next);
        ListNode* temp = head->next;
        temp->next = head;
        head->next = NULL;
        return shead;
    }
    ListNode* iterative(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = NULL, *curr = head, *after = head->next;
        while (after!=NULL){
            curr->next = prev;
            prev = curr, curr = after, after = after->next;
        }
        curr->next = prev;
        return curr;
    }
    ListNode* reverseList(ListNode* head) {
        return iterative(head);
    }
};