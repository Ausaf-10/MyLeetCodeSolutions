class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n,-1);
        
        for (int i=2*n-1; i>=0; i--){
            int element = nums[i%n]; 
            while (!stk.empty() && stk.top() <= element) stk.pop(); 
            if (!stk.empty()) ans[i%n] = stk.top();
            stk.push(element);
        }
        
        
        return ans;
    }
};