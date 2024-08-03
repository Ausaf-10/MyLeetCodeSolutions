class Solution {
public:
    int addRungs(vector<int>& arr, int dist) {
        int n = arr.size(), maxi = dist, cnt = 0;
        for (int i=0; i<n; i++){           
            if (arr[i] <= maxi){
                maxi = max(maxi, arr[i] + dist);
            }
            else{
                cnt = cnt + ceil((arr[i] - maxi)/double(dist));
                maxi = max(maxi, arr[i] + dist);
            }
        }
        return cnt;
    }
};