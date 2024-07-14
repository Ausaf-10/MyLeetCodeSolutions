class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int, int> healthMap, positionMap;
        unordered_map<int, char> dirMap;
        for (int i=0; i<positions.size(); i++){
            healthMap[positions[i]] = healths[i]; 
            dirMap[positions[i]] = directions[i]; 
            positionMap[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());
        stack<int> stk;
        for (auto position : positions){
            while (!stk.empty() && dirMap[stk.top()] == 'R' && dirMap[position] == 'L'){
                int dif = healthMap[stk.top()] - healthMap[position];
                if (dif == 0){
                    stk.pop();
                    position = 0;
                    break;
                } 
                else if (dif > 0){
                    position = 0;
                    healthMap[stk.top()]--;
                    break;
                }
                else{
                    healthMap[position]--;
                    stk.pop();
                }
            }
            if (position) stk.push(position);
        }
        vector<vector<int>> ans;
        vector<int> res;
        while (!stk.empty()){
            int position = stk.top(); stk.pop();
            ans.push_back({positionMap[position], healthMap[position]});
        }
        sort(ans.begin(), ans.end());
        for (auto it : ans){
            res.push_back(it[1]);
        }
        return res;
    }
};