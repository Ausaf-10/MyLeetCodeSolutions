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
    ListNode* getMiddle(ListNode* node){
        if (!node || !node->next) return node;
        ListNode* dummy = new ListNode(-1);
        dummy->next = node;
        ListNode* slow = dummy, *fast = dummy;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (l1!=NULL && l2!=NULL){
            if (l1->val <= l2->val){
                temp->next = l1; 
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if (l1) temp->next = l1;
        if (l2) temp->next = l2;

        return dummy->next;
    }
    ListNode* mergeSort(ListNode* node){
        if (!node || !node->next) return node;
        ListNode* mid = getMiddle(node);
        ListNode* after = mid->next; 
        mid->next = NULL;
        ListNode* left = mergeSort(node);
        ListNode* right = mergeSort(after);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        return mergeSort(head);
    }
};