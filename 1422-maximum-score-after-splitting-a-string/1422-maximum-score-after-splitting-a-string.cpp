class Solution {
public:
    int maxScore(string s) {
        int l0 = 0, l1 = 0, r1 = 0, r0 = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '1') r1++;
            else r0++;
        }
        int maxi = -1e9;
        for (int i=0; i<s.size()-1; i++){
            if (s[i] == '0'){
                l0+=1;
            }
            else{
                r1-=1;
            }
            // if (s[i] == '0')
            // else 
            cout << l0+r1 << endl;
            maxi = max(maxi, l0+r1); 
            
        }
        return maxi;
    }
};