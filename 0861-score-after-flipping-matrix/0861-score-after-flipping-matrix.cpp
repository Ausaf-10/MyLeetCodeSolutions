#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n,m;
    int binaryToDecimal(vector<int>& arr){
        int size = arr.size();
        int number = 0;
        for (int i=0; i<size; i++){
            number += pow(2,size-1-i)*arr[i];
        }
        return number;
    }
    int matrixScore(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i=0; i<n; i++){
            if (grid[i][0] == 0){
                for (int j=0; j<m; j++){
                    if (grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        for (int j=0; j<m; j++){
            int cnt0 = 0, cnt1 = 0;
            for (int i=0; i<n; i++){
                if (grid[i][j] == 0) cnt0++;
                else cnt1++;
            }
            if (cnt0 > cnt1){
                for (int i=0; i<n; i++){
                    if (grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }
        int ans = 0;
        for (int i=0; i<n; i++){
            ans += binaryToDecimal(grid[i]);
        }
        return ans;
    }   
  
   
};