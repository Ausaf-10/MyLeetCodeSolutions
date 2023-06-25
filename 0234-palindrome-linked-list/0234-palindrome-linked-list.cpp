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

    ListNode* getMiddle(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head , *fast = head, *prev = NULL;
        while (fast!=NULL && fast->next!=NULL){
            prev = slow, slow=slow->next , fast=fast->next->next;
        }
        if (fast == NULL ) return prev;
        else return slow;
    }

    ListNode* reverseList(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
       ListNode* shead = reverseList(head->next);
       ListNode* temp = head->next;
       temp->next = head;
       head->next = NULL;
       return shead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* mid = getMiddle(head);
        ListNode* rightHead = reverseList(mid->next);
        ListNode* temp = head;

        while (rightHead!=NULL){
            if (temp->val != rightHead->val) return false;
            temp = temp->next , rightHead =  rightHead->next;
        }

        return true;
    }
};