class Solution {
public:
    int longestSubarray(vector<int>& arr, int limit) {
        int n = arr.size(), i = 0, j = 0, maxi = 1;
        deque<int> maxq, minq;
        while (j<n){
            while (!maxq.empty() && arr[j] > maxq.back()) maxq.pop_back();
            while (!minq.empty() && arr[j] < minq.back()) minq.pop_back();
            maxq.push_back(arr[j]); minq.push_back(arr[j]);  
            
            while (abs(maxq.front()-minq.front()) > limit && i<=j){
                if (arr[i] == maxq.front()) maxq.pop_front();
                if (arr[i] == minq.front()) minq.pop_front();
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};