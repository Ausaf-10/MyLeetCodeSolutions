using ll = long long int;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll n = happiness.size(), selectedTillNow = 0, sum = 0, i = n-1;
        sort(happiness.begin(), happiness.end());
        while (selectedTillNow!=k){
            ll value = happiness[i--]-selectedTillNow;
            if (value>=0) sum += value;
            selectedTillNow++;
        }
        return sum;
    }
};