class Solution {
public:
    int atMost(vector<int>& arr, int k){
        if (k < 0) return 0;
        int i=0,j=0,s=0,n=arr.size(),cnt = 0;
        while (j < n){
            s+=arr[j];
            while (s > k && i<=j){
                s-=arr[i];
                i++;
            }
            if (s <= k ){
                cnt += j-i+1;
            }
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& arr, int k) {
        return atMost(arr,k) - atMost(arr,k-1);
    }
};