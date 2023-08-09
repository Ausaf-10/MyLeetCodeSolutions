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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL || head->next==NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy , *fast = dummy;

        for (int i=1; i<=k; i++) fast = fast->next;
        ListNode* first = fast;

        while (fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;

        swap(first->val, second->val);

        return head;
    }
};