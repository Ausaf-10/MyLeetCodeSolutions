class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), i = 0, j = 0, totSum = 0, curSum = 0, windowSize = n-k, maxi = 0;
        for (auto it : cardPoints) totSum+=it;
        if (k == n) return totSum;
        while (j<n){
            curSum+=cardPoints[j];
            if (j-i+1 < windowSize) j++;
            else{
                maxi = max(maxi, totSum-curSum);
                curSum-=cardPoints[i];
                j++,i++;
            }
        }
        return maxi;
    }
};