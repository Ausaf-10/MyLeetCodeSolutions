//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool canPlace(vector<int>& arr, int dist, int cows){
        int cntCows = 1, last = arr[0];
        for (int i=1; i<arr.size(); i++){
            if (arr[i] - last >= dist){
                cntCows++ , last = arr[i];
            }
        }
        if (cntCows >= cows) return true;
        return false;
    }

    int solve(int n, int cows, vector<int> &arr) {
    
        int low = 1;
        sort(arr.begin(), arr.end());
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(), arr.end());
        
        int high = maxi - mini;
        int ans = -1;
       
        while (low <= high){
            int mid = low + (high-low)/2;
            if (canPlace(arr,mid,cows)){
                low = mid + 1;
                ans = max(ans,mid);
            }
            else high = mid - 1;
            
        }
        
        return ans;
        

        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends