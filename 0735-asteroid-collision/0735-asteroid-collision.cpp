class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int asteroid : asteroids){
            // COLLISSION
            while (!stk.empty() && stk.top() > 0 && asteroid < 0){
                int sum = asteroid + stk.top();
                if (sum > 0){
                    // DONT PUSH OR DONT POP
                    asteroid = 0;
                    break;
                }
                else if (sum == 0){
                    asteroid = 0;
                    stk.pop();
                }
                else if (sum < 0){
                    stk.pop();
                    // asteroid = 0;
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