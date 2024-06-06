class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int groupSize) {
        int n = arr.size();
        map<int,int> mp;
        for (auto it : arr) mp[it]++;
        int size = 0;
        while (mp.size()!=0){
            vector<int> vec;
            for (auto it : mp){
                int number = it.first; mp[number]--;
                if (mp[number] == 0) mp.erase(number);
                if (vec.empty() || (!vec.empty() && vec.back() + 1 == number)){
                    vec.push_back(number);
                }
                else return false;
                if (vec.size() == groupSize) break;
            }
            size = vec.size();
        }
        if (size != groupSize) return false;
        return true;
    }
};