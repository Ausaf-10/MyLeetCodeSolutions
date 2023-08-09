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
       
        ListNode *e = head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next  = head;
        ListNode* beforeStart = dummy;
        
        int i=0;
        while (e!=NULL){
            i++;
            if (i%k==0){
                ListNode* s = beforeStart->next, *temp = e->next;
                reverseList(s,e);
                beforeStart->next = e;
                s->next = temp;
                beforeStart = s;
                e=temp;
            }
            else{
                e = e->next;
            }
        }

        return dummy->next;
    }
    ListNode* swapPairs(ListNode* head) {
         if (head == NULL || head->next == NULL ) return head;
        return  reverseKGroup(head,2);
    }
};