using ll = long long int;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        int n = arr.size();
        long long m = mass;
        sort(arr.begin(), arr.end());
        for (int i=0; i<n; i++){
            if (arr[i] <= m){
                m = (long long)m + arr[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};