class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        vector<int> ans;
        for (int i=0; i<arr.size(); i++){
            int indx = abs(arr[i])-1;
            if (arr[indx] > 0) arr[indx]*=-1;
            else ans.push_back(abs(arr[i]));
        }
        for (int i=0; i<arr.size(); i++){
            if (arr[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};