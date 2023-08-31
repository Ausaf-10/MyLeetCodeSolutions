//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        // code here 
        int row = M.size();
        int col = M[0].size();
        int x = -1;
        for (int i=0; i<row; i++){
            int flagRow = 1, flagCol = 1; // CONSIDERING THE CELEBRITY
            // CHECK ITS ROWS -> ALL BE 0's
            for (int j=0; j<col; j++){
                if (M[i][j]!=0 && i!=j){
                    flagRow = 0;
                    break;
                }
            }
            
            if (flagRow == 0) continue;
            
            //CHECK ITS COL -> ALL 1'S
            for (int j=0; j<row; j++){
                // if (i == j) continue;
                if (i!=j && M[j][i]!=1){
                    flagCol = 0;
                    break;
                }
            }
            
            if (flagRow == 0 || flagCol == 0) return -1;
            
            if (flagRow == 1 && flagCol == 1) x = i;
        }
        
        return x;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends