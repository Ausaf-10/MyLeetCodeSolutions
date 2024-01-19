class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> l2r(n,1), r2l(n,1);
        
        vector<int> count(n,1);

        for (int i=1; i<n; i++){
            if (arr[i] > arr[i-1]){
                count[i] = count[i-1]+1;
            }
        }
        
        for (int i=n-2; i>=0; i--){
            if (arr[i] > arr[i+1]){
                count[i] = max(count[i], count[i+1]+1);
            }
        }
        
        int cnt = 0;
        
        for (int i=0; i<n; i++){
            cnt+=count[i];
        }
        
        return cnt;
    }
};