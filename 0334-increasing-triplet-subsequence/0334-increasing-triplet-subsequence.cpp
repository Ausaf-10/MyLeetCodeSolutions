class Solution {
public:
    int n;
    int binarySearch(vector<int>& arr){
        int maxi = 1;
        vector<int> temp;
        temp.push_back(arr[0]);
        for (int i=1; i<n; i++){
            int lb = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            if (lb == temp.size()){
                temp.push_back(arr[i]);
            }
            else temp[lb] = arr[i];
            maxi = max(maxi, (int)temp.size());
        }
        return maxi;
    }
    bool increasingTriplet(vector<int>& arr) {
        n = arr.size();
        return binarySearch(arr) >= 3 ? true : false;
    }
};