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
    ListNode* getFirst(ListNode* head, int a){
        int cnt = 0;
        while (head!=NULL && cnt!=a){
            head = head->next;
            cnt++;
        }
        return head;
    }
    ListNode* getLast(ListNode* head){
        while (head!=NULL && head->next != NULL){
            head = head->next;
        }
        return head;
    }
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* first = getFirst(list1, a-1);
        ListNode* second = getFirst(list1, b+1);
        ListNode* tail = getLast(list2);

        first->next = list2;
        tail->next = second;
        return list1;
    }
};