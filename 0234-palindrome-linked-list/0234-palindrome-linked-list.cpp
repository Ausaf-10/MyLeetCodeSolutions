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
    ListNode* reverse(ListNode* node){
        if (!node || !node->next) return node;
        ListNode* shead = reverse(node->next);
        ListNode* after = node->next;
        after->next = node, node->next = NULL;
        return shead;
    }
    ListNode* getMiddle(ListNode* node){
        if (!node || !node->next) return node;
        ListNode* dummy = new ListNode(-1);
        dummy->next = node;
        ListNode* slow = dummy, *fast = dummy;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast) return slow;
        return slow->next;        
    }
    void Print(ListNode* node) {
        if (!node) return;
        while (node){
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
        return;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* mid = getMiddle(head);
        ListNode* shead = reverse(mid);
        Print(head);
        Print(shead);
        while (shead){
            if (head->val != shead->val) return false;
            else{
                head = head->next;
                shead = shead->next;
            }
        }
        return true;
    }
};