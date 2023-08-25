using ll = long long int;

class Solution {
public:
    // i: 1 -> size , j: size -> 1
   
    long long recursion(int i, int j, vector<int>& cuts){
        if (i > j) return 0; 
        long long mini = LONG_MAX;
        for (int indx = i; indx<=j; indx++){
            long long cost = (cuts[j+1] - cuts[i-1]) + recursion(i,indx-1,cuts) + recursion(indx+1,j,cuts);
            mini = min(mini,cost);
        }
        return mini;
    }

    // TC : O(i*j)*(j-i+1) -> O((size)^3), SC: O(SIZE) + O(SIZE^2)
    ll memoization(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if (i > j) return 0; 
        if (dp[i][j]!=-1) return dp[i][j];

        long long mini = LONG_MAX;
        
        for (int indx = i; indx<=j; indx++){
            long long cost = (cuts[j+1] - cuts[i-1]) + memoization(i,indx-1,cuts,dp) + memoization(indx+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }

    int tabulation(int n, vector<int>& cuts){
        // TC : O(SIZE^3), SC: O(SIZE^2) 
        int size = cuts.size();

        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(size+2,vector<int>(size+2,0));

        for  (int i=size; i>=1; i--){               // ALWAYS THE REVERSE OF RECURSION PARAMETERS!!!
            for (int j=1; j<=size; j++){
                long long mini = LONG_MAX;
                if (i > j) continue;            // BASE CASE!

                for (int indx = i; indx<=j; indx++){        // TRYING OUT ALL THE POSSIBLE CUTS IN THAT PARTITION
                    
                    long long cost = (cuts[j+1] - cuts[i-1]) + dp[i][indx-1] + dp[indx+1][j];
                    mini = min(mini,cost);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][size];
    }

    int minCost(int n, vector<int>& cuts) {
    // THIS IS A PROBLEM OF PARTITION DP WHERE WE CAN MAKE CUT ON ANY INDEX AND EVERYTIME ANS WILL BE ALWAYS DIFFERENT 
   
    // 1. TREAT THE BLOCK OR THE ENITRE ARRAY AS THE PARTITION
    // 2. TRY OUT ALL THE PARTITION -> SO USE A FOR LOOP TO DO THAT
    // 3. RETURN THE MINIMAL OF ALL THE PARTITONS!

    // ** TRICK ** 
    //  ***** ALSO, THE CUTS SHOULD BE SORTED FOR THE PROBLEMS TO BE SOLVED INDEPENDENTLY!!! *****
    // TO CALCULATE THE COST WHERE THE CUT HAS BEEN MADE WE ARE GOING TO ADD THE LENGTH OF THE STICK TO THE RIGHT OF THE CUTS ARRAY AND 0 TO THE
    // LEFT OF THE CUTS ARRAY!
    // THIS IS BCOZ , THE COST = CUTS[j+1] - CUTS[i-1], AND THIS WILL ALWAYS MAKE SURE THIS THING!!!! 
        
        // int size = cuts.size();

        // cuts.push_back(n);
        // cuts.insert(cuts.begin(),0);
        // sort(cuts.begin(), cuts.end());     // to solve the problems independently!

        // vector<vector<int>> dp(size+2,vector<int>(size+2,-1));
        // return memoization(1,size,cuts,dp);

        return tabulation(n,cuts);
    }
};