class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
       int n = arr1.size(), m = arr2.size();
       if (n>m) return findMedianSortedArrays(arr2, arr1);
        int tot = n+m, left = (tot+1)/2, low = 0, high = n;
        while (low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;
            int l1, l2, r1, r2;
            l1 = l2 = INT_MIN;
            r1 = r2 = INT_MAX;
            if (mid1-1>=0) l1 = arr1[mid1-1];
            if (mid2-1>=0) l2 = arr2[mid2-1];
            if (mid1<n) r1 = arr1[mid1];
            if (mid2<m) r2 = arr2[mid2];
            if (l1 > r2) high = mid1-1;
            else if (l2 > r1) low = mid1 + 1;
            else{
                double leftVal = (double)max(l1,l2), rightVal = (double)min(r1, r2);
                if (tot&1){
                    return leftVal;
                }
                else{
                    return (leftVal + rightVal)/2.0;
                }
            }
        }
        return 1.0;
    }
};