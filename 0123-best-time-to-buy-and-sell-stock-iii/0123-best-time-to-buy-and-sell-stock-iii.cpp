class Solution {
public:
    int n;
    int recursion(int indx, bool buy, int cnt, vector<int>& arr){
        if (indx == n || cnt == 0) return 0;
        if (buy){
            int buying = -arr[indx] + recursion(indx+1, !buy, cnt, arr);
            int notBuying = 0 + recursion(indx+1, buy, cnt, arr);
            return max(buying, notBuying);
        }
        else{
            int sell = arr[indx] + recursion(indx+1, !buy, cnt-1, arr);
            int notSell = 0 + recursion(indx+1, buy, cnt, arr);
            return max(sell, notSell);
        }
    }
    int tabulation(vector<int>& arr){
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2,vector<int>(3,0)));
        for (int indx=n-1; indx>=0; indx--){
            for (int buy=0; buy<=1; buy++){
                for (int cnt=1; cnt<3; cnt++){
                    if (buy){
                        int buying = -arr[indx] + dp[indx+1][!buy][cnt];
                        int notBuying = 0 + dp[indx+1][buy][cnt];
                        dp[indx][buy][cnt] = max(buying, notBuying);
                    }
                    else{
                        int sell = arr[indx] + dp[indx+1][!buy][cnt-1];
                        int notSell = 0 + dp[indx+1][buy][cnt];
                        dp[indx][buy][cnt] = max(sell, notSell);
                    }
                }
                
            }
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& arr) {
        n = arr.size();
        return tabulation(arr);
    }
};