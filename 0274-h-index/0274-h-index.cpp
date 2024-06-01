class Solution {
public:
    bool check(vector<int>& citations, int h){
        int cnt = 0;
        for (auto it : citations){
            if (it >= h) cnt++;
        }
        if (cnt >= h) return true;
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size(), low = 0, high = n;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (check(citations, mid)) low = mid + 1;
            else high = mid - 1;
        } 
        return high;
    }
};