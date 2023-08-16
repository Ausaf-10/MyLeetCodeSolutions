class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        int n = n1 + n2;
        int indx1 = n/2 - 1, indx2 = n/2;
        int ele1 = -1 , ele2 = -1;
        int cnt = 0;

        int i=0, j=0;
        while (i < n1 && j < n2){
            if (arr1[i] <= arr2[j]){
                if (cnt == indx1) ele1 = arr1[i];
                if (cnt == indx2) ele2 = arr1[i];
                i++,cnt++;
            }
            else{
                if (cnt == indx1) ele1 = arr2[j];
                if (cnt == indx2) ele2 = arr2[j];
                j++,cnt++;
            }
        }   

        while (i < n1){
            if (cnt == indx1) ele1 = arr1[i];
            if (cnt == indx2) ele2 = arr1[i];
            i++,cnt++;
        }   

        while (j < n2){
            if (cnt == indx1) ele1 = arr2[j];
            if (cnt == indx2) ele2 = arr2[j];
            j++,cnt++;
        } 

        if (n%2 == 1) return ele2;

        return (ele1+ele2)/(2.0);
    }
};