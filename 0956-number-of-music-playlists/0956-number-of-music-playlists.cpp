#define mod 1000000007
#define ll long long
class Solution {
public:
    int n,goal;
    ll solve(int songs, int playlists, int k, vector<vector<int>>& dp){
        //base case
        if(playlists == goal) return songs == n;

        if(dp[songs][playlists] != -1) return dp[songs][playlists];

        ll ans = 0;
       
        ans = ((max(0, songs - k))*solve(songs, playlists+1, k, dp)) % mod; // ADDING A EXISTING SONG 
        ans += ((n-songs)*solve(songs+1, playlists+1, k, dp)%mod) % mod; // ADDING A NEW SONG

        ans = ans % mod;
       
        return dp[songs][playlists] = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(100, vector<int>(100,-1));
       
        this-> n = n;
        this->goal = goal;
        
        return solve(0, 0, k, dp);
    }
};