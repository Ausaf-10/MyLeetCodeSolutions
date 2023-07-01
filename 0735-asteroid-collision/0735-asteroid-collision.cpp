class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> ans;
        int n = asteroids.size();
        for (int i=0; i<n; i++){
            int element = asteroids[i];
            while (!stk.empty() && stk.top() > 0 && element < 0){
                int sum = element + stk.top();
                if (sum > 0){
                    element = 0;
                }
                else if (sum < 0 ){
                    stk.pop();
                }
                else {
                    stk.pop();
                    element = 0;
                }
            }
            if (element!=0) stk.push(element);
            
        }
        if (stk.empty()) return ans;

        while (!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};