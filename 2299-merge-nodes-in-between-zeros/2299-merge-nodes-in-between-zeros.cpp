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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy, *cur = head->next;
        int s = 0;
        while (cur!=NULL){
            int value = cur->val;
            if (value != 0){
                s += value;
            }
            else{
                temp->next = new ListNode(s);
                temp = temp->next;
                s = 0;
                head=cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};