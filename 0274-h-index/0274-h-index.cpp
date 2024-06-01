class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size(), low = 0, high = n-1;
        while (low <= high){
            int mid = low + (high-low)/2, h = n-mid;
            if (citations[mid] >= h) high = mid - 1;
            else low = mid +1;
        }        
        return n-low;
    }
};