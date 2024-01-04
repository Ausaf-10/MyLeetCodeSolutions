class Solution {
public:
    int minOperations(vector<int>& arr) {
        unordered_map<int,int> mp;
        for (auto it : arr){
            mp[it]++;
        }


        int cnt = 0;
        for (auto it : mp){
            int freq = it.second, ele = it.first;
            if (freq == 1) return -1;
            cnt = cnt + ceil(double(freq)/3);
            
        }

        return cnt;
    }
};