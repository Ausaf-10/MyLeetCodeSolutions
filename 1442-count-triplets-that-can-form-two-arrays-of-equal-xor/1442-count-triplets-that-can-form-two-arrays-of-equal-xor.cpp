class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int xr1=0;
                for (int a = i; a<j; a++){
                    xr1^=arr[a];
                }
                int xr2=0;
                for (int k=j; k<n; k++){
                    xr2^=arr[k];
                    if (xr1 == xr2) cnt++;
                }
            }
        }
        return cnt;
    }
};