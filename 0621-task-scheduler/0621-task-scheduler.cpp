class Solution {
public:
    int leastInterval(vector<char>& tasks, int coolDownPeriod) {
        unordered_map<char,int> mp;
        for (auto &it : tasks) mp[it]++;
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        for (auto it : mp){
            pq.push(it.second);
        }
        int t = 0;
        while (!pq.empty() || !q.empty()){
            while (!q.empty() && t>=q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            t++;
            if (!pq.empty()){
                int freq = pq.top()-1; pq.pop();
                if (freq!=0) q.push({freq,t+coolDownPeriod});
            }
        }
        return t;
    }
};