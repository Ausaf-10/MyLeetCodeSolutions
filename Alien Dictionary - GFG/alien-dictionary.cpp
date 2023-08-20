//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        for (int i=0; i<V; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i=0; i<V; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
       
        while (!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for (auto it : adj[node]){
                if (indegree[it]!=0){
                    indegree[it]--;
                    if (indegree[it] == 0)  q.push(it);
                }    
            }
        }
        
        return topo;
    }
    string findOrder(string dict[], int N, int K) {
        // //code here
        // set<string> st;
        // for (int i=0; i<N; i++){
        //     st.insert(dict[i]);
        // }
        
        vector<int> adj[K];
        // CREATING AN ADJACENCY LIST -> DIRECTED GRAPH
        for (int i=0; i<N-1; i++){
            string str1 = dict[i];
            string str2 = dict[i+1];
            int len = min(str1.size(), str2.size());
            for (int ptr = 0; ptr<len; ptr++){
                if (str1[ptr]!=str2[ptr]){
                    adj[str1[ptr]-'a'].push_back(str2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> order = topoSort(K, adj);
       
        string ans ="";
        for (auto it : order){
            ans+=it+'a';
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends