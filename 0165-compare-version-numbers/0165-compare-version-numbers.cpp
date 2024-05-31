class Solution {
public:
    int n,m;
    int compareVersion(string version1, string version2) {
        int left = 0, right = 0, n = version1.size(), m = version2.size();
        while (left<n && right<m){
            int i = left, j = right;
            while (i<n && version1[i]!='.') i++;
            while (j<m && version2[j]!='.') j++;
            string s1 = version1.substr(left, i-left); 
            string s2 = version2.substr(right, j-right);
            int num1 = stoi(s1), num2 = stoi(s2);
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            left=i+1, right = j+1;  
        }
        while (left < n){
            int i = left;
            while (i<n && version1[i]!='.') i++;
            string s1 = version1.substr(left, i-left);
            int num1 = stoi(s1);
            if (num1 > 0) return 1;
            else if (num1 < 0) return -1;
            left = i+1;
        }
        while (right < m){
            int j = right;
            while (j<m && version2[j]!='.') j++;
            string s2 = version2.substr(right, j-right);
            int num2 = stoi(s2);
            if (num2 > 0) return -1;
            else if (num2 < 0) return 1;
            right = j+1;
        }

        return 0;

    }
};