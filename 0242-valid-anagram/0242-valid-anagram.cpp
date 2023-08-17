class Solution {
public:
    bool isAnagram(string pattern, string str) {
        int n = pattern.size(), m = str.size();
       
        if (n!=m) return false;

        int freq[26]={0};

        for (int i=0; i<pattern.size(); i++){
            freq[pattern[i]-'a']++;
            freq[str[i]-'a']--;
        }
        
        for (int i=0; i<26; i++){
            if (freq[i] !=0) return false;
        }
        return true;

    }
};