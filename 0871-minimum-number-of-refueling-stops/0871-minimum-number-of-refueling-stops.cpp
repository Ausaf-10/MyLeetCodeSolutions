class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        if (stations.size() == 0 && startFuel < target) return -1;
        if (startFuel < stations[0][0]) return -1;

        int cur = startFuel, cnt = 0, i = 0;
        priority_queue<int> pq;
        while (cur < target){
            while (i < stations.size() && stations[i][0] <= cur){
                pq.push(stations[i++][1]);
            }
            if (pq.empty()) return -1;
            cur+=pq.top(); pq.pop();
            cnt++;
        }
        return cnt;
    }
};