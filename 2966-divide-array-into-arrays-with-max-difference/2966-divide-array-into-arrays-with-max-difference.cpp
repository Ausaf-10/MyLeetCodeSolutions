class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (auto it : arr) cout << it << " ";
        int i=0,j=1;
        vector<vector<int>> ans;
        vector<int> temp;
        while (i < n){
            if (temp.empty() || !temp.empty() && arr[i]-temp[0] <= k){
                temp.push_back(arr[i]);
                
            }
            else return {};
            if (temp.size() == 3){
                ans.push_back(temp);
                
                temp.clear();
                temp.resize(0);
            }
            i++;
        }

        return ans;
    }
};