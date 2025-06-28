class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size(), cnt = 0, ele = -1;
        for (int i=0; i<n; i++){
            if (cnt == 0){
                ele = arr[i];
                cnt++;
            }
            else if (ele == arr[i]){
                cnt++;
            }
            else if (ele != arr[i]) {
                cnt--;
            }
        }
        return ele;
    }
};