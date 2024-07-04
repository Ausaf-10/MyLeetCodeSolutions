class cmp{
    public:
        bool operator()(pair<char,int> a, pair<char,int> b){
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;
        string ans;
        unordered_set<int> st;
        for (int i=0; i<s.size(); i++){
            char ch = s[i];
            if (ch == '*'){
                st.insert(i);
                auto node = pq.top(); pq.pop();
                int indx = node.second;
                st.insert(indx);
            }
            else{
                pq.push({s[i],i});
            }
        }
        for (int i=0; i<s.size(); i++){
            if (st.find(i) == st.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};