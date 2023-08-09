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
     ListNode* getKFromBeginning(ListNode* head, int k){
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int cnt = 1;
        while (cnt!=k){
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* getKFromEnd(ListNode* head, int k){
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy, *fast = dummy;

        for (int i=1; i<=k; i++) fast = fast->next;

        while (fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        return slow->next;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if (head == NULL || head->next==NULL) return head;

        ListNode* leftNode =  getKFromBeginning(head,k);  
        ListNode* rightNode =  getKFromEnd(head,k);  
        swap(leftNode->val, rightNode->val);
        return head;
    }
};