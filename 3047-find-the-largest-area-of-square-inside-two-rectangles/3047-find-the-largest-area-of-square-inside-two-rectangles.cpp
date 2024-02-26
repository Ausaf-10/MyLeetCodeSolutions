using ll = long long int;
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll maxi = 0;
        for (int i=0; i<n-1; i++){
            ll bottomLeftX_Coordinate1 = bottomLeft[i][0], bottomLeftY_Coordinate1 = bottomLeft[i][1]; 
            ll topRightX_Coordinate1 = topRight[i][0], topRightY_Coordinate1 = topRight[i][1]; 
            for (int j=i+1; j<n; j++){
                ll bottomLeftX_Coordinate2 = bottomLeft[j][0], bottomLeftY_Coordinate2 = bottomLeft[j][1]; 
                ll topRightX_Coordinate2 = topRight[j][0], topRightY_Coordinate2 = topRight[j][1]; 

                ll newBottomLeftX_Coordinate = max(bottomLeftX_Coordinate1, bottomLeftX_Coordinate2);
                ll newBottomLeftY_Coordinate = max(bottomLeftY_Coordinate1, bottomLeftY_Coordinate2);

                ll newtopRightX_Coordinate = min(topRightX_Coordinate1, topRightX_Coordinate2);
                ll newtopRightY_Coordinate = min(topRightY_Coordinate1, topRightY_Coordinate2);

                if (newBottomLeftX_Coordinate >= newtopRightX_Coordinate || newBottomLeftY_Coordinate >= newtopRightY_Coordinate) continue;

                ll x_Diff = abs(newtopRightX_Coordinate - newBottomLeftX_Coordinate);
                ll y_Diff = abs(newBottomLeftY_Coordinate - newtopRightY_Coordinate);

                ll oneSide = min(x_Diff, y_Diff);
                ll secondSide = min(x_Diff, y_Diff);

                ll oneSideSqure = pow(oneSide, 2), secondSideSquare = pow(secondSide, 2);
                ll diagonalSquared = oneSideSqure + secondSideSquare;
                ll area = diagonalSquared / 2;

                maxi = max(maxi, area);
            }
        }
        return maxi;
    }

};