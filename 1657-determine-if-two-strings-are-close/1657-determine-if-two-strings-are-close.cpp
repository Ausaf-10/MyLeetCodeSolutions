class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        unordered_map<char,int> mp1, mp2;

        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq1;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq2;

        for (auto it : word1){
            mp1[it]++;

        }
        
        for (auto it : word2) mp2[it]++;

        for (auto it : mp1){
            // CHECKING WHETHER THE ALPHABETS ARE SAME OR NOT 
            if (mp2.find(it.first) == mp2.end()) return false;
        }

        for (auto it : mp1){
            pq1.push({it.second,it.first});
        }
        
        for (auto it : mp2){
            pq2.push({it.second,it.first});
        }

        while (!pq1.empty()){
            int freq1 = pq1.top().first,  freq2 = pq2.top().first;
            pq1.pop();
            pq2.pop();
            if (freq1 != freq2) return false;
        }
        
        return true;
    }
};