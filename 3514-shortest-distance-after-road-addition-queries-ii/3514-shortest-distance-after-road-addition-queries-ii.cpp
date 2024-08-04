class Solution {
public:
    void eraseNodes(int x, int y, set<int>& s){
        auto start = s.lower_bound(x);
        auto end = s.upper_bound(y);
        s.erase(start, end);
        return ;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        for (int i=0; i<n; i++){
            st.insert(i);
        }
        vector<int> ans;
        for (auto it : queries){
            int x = it[0], y = it[1];
            eraseNodes(x+1,y-1, st);
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};