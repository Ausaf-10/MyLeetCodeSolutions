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
    void reverse(ListNode* s, ListNode* e){
        ListNode* prev = NULL, *curr = s, *after = s->next;
        while (curr!=e){
            curr->next = prev;
            prev = curr, curr = after, after = after->next;
        } 
        curr->next = prev;
        return ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *e = head, *before = dummy;
        int i = 0;
        while (e!=NULL){
            i++;
            if (i%k == 0){
                ListNode *after = e->next, *s = before->next;
                reverse(s, e);
                before->next = e, s->next = after;
                e = after, before = s;
            }
            else{
                e = e->next;
            }
        }
        return dummy->next; 
    }
};