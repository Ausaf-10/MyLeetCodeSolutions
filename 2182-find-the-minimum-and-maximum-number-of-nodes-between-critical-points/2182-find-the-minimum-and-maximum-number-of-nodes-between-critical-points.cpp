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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next->next) return {-1,-1};
        int first = -1, last = -1, cnt = 2, mini = 1e9;
        ListNode* prev = head, *cur = head->next, *after = cur->next;
        while (after){
            if (cur->val > prev->val && cur->val > after->val){
                if (first == -1){
                    first = last = cnt;
                }
                else{
                    mini = min(mini, cnt - last);
                    last = cnt;
                }
            }
            else if (cur->val < prev->val && cur->val < after->val){
                if (first == -1){
                    first = last = cnt;
                }
                else{
                    mini = min(mini, cnt - last);
                    last = cnt;
                }
            }
            cnt++;
            prev = cur, cur = after, after = after->next;
        }
        if (first == -1 || first == last) return {-1,-1};
        return {mini, last-first};
    }
};