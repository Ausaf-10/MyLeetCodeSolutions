class Solution {
public:
    int longestSubarray(vector<int>& arr, int limit) {
        multiset<int> st;
        int n = arr.size(), i = 0, j = 0, maxi = 1;
        while (j<n){
            st.insert(arr[j]);
            while (abs(*st.begin() - *st.rbegin()) > limit && i<=j){
                if (st.find(arr[i]) != st.end()) {
                    st.erase(st.find(arr[i]));
                }
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};