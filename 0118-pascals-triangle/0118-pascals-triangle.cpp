using ll = long long int;
class Solution {
public:
    int nCr(int n, int r){
        int num = 1, deno = 1;
        for (int i=0; i<r; i++){
            num*=(n-i);
            num/=(i+1);
        }
        return num;
    }
    void printRow(int n, vector<int>& arr){
        arr.push_back(1);
        int res = 1;
        for (int i=0; i<n; i++){
            res*=(n-i);
            res/=(i+1);
            arr.push_back(res);
        }
        return ;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;
        mat.push_back({1});
        for (int rows = 2; rows <= numRows; rows++){
            vector<int> rowArray;
            printRow(rows-1,rowArray);
            mat.push_back(rowArray);
        }
        return mat;
    }
};