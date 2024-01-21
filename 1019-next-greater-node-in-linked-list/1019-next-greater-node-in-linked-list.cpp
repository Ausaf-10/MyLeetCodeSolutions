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
    vector<int> nextLargerNodes(ListNode* head) {
        if (head->next == NULL) return {0};
        vector<int> arr; stack<int> stk;
        while (head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        int n = arr.size();
        for (int i=n-1; i>=0; i--){
            while (!stk.empty() && stk.top() <= arr[i]) stk.pop();
            int original = arr[i];
            if (stk.empty()) arr[i] = 0;
            else arr[i] = stk.top();
            stk.push(original);
        }
        
        return arr;
    }
};