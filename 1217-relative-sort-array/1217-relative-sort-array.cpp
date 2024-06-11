class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int maxi = *max_element(arr1.begin(), arr1.end());
        vector<int> arr(maxi+1, 0);
        for (int i=0; i<arr1.size(); i++){
            arr[arr1[i]]++;
        }
        vector<int> ans;
        for (int i=0; i<arr2.size(); i++){
            int freq = arr[arr2[i]];
            for (int j=0; j<freq; j++){
                ans.push_back(arr2[i]);
            }
            arr[arr2[i]] = 0;
        }
        for (int i=0; i<maxi+1; i++){
            if (arr[i]!=0){
                int freq = arr[i];
                for (int j=0; j<freq; j++){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};