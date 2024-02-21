class Solution {
public:
    int countMatchingSubarrays(vector<int>& arr, vector<int>& pattern) {
        int cnt = 0;
        for (int i=0; i<arr.size(); i++){
            int k = 0, j = i+1;
            while(j<arr.size() && k < pattern.size()){
                if (pattern[k] == 1){
                    if (arr[j] > arr[j-1]){
                        j++;
                    }
                    else break;
                }
                else if (pattern[k] == -1){
                    if (arr[j] < arr[j-1]){
                        j++;
                    }
                    else break;
                }
                else{
                    if (arr[j] == arr[j-1]){
                        j++;
                    }
                    else break;
                }
                k++;
            }
            if (k >= pattern.size()){
                cnt++;
            }
        }
        return cnt;
    }
};