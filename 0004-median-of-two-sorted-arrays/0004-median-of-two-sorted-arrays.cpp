class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int i=0, j=0;
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> temp;
        while (i<n1 && j<n2){
            if (arr1[i] <= arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }
            else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
        while (i<n1){
            temp.push_back(arr1[i]);
            i++;
        }
        while (j<n2){
            temp.push_back(arr2[j]);
            j++;
        }

        int size = temp.size();
        if (size%2 != 0) return temp[size/2];
        
        double a = temp[size/2] , b = temp[size/2 - 1];
        return (a+b)/2.0;
    }
};