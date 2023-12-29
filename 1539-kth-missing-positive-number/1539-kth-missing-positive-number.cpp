class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1, n = arr.size();
        for (int i=0; i<n; i++){
            while (arr[i] != num && k != 0){
                num++;
                k--;
            }
            
            if (k == 0){
                return num-1;
            }
            
            num++;
            
        }
        
        while (k--){
            num++;
        }
        
        return num-1;
        
    }
};