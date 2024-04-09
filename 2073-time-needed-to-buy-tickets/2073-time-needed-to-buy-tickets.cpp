class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        unordered_map<int,int> mp; queue<int> q;
        for (int i=0; i<n; i++){
            q.push(i);
            mp[i] = tickets[i];
        }
        int t = 0;
        while (mp.find(k) != mp.end()){
            int indx = q.front(); q.pop();
            mp[indx]--;
            if (mp[indx]!=0) q.push(indx);
            if (mp[indx] == 0){
                mp.erase(indx);
            }
            t++;
        }
        return t;

    }
};