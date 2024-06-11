class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> mp;
        for (auto it : arr) mp[it]++;
        for (auto& it : mp){
            int ele = it.first, freq = it.second;
            if (freq > 0){
                for (int x=0; x<k; x++){
                    if (mp[x+ele] >= freq){
                        mp[x+ele]-=freq;
                    }
                    else return false;
                }
            }
            
        }
        return true;
    }
};