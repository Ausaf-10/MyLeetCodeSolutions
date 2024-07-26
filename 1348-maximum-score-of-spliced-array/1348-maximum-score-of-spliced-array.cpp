class Solution {
public:
    int n,s1,s2;
    int kadane(vector<int>& arr){
        int curSum = 0, maxi = 0, ansStart = -1, ansEnd = -1, start;
        for (int i=0; i<n; i++){
            if (curSum == 0) start = i;
            curSum+=arr[i];
            if (curSum > maxi){
                maxi = curSum;
                ansStart = start, ansEnd = i;
            }
            if (curSum < 0) curSum = 0;
        }
        return maxi;
    }
    int fun(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3){
        s1 = accumulate(arr1.begin(), arr1.end(), 0);
        s2 = accumulate(arr2.begin(), arr2.end(), 0);
        for (int i=0; i<n; i++){
            arr3[i] = arr1[i] - arr2[i];
        }
        return s2 + kadane(arr3);
    }

    int maximumsSplicedArray(vector<int>& arr1, vector<int>& arr2) {
        n = arr1.size();
        vector<int> arr3(n);
        int max1 = fun(arr1, arr2, arr3), max2 = fun(arr2, arr1, arr3);
        return max(max1, max2);
    }
};