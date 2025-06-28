class Solution {
public:
    bool check(vector<int>& arr) {
        int peak = 0, n = arr.size();
        for (int i=0; i<arr.size(); i++){
            if (arr[i] > arr[(i+1)%n]){
                peak++;
            }
        }
        return peak <= 1;
    }
};