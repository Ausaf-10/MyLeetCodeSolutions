class Solution {
public:
    bool hasDuplicate(string& s1, string& s2){
        unordered_set<char> st;
        for (auto it : s1){
            if (st.find(it) != st.end()) return true;
            else st.insert(it);
        }
        for (auto it : s2){
            if (st.find(it) != st.end()) return true;
        }
        return false;
    }
    int fun(vector<string>& str, int indx, string ds){
        if (indx == (int)str.size()){
            return ds.size();
        }
       
        int notPick = 0, pick = 0;
        if (hasDuplicate(str[indx], ds)){
            notPick = fun(str, indx + 1, ds);
        }
        else{
            pick = fun(str, indx + 1, ds + str[indx]);
            notPick = fun(str, indx + 1, ds);
        }
        
        
        return max(pick, notPick);
    }
    int maxLength(vector<string>& str) {
        string ds;
        return fun(str, 0, ds);
    }
};