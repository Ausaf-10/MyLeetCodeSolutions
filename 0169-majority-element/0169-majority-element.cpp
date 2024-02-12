class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int ele = arr[0], cnt = 1;
        for (int i=1; i<n; i++){
            if (cnt == 0){
                ele = arr[i];
                cnt = 1;
            }
            else if (ele == arr[i]){
                cnt++;
            }
            else cnt--;
        }
        return ele;
    }
};