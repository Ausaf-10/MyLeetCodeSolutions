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
	    
	    int i=0,j=0, cnt = 0;
	    int k = pat.size(), n = str.size();
	    
	    while (j < n){
	        char ch = str[j];
	        if (mp.find(ch) != mp.end()){
	            mp[ch]--;
	        }
	        if (j-i+1 < k) j++;
	        else if (j-i+1 == k){
	            bool allZero = true;
	            for (auto it : mp){
	                if (it.second!=0){
	                    allZero = false;
	                }
	            }
	            if (allZero) cnt++;
	            if (mp.find(str[i]) != mp.end()) mp[str[i]]++;
	            i++,j++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends