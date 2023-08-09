//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> stk;
        vector<long long> ans(n,-1);
        
        for (int i=n-1; i>=0; i--){
     
            if (!stk.empty() && arr[i] < stk.top()){
                ans[i] = stk.top();
            }
            
            else{
                while (!stk.empty() && arr[i] >= stk.top()){
                    stk.pop();
                }
                if (!stk.empty()){
                    ans[i] = stk.top();
                }
                    
            }
            
            stk.push(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends