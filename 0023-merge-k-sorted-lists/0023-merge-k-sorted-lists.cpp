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
class cmp{
    public:
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val; // a should come before b for minHeap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto it : lists){
            if (it!=NULL) pq.push(it);
        }

        ListNode* dummy = new ListNode (-1);
        ListNode* temp = dummy;

        while (!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            temp->next = top;
            top = top->next;
            if (top!=NULL) pq.push(top);
            temp = temp->next;
        }

        return dummy->next;
    }
};