//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str){
        map<char,int> mp;
        
        for (int i=0; i<str.size(); i++){
            char ch = str[i];
            if (ch!=' ') mp[ch]++;
        }
        
        int maxi = -1e9;
        char ans ;
       
        for (auto it : mp){
            if (it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }
        
        return ans;
    }
    

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends