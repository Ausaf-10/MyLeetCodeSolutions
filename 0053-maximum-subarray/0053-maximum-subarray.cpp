class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size(), s = 0, maxi = INT_MIN, start = 0, maxStart = 0, maxEnd = 0;
        for (int i=0; i<n; i++){
            if (s == 0){
                start = i;
            }
            s+=arr[i];
            if (s > maxi){
                maxi = s ;
                maxStart = start, maxEnd = i;
            }
            if (s < 0) s = 0;
        }
        for (int i=maxStart; i<=maxEnd; i++){
            cout << arr[i] << " ";
        }
        return maxi;
    }
};