class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), i = 0, j = 0;
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        vector<int> ans;
        while (i < n && j < m){
            if (arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                i++;j++;
            }
            else if (arr1[i] < arr2[j]) i++;
            else j++;
        }
        return ans;
    }
};