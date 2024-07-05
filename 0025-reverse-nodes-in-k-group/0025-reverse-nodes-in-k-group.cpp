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
    void reverse(ListNode* s, ListNode*e){
        ListNode *prev = NULL , *curr = s, *after = s->next;
        while (curr!=e){
            curr->next = prev;
            prev = curr, curr = after , after = after->next;
        }
        curr->next = prev;
        return ;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) return head;
        ListNode *s = head, *e = head;
        int cnt = 1;
        while (cnt < k){
            e = e->next;
            if (e == NULL) return head;
            cnt++;
        }
        ListNode* newHead = e->next;
        reverse(s,e);
        ListNode *nextHead = reverseKGroup(newHead, k);
        s->next = nextHead;
        return e;
    }
};