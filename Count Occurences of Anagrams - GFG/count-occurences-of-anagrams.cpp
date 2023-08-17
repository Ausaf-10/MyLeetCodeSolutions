//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string str) {
	    // code here
	    unordered_map<char,int> mp;
	    for (auto it : pat){
	        mp[it]++;
	    }
	    
	    int ans = 0;
	    int cnt = mp.size();
	    
	    int i=0,j=0;
	    int k = pat.size(), n = str.size();
	    
	    while (j < n){
	        char ch = str[j];
	        if (mp.find(ch) != mp.end()){
	            mp[ch]--;
	            if (mp[ch] == 0) cnt--;
	        }
	        if (j-i+1 < k) j++;
	        else if (j-i+1 == k){
	            if (cnt == 0) ans++;
	            if (mp.find(str[i]) != mp.end()){
	                mp[str[i]]++;
	                if (mp[str[i]] == 1) cnt++;
	            }
	            i++,j++;
	        }
	    }
	    
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends