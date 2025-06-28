class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n = arr.size(), cnt = 0, maxi = 0;
        for (int i=0; i<n; i++){
            if (arr[i] == 0 ){
                cnt = 0;
            } 
            else {
                cnt++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};