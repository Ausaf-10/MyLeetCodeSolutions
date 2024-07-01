class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0, n = arr.size();
        for (int i=0; i<n-2; i++){
            if (arr[i]&1){
                if (arr[i+1]&1 && arr[i+2]&1) return true;
            }
        }
        return false;
    }
};