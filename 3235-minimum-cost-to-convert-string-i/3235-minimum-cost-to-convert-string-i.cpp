using ll = long long int;
typedef pair<ll, char> pi;
class Solution {
public:
    void floydWarshall(vector<vector<ll>>& costMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
        
        for (int k=0; k<26; k++){
            for (int i=0; i<26; i++){
                for (int j=0; j<26; j++){
                    if (costMatrix[i][k] == 1e15 || costMatrix[k][j] == 1e15) continue;
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                }
            }
        }
        
        return ;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>> costMatrix(26, vector<ll>(26, 1e15));
        
        for (int i=0; i<26; i++) costMatrix[i][i] = 0;
        for (int i=0; i<original.size(); i++){
            char u = original[i], v = changed[i];
            int wt = cost[i];
            costMatrix[u-'a'][v-'a'] = min(costMatrix[u-'a'][v-'a'], (ll)wt);
        }

        floydWarshall(costMatrix, original, changed, cost);

        long long ans = 0;
        for (int i=0; i<source.size(); i++){
            if (source[i] == target[i]) continue; 
            char u = source[i], v = target[i];
            if (costMatrix[u-'a'][v-'a'] == 1e15) return -1;
            ans = ans + costMatrix[u-'a'][v-'a'];
        }
        return ans;
    }
};