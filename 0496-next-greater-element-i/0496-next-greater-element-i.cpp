class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        vector<int> ans(nums1.size(),-1);
        unordered_map<int,int> mp;
        
        // INSERT THE COMMON ELEMENTS ALONG WITH THEIR INDICES INTO MAP
        for (int i=0; i<nums1.size(); i++) mp[nums1[i]] = i;

        // NOW USE STACK AND PUT THE NGE INTO ANS
        for (int i=nums2.size()-1; i>=0; i--){
            int element = nums2[i];
            while (!stk.empty() && element >= stk.top()) stk.pop();
            if (stk.empty()){
                if (mp.find(element) != mp.end()) ans[mp[element]] = -1;
            }
            else{
                if (mp.find(element) != mp.end()) ans[mp[element]] = stk.top();
            }
            stk.push(element);
        }
        
        return ans;
    }
};