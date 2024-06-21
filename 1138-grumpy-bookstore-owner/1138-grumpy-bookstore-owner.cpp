class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int n = customers.size(), i = 0, j = 0, startIndx = -1, endIndx = -1, maxi = -1, s = 0, ans = 0;
        int total = accumulate(customers.begin(), customers.end(), 0);
        while (j<n){
            if (grumpy[j]) s+=customers[j];
            if (j-i+1 < k) j++;
            else{
                if (s > maxi){
                    maxi = s;
                    startIndx = i;
                    endIndx =  j;
                }
                if (grumpy[i]) s-=customers[i];
                j++,i++;
            }
        }
        if (maxi == -1) return total;
        cout << maxi;
        for (int i=0; i<n; i++){
            if (i>=startIndx && i<=endIndx && grumpy[i]) continue;
            if (!grumpy[i]) ans+=customers[i];
        }
        return ans+maxi;
    }
};