const int maxSize = 1e4+2;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        map<pair<int,int>, int> mp;
        for (int i=0; i<times.size(); i++){
            mp[{times[i][0],times[i][1]}] = i;
        }
        auto cmp = [&](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        };
        sort(times.begin(), times.end(), cmp);
        vector<int> chairs(maxSize, -1);
        for (int i=0; i<n; i++){
            for (int j=0; j<maxSize; j++){
                if (chairs[j] == -1){
                    chairs[j] = times[i][1];
                    if(mp[{times[i][0], times[i][1]}] == targetFriend) return j;
                    break;
                }
                else if (chairs[j] <= times[i][0]){
                    chairs[j] = times[i][1];
                    if(mp[{times[i][0], times[i][1]}] == targetFriend) return j;
                    break;
                }
            }
        }
        return 0;
    }
};