class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int asteroid : asteroids){
            // COLLISSION
            while (!stk.empty() && stk.top() > 0 && asteroid < 0){
                int sum = asteroid + stk.top();
                if (sum > 0){
                    asteroid = 0;
                    break;
                }
                else if (sum == 0){
                    asteroid = 0;
                    stk.pop();
                    break;
                }
                else if (sum < 0){
                    stk.pop();
                }
            }
            if (asteroid != 0) stk.push(asteroid);
            
        }
        
        if (stk.empty()) return {};
        vector<int> ans;
        while (!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};