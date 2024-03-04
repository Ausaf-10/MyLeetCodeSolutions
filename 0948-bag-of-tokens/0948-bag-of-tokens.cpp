class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if (tokens.size() == 0) return 0;
        sort(tokens.begin(), tokens.end());
        if (tokens[0] > power) return 0;
        int i = 0, j = tokens.size()-1, maxi = -1e9;
        int score = 0;
        while (i<=j){
            if (tokens[i] <= power){
                power -= tokens[i];
                score++;
                maxi = max(maxi, score);
                i++;
            }
            else{
                if (i!=j){
                    if (score > 0){
                        score-=1; 
                        power+=tokens[j];
                        j--;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if (power >= tokens[j]){
                        score++;
                        power-=tokens[j];
                        j--;
                    }
                    else{
                        j--;
                    }
                }
            }
            maxi = max(maxi, score);
        }
        return maxi;
    }
};