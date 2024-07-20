class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;

        if (a) pq.push({a, 'a'});
        if (b) pq.push({b, 'b'});
        if (c) pq.push({c, 'c'});
        
        string ans;
        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            if (ans.size() > 1 && node.second == ans[ans.size()-1] && node.second == ans[ans.size()-2]){
                if (pq.empty()) break;
                else{
                    auto it = pq.top(); pq.pop();
                    ans.push_back(it.second);
                    it.first--;
                    if (it.first > 0) pq.push(it);
                }
            }
            else{
                ans.push_back(node.second);
                node.first--;
            }
            if (node.first > 0) pq.push(node);

        }
        return ans;
    }
};