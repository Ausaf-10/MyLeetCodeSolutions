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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1 = head, *cur = head->next;
        int s = 0;
        while (cur!=NULL){
            int value = cur->val;
            if (value != 0){
                s+=cur->val;
            }
            else{
                cur->val = s;
                s = 0;
                head->next = cur;
                head = cur;
            }
            cur = cur->next;

        }
        return head1->next; 
    }
};