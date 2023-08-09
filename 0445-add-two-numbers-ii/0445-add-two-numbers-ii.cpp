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
    ListNode* reverseList(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL, *cur = head, *after = head->next;
        while (after!=NULL){
            cur->next = prev;
            prev = cur, cur = after, after = after->next;
        } 
        cur->next = prev;
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* a, ListNode* b) {
        ListNode* l1 =  reverseList(a);
        ListNode* l2 =  reverseList(b);
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;
        while (l1!=NULL || l2!=NULL || carry!=0){
            int sum = 0;
            if (l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            
            ListNode* newNode = new ListNode(sum%10);
            temp->next = newNode;
            temp = temp->next;
            
            carry=sum/10;
        }

        ListNode* res = dummy->next;
        
        return reverseList(res);
    }
};