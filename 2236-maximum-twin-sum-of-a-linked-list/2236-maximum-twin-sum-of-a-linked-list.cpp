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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        stack<ListNode*> stk;
        while (temp!=NULL){
            stk.push(temp);
            temp = temp->next;
        }
        int n = stk.size();
        int maxi = -1e9;
        temp = head;
        while (n/2!=stk.size()){
            int sum = 0;
            sum = temp->val + stk.top()->val;
            maxi = max(maxi, sum);
            temp = temp->next;
            stk.pop();
        }
        return maxi;
    }
};