class Solution {
public:
    int leastInterval(vector<char>& arr, int coolDownPeriod) {
        int n = arr.size();
        if (coolDownPeriod == 0) return n;
        priority_queue<int> maxHeap;
        deque<pair<int,int>> q;
        unordered_map<char, int> mp;
        for (char ch : arr) mp[ch]++;
        for (auto it : mp){
            maxHeap.push(it.second);
        }

        int time = 0;
        
        while (!maxHeap.empty() || !q.empty()){
            while (!q.empty() && time >= q.front().second){
                maxHeap.push(q.front().first);
                q.pop_front();
            }
            time++;
            if (!maxHeap.empty()){
                int freq = maxHeap.top()-1; maxHeap.pop();
                if (freq != 0) q.push_back({freq, time+coolDownPeriod});
            }
        }

        return time;
        
    }
};