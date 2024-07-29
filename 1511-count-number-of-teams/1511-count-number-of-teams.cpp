class Solution {
public:
    int n;
    int dp1[1001][1001][4];
    int dp2[1001][1001][4];
    int LIS(int indx, int prevIndx, int cnt, vector<int>& arr){
        if (cnt == 3 || indx == n) return cnt == 3 ? 1 : 0;
        if (dp1[indx][prevIndx+1][cnt] != -1) return dp1[indx][prevIndx+1][cnt];
        int pick = 0;
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            pick = LIS(indx+1, indx, cnt+1, arr);
        }
        int notPick = LIS(indx+1, prevIndx, cnt, arr);
        return dp1[indx][prevIndx+1][cnt] = pick + notPick;
    }
    int LDS(int indx, int prevIndx, int cnt, vector<int>& arr){
        if (cnt == 3 || indx == n) return cnt == 3 ? 1 : 0;
        if (dp2[indx][prevIndx+1][cnt] != -1) return dp2[indx][prevIndx+1][cnt];
        int pick = 0;
        if (prevIndx == -1 || arr[indx] < arr[prevIndx]){
            pick = LDS(indx+1, indx, cnt+1, arr);
        }
        int notPick = LDS(indx+1, prevIndx, cnt, arr);
        return dp2[indx][prevIndx+1][cnt] = pick + notPick;
    }
    int numTeams(vector<int>& arr) {
        n = arr.size();
        // vector<vector<vector<int>>> dp1(n+1, vector<vector<int>>(n, vector<int>(4, -1)));
        // vector<vector<vector<int>>> dp2(n+1, vector<vector<int>>(n, vector<int>(4, -1)));
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        int one = LIS(0, -1, 0, arr), two = LDS(0, -1, 0, arr);
        return one + two;
    }
};