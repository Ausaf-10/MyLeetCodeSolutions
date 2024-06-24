class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        for (int i=0; i<n; i++){
            if (arr[i]){
                if (cnt&1) cnt++;
            }
            else{
                if (!(cnt&1)) cnt++;
            }
        }
        return cnt;
    }
};