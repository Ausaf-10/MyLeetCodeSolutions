using ll = long long int;
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ll t = 0, n = customers.size();
        ll waiting = 0;
        for (auto it : customers){
            int arrival = it[0], prepareFood = it[1];
            if (t < arrival){
                t = arrival;
            }
            t = t + prepareFood;
            waiting += (t-arrival);
        }
        return (double)waiting/n;
    }
};