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
    bool operator()(ListNode* a, ListNode* b){
        return (a->val > b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // THIS COMPARATOR MAKE SURES THAT b IS INSERTED FIRST THEN a 
        priority_queue<ListNode*,vector<ListNode*>,cmp> minHeap;


        // ITEARTING THE HEAD OF EACH AND EVERY LINKED LIST
        for (auto it:lists){
            if (it!=NULL) minHeap.push(it);
        }

        ListNode* temp = new ListNode(-1);
        ListNode* dummy = temp;

        while (!minHeap.empty()){
            ListNode* var = minHeap.top();
            temp->next = var;
            temp = temp->next;
            minHeap.pop();
            if (var->next!=NULL) minHeap.push(var->next);
        }

        return dummy->next;
    }
};