class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        map<int, vector<int>> mp;
        for (int &it : arr){
            string str = to_string(it);
            for (int i=0; i<str.size(); i++){
                int no = str[i]-'0';
                str[i] = mapping[no]+'0';
            }
            int number = stoi(str);
            mp[number].push_back(it);
        }
        for (auto it : mp){
            for (auto ele: it.second){
                ans.push_back(ele);
            }
        }
        return ans;
    }
};