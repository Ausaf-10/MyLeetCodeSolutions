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
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while (fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        if (fast == NULL) return prev; // IF EVEN NODES
        return slow; // IF ODD NODES
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        if (l1->val > l2->val) swap(l1,l2); // Making the smaller nodes as l1
        
        ListNode* res = l1;
        

        while (l1!=NULL && l2!=NULL){
            ListNode* temp = NULL;
            while (l1!=NULL && l1->val <= l2->val){
                temp = l1;
                l1= l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }

        return res;
    }

    ListNode* mergeSort(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* mid = getMiddle(head);
        ListNode* r = mid->next;
        
        mid->next = NULL;
        
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(r);
        return merge(left,right); 
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        return mergeSort(head);
    }
};