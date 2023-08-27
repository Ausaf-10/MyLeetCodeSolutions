//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str){
        
        int freq[26]={0};
        
        for (int i=0; i<str.size(); i++){
            char ch = str[i];
            if (ch!=' ') freq[ch-'a']++;
        }
        
        int maxi = -1e9;
        char ans ;
       
        for (int i=0; i<26; i++){
            if (freq[i] > maxi){
                maxi = freq[i];
                ans = i + 'a';
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