class Solution {
public:
    void reverseList(ListNode* s, ListNode* e){
        if (s == NULL || s->next == NULL) return ;
        ListNode *prev = NULL , *curr = s, *after = s->next;
        while (curr!=e){
            curr->next = prev;
            prev = curr, curr = after , after = after->next;  
        } 
        curr->next = prev;
        return ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k==1) return head;
        ListNode* s = head, *e = head;
        int inc = k-1;
        while (inc--){
            e = e->next;
            if (!e) return s;
        }
        ListNode* afterHead = e->next;
        reverseList(s, e);
        ListNode* node = reverseKGroup(afterHead, k);
        s->next = node;
        return e;
    }
};