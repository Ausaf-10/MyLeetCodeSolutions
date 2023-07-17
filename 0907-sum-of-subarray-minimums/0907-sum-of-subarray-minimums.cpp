class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long n = arr.size();
        stack<pair<int,int>> s1,s2;
        vector<int> prevSmaller(n),nextSmaller(n);

        // nextSmaller and prevSmaller are storing g1 and g2

        // CALCULATING prevSMALLER OF EVERY ELEMENT
        for (int i=0; i<n; i++){
            int cnt = 1;
            while (!s1.empty() && s1.top().first > arr[i]){
                cnt+=s1.top().second;
                s1.pop();
            }
            s1.push({arr[i],cnt});
            prevSmaller[i] = cnt;
        } 

        //CALCULATING THE NUMBER OF NEXSTMALLER 
        for (int i=n-1; i>=0; i--){
            int cnt = 1;
            while (!s2.empty() && s2.top().first >= arr[i]){
                cnt+= s2.top().second;
                s2.pop();
            }
            s2.push({arr[i],cnt});
            nextSmaller[i] = cnt;
        } 
        long long res = 0;
        long mod = 1e9+7;
        for (int i=0; i<n; i++){
            // res=(res+(long long)arr[i]*nextSmaller[i]*prevSmaller[i])%mod;
            res = (res + arr[i]*1LL*nextSmaller[i]*prevSmaller[i])%mod; 
        }
        return res;

    }
};