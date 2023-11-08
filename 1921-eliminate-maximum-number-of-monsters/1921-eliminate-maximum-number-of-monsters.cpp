class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> timer(n);
        for (int i=0; i<n; i++){
            timer[i] = ceil((double)(dist[i])/(double)(speed[i]));
        }
        sort(timer.begin(), timer.end());
        
        int cnt = 0, tym = 0;

        for(auto t : timer){
            int cur = t - tym;
        
            if (cur<=0) break;
        
            else{
                cnt++;
                tym++;
            }
        } 

        return cnt;
    }
};