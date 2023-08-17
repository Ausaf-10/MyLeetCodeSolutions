class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        
        vector<int> freq(26,0);
        for (auto ch : s){
            freq[ch-'a']++;
        }

        priority_queue<pair<int,char>> pq;
        for (int i=0; i<26; i++){
            if (freq[i]!=0)
                pq.push({freq[i],i+'a'});
        }
        string ans="";
        
        auto block = pq.top(); pq.pop();
        ans.push_back(block.second);

        while (!pq.empty()){
            auto node = pq.top();
            pq.pop();
            ans.push_back(node.second);

            block.first--;
            if (block.first != 0) pq.push(block);

            block = node;

        }
        
        return ans.size()==n ? ans : "";
    }
};