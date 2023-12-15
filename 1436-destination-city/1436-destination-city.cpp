class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>> mp;
        for (int i=0; i<paths.size(); i++){
            string u = paths[i][0]; 
            string v = paths[i][1]; 
            mp[u].push_back(v);
        }
        for (auto it : mp){
            string pehla = it.first;
            string dusra = it.second[0];
            if (mp.find(dusra) == mp.end()){
                return dusra;
            }
        }
        return "";
    }
};