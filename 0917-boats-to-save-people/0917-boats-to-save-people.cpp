class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), s = 0, cnt = 0, i = 0, j = n-1;
        sort(people.begin(), people.end());
        while (i < j){
            int s = people[i] + people[j];
            if (s <= limit){
                i++,j--;
            }
            else{
                j--;
            }
            cnt++;
        }
        if (i == j) cnt++;
        return cnt;
    }
};