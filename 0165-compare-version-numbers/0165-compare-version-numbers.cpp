class Solution {
public:
    int n,m;
    int compareVersion(string version1, string version2) {
        int left = 0, right = 0, n = version1.size(), m = version2.size();
        while (left<n && right<m){
            int i = left, j = right;
            int num1 = 0, num2 = 0;
            while (i<n && version1[i]!='.'){
                num1 += num1*1ll*10 + (version1[i]-'0');
                i++;
            }
            while (j<m && version2[j]!='.') {
                num2 += num2*1ll*10 + (version2[j]-'0');
                j++;
            }
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            left=i+1, right = j+1;  
        }
        while (left < n){
            int i = left;
            int num1 = 0;
            while (i<n && version1[i]!='.'){
                num1 += num1*1ll*10 + (version1[i]-'0');
                i++;
            }
            if (num1 > 0) return 1;
            else if (num1 < 0) return -1;
            left = i+1;
        }
        while (right < m){
            int j = right;
            int num2 = 0;
            while (j<m && version2[j]!='.') {
                num2 += num2*1ll*10 + (version2[j]-'0');
                j++;
            }
            if (num2 > 0) return -1;
            else if (num2 < 0) return 1;
            right = j+1;
        }

        return 0;

    }
};