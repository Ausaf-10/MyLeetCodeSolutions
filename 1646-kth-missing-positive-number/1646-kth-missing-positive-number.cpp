class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1, i = 0, n = arr.size();
        while (i < n && k > 0){
            if (arr[i] == num){
                i++;
            }
            else{
                k--;
            }
            num++;
        }
        while (k > 0){
            num++;
            k--;
        }
        return num-1;
    }
};