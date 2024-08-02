class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int i = 0, n = arr.size(), j = 0, cnt = 0, mini = 1e9, k = 0;
        for (auto it : arr){
            if (it == 1) k++;
        }
        if (k == 0) return 0;
        while (j < 2*n){
            if (!arr[j%n]) cnt++;
            if (j-i+1 < k) j++;
            else{
                mini = min(mini, cnt);
                if (!arr[i%n]) cnt--;
                i++,j++;
            }
        }
        return mini;
    }
};