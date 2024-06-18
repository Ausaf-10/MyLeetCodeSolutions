class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n = arr.size(), maxi = 0, s = 0, k = 0;
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++){
            if (!arr[i]) s+=-1;
            else s+=1;
            if (s == k) maxi = max(maxi, i+1);
            int rem = s-k;
            if (mp.find(rem) != mp.end()){
                maxi = max(maxi, i-mp[rem]);
            } 
            if (mp.find(rem) == mp.end()){
                mp[rem] = i;
            }
        }
        return maxi;
    }
};