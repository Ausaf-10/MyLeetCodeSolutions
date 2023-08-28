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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL, *cur = head, *after = head->next;
        while (after!=NULL){
            cur->next = prev;
            prev=cur, cur = after, after = after->next;
        }
        cur->next = prev;
        return cur;
    }
    ListNode* doubleIt(ListNode* head) {
        if (head == NULL) return head;
        ListNode* rhead = reverse(head);
        ListNode* var = rhead;
        ListNode* dummy = rhead;
        ListNode* temp = dummy;

        int carry = 0;
        while (var!=NULL || carry!=0){
            int sum = 0;
            if (var!=NULL){
                sum+=2*var->val;
                var=var->next;
            }
            sum+=carry;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
            carry = sum/10;
        }

        return reverse(dummy->next);

    }
};