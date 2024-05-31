using ll = long long int;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<ll> pq;
        for (auto it : happiness) pq.push(it);
        ll selectedTillNow = 0, sum = 0;
        while (selectedTillNow!=k){
            ll value = pq.top()-selectedTillNow;
            if (value >= 0) sum += value;
            pq.pop();
            selectedTillNow++;
        }
        return sum;
    }
};