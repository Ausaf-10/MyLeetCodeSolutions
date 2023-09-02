// EK GRAPH KA QUESTION HAI KAAFI SAHI COZ HUM  KYA KR RHE HAIN THAT AGAR A/B HAI TOH MATLAB A SE JAB B PE JAYENGE TABH 2 MILEGA AND JAB B SE A 
// PE JAYENGE TO 1/2 MILEGA AND ISS REASON KI WAJAH SE HUM KEH RHE HAIN KI YEH EK GRAPH PROBLEM HAI!!
// A->B , EDGEWEIGHT 2 , B->A EDGEWEIGHT 1/2 
// CHECK KR LO KI AAPKI QUERY MEIN NUMERATOR AND DENOMINATOR BOTH ARE PRESENT IN UR MAP AND BOTH OF THEM SHOULD NOT BE EQUAL 
// WE CAN CONSIDER THE NUMERATOR AS THE SOURCE AND THE DENOMINATOR AS THE DESTINATOIN AND BOTH THE SRC AND DEST MUST NOT BE EQUAL
// SOURCE SE DESTINATION TAK JAISE JAOGE WAISE EDGEWEIGHTS KO MULTIPLY KRTE CHALNA AND U WILL EVENTUALL GET UR ANSWER!!!!!

class Solution {
public:
    void dfs(string& src, string& dest, unordered_set<string> &visited, unordered_map<string, vector<pair<string,double>>> &mp, double prod,double& ans){
        
        visited.insert(src); 
        if (dest == src){
            ans = prod;
            return ;
        }
        
        for (auto it : mp[src]){
            string temp = it.first;
            double tempValue = it.second;
            if (visited.find(temp) == visited.end()){
                dfs(temp, dest, visited, mp, prod*tempValue, ans);
            }
        }
        
        return ;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    // 1. CREATE A GRAPH, BUT THIS TIME WE ARE GOING TO CREATE A GRAPH USING A MAP
        int n = equations.size();

        unordered_map<string, vector<pair<string,double>>> mp;
        for (int i=0; i<n; i++){
            string u = equations[i][0], v = equations[i][1];
            double value = values[i];

            mp[u].push_back({v,value});
            mp[v].push_back({u,double(1.0/value)});
        }

        vector<double> answer;

        for (auto it : queries){
            string src = it[0], dest = it[1];
            if (mp.find(src) != mp.end() && mp.find(dest) != mp.end()){
                // har ek query ke liye alag visited data struct treat krna padega bcoz agar koi visit hogya toh woh next query ke liye toh 
                // univisted hi rahega na!!
                double ans = -1;
                double prod = 1;
                unordered_set<string> visited;  
                dfs(src,dest,visited,mp, prod, ans);
                answer.push_back(ans);
            }
            else{
                answer.push_back(-1.0);
            }
        }

        return answer;

    }
};