class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0, n = a.size(), m = b.size();
        while  (i < n && j < m) {
            if (a[i] == b[j]){
                if (ans.empty() || !ans.empty() && ans.back() != a[i]){
                    ans.push_back(a[i]);
                }
                i++,j++;
                
            } else if (a[i] > b[j]){
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};