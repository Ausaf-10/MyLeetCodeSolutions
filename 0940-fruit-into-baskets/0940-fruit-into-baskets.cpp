class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int i = 0, j = 0, n = arr.size(), cnt = 0, maxi = 0;
        unordered_map<int, int> mp;
        while (j<n){
            mp[arr[j]]++;
            while (mp.size() > 2 && i<j){
                mp[arr[i]]--;          
                if (mp[arr[i]] == 0) mp.erase(arr[i]);      
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};