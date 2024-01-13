class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp1, mp2;
        
        for (auto it : s) mp1[it]++;
        for (auto it : t) mp2[it]++;
        
        int cnt = 0;
        
        for (auto it : mp1){
            if (mp2.find(it.first) != mp2.end()){
                if (mp1[it.first] == mp2[it.first]){
                    cnt+=mp1[it.first];
                }
                else cnt+=min(mp1[it.first],mp2[it.first]);
                
            }
        }

        return int(s.size()) - cnt;
        
    }
};