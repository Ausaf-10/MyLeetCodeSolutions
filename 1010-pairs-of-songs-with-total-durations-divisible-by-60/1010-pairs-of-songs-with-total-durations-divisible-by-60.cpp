class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& arr) {
        int cnt = 0, n = arr.size();;
        unordered_map<int,int> mp;
        
        for (auto number : arr){
            mp[number%60]++;
        }
        
        for (auto number : arr){
            int remainder = number%60;
            mp[remainder]--;
            if (mp[remainder] == 0) mp.erase(number);
            int remaining = (60-remainder)%60;
            if (mp.find(remaining) != mp.end()){
                cnt+=mp[remaining];
            }
        }
        
        return cnt;
    }
};