class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        for (int i=0; i<asteroids.size(); i++){
            int ele = asteroids[i];
            if (ele > 0){
                int j = i+1;
                while (j<asteroids.size() && asteroids[j]<=0){
                    int sum = ele + asteroids[j];
                    if (sum > 0){
                        asteroids[j] = 0;
                    }
                    else if (sum < 0){
                        asteroids[i] = 0;
                        break;
                    }
                    else{
                        asteroids[i] = 0;
                        asteroids[j] = 0;
                        break;
                    }
                    j++;
                }
            }
            else if (ele == 0){
                continue;
            }
            else{
                int j = i-1;
                while (j>= 0 && asteroids[j] >= 0){
                    int sum = ele + asteroids[j];
                    if (sum > 0){
                        asteroids[i] = 0;
                        break;
                    }
                    else if (sum < 0){
                        asteroids[j] = 0;
                    }
                    else{
                        asteroids[i] = 0;
                        asteroids[j] = 0;
                        break;
                    }
                    j--;
                }
                        
                    }

        }
        vector<int> ans;
        for (auto it : asteroids){
            if (it!=0) ans.push_back(it);
        }
        return ans;
    }
};