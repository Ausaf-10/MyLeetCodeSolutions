class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> xCoordinates;
        for (int i=0; i<points.size(); i++){
            int x = points[i][0];
            xCoordinates.push_back(x);
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        int maxi = -1e9;
        for (int i=1; i<xCoordinates.size(); i++){
            int diff = xCoordinates[i] - xCoordinates[i-1];
            maxi = max(maxi, diff);
        }
        return maxi;
    }
};