//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool compare(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
        if (a.second.second == b.second.second) return a.second.second < b.second.second;
        return a.second.first < b.second.first;
    }
    // WE WILL BE ABLE TO CONDUCT MAX MEETING IF WE CONDUCT THE MEETINGS JINKA END TIME SABSE KAM HAI TOH SABSE PEHLE JALDI WAALON KO NIPTADO!
    int maxMeetings(int start[], int end[], int n){
        
        vector<pair<int,pair<int,int>>> vec;
        //  START:{END,POSITION}
        for (int i=0; i<n; i++){
            vec.push_back({start[i],{end[i],i+1}});                     // TC: O(N)
        }
        
        // SORTED ACCORDING TO THE FINISHING TIME
        sort(vec.begin(),vec.end(),compare);                            // TC: O(NlogN)
    
        int endTime = 0;
        int cnt = 0;
        for (int i=0; i<n; i++){                                        // TC: O(N)
            int startTime = vec[i].first;
            if (startTime > endTime){
                cnt++;
                endTime = vec[i].second.first;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends