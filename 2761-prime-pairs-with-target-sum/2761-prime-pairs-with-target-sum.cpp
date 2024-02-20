class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if (n<=3) return {};
        vector<bool> arr(n+1, true);
        for (int i=2; i*i<=n; i++){
            if (arr[i] == true){
                for (int j=i*i; j<=n; j+=i){
                    arr[j] = false;
                }
            }
        }
    
        set<vector<int>> st;
        for (int i=2; i<n; i++){
            if (arr[i]){
                int rem = n - i;
                if (rem!=0 && rem!=1 && arr[rem] == true){
                    vector<int> vec = {i, rem};
                    sort(vec.begin(), vec.end());
                    st.insert(vec);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};